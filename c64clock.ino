#include "config.h"

#include <WiFi.h>
#include "time.h"

bool irq = false;

typedef struct {
    lv_obj_t *hour;
    lv_obj_t *minute;
    lv_obj_t *data;
    lv_obj_t *percent;
    lv_obj_t *bkk;
} str_datetime_t;

static str_datetime_t g_data;

TTGOClass *watch = nullptr;
PCF8563_Class *rtc;

LV_FONT_DECLARE(c64);
LV_FONT_DECLARE(c64half);
LV_FONT_DECLARE(c64tiny);

const char *ssid = SSID;
const char *password = SECRET;

const char *ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

const lv_color_t txtcolor = LV_COLOR_MAKE(255,255,255);
const lv_color_t bgcolor = LV_COLOR_MAKE(62,50,162);

int p;

void sleep(){
            
        watch->power->clearIRQ();
        watch->displaySleep();
        watch->powerOff();
        
        watch->power->setPowerOutPut(AXP202_LDO3, false);
        watch->power->setPowerOutPut(AXP202_LDO4, false);
        watch->power->setPowerOutPut(AXP202_LDO2, false);
        watch->power->setPowerOutPut(AXP202_EXTEN, false);
        watch->power->setPowerOutPut(AXP202_DCDC2, false);

        esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);
        esp_deep_sleep_start();
}

void setup()
{
    Serial.begin(115200);
        
    watch = TTGOClass::getWatch();
    watch->begin();
    watch->lvgl_begin();
    watch->openBL();
    watch->displayWakeup();

    rtc = watch->rtc;
    rtc->check();

    pinMode(AXP202_INT, INPUT_PULLUP);
    attachInterrupt(AXP202_INT, [] {
        irq = true;
    }, FALLING);

    watch->power->enableIRQ(AXP202_PEK_SHORTPRESS_IRQ | AXP202_VBUS_CONNECT_IRQ , true);
    watch->power->clearIRQ();
    watch->power->adc1Enable(AXP202_VBUS_VOL_ADC1 | AXP202_VBUS_CUR_ADC1 | AXP202_BATT_CUR_ADC1 | AXP202_BATT_VOL_ADC1, true);
    p = watch->power->getBattPercentage();

    static lv_style_t Font;
    lv_style_init(&Font);
    lv_style_set_text_color(&Font, LV_STATE_DEFAULT, txtcolor);
    lv_style_set_text_font(&Font, LV_STATE_DEFAULT, &c64);
    
    static lv_style_t FontHalf;
    lv_style_init(&FontHalf);
    lv_style_set_text_color(&FontHalf, LV_STATE_DEFAULT, txtcolor);
    lv_style_set_text_font(&FontHalf, LV_STATE_DEFAULT, &c64half);

    static lv_style_t FontTiny;
    lv_style_init(&FontTiny);
    lv_style_set_text_color(&FontTiny, LV_STATE_DEFAULT, txtcolor);
    lv_style_set_text_font(&FontTiny, LV_STATE_DEFAULT, &c64tiny);

    static lv_style_t Background;
    lv_style_init(&Background);
    lv_style_set_bg_color(&Background, LV_STATE_DEFAULT, bgcolor );

    lv_obj_t * background;
    background = lv_obj_create(lv_scr_act(), NULL);
    lv_obj_set_size(background, 244, 244);
    lv_obj_add_style(background, LV_OBJ_PART_MAIN, &Background);
    lv_obj_align(background, NULL, LV_ALIGN_CENTER, -1, -1);

    lv_obj_t *boot = lv_label_create(background, nullptr);
    lv_obj_add_style(boot, LV_OBJ_PART_MAIN, &FontTiny);
    lv_label_set_text(boot, "   **** COMMODORE 64 BASIC V2 ****\n\n64K RAM SYSTEM 38911 BASIC BYTES FREE");
    lv_obj_align(boot, background, LV_ALIGN_CENTER, 0, -100);

    lv_obj_t *points = lv_label_create(background, nullptr);
    lv_obj_add_style(points, LV_OBJ_PART_MAIN, &Font);
    lv_label_set_text(points, ":");
    lv_obj_align(points, background, LV_ALIGN_CENTER, -1, -20);
   
    g_data.hour = lv_label_create(background, nullptr);
    lv_obj_add_style(g_data.hour, LV_OBJ_PART_MAIN, &Font);
    lv_label_set_text(g_data.hour, "00");
    lv_obj_align(g_data.hour, points, LV_ALIGN_OUT_LEFT_MID, 10, 0);

    g_data.minute = lv_label_create(background, nullptr);
    lv_obj_add_style(g_data.minute, LV_OBJ_PART_MAIN, &Font);
    lv_label_set_text(g_data.minute, "00");
    lv_obj_align(g_data.minute, points, LV_ALIGN_OUT_RIGHT_MID, -10, 0);

    g_data.data = lv_label_create(background, nullptr);
    lv_obj_add_style(g_data.data, LV_OBJ_PART_MAIN, &FontHalf);
    lv_label_set_text(g_data.data, "00.00.0000");
    lv_obj_align(g_data.data, g_data.hour, LV_ALIGN_IN_LEFT_MID, 0, 40);

    g_data.percent = lv_label_create(background, nullptr);
    lv_obj_add_style(g_data.percent, LV_OBJ_PART_MAIN, &FontHalf);
    lv_label_set_text(g_data.percent, "00%");
    lv_obj_align(g_data.percent, g_data.data, LV_ALIGN_OUT_BOTTOM_RIGHT , -1, 10);

    g_data.bkk = lv_label_create(background, nullptr);
    lv_obj_add_style(g_data.bkk, LV_OBJ_PART_MAIN, &FontHalf);
    lv_label_set_text(g_data.bkk, "00:00");
    lv_obj_align(g_data.bkk, g_data.data, LV_ALIGN_OUT_BOTTOM_LEFT , 0, 10);
 
    lv_task_create([](lv_task_t *t) {
        RTC_Date curr_datetime = rtc->getDateTime();

        int i = curr_datetime.hour + 6;
        if(i > 23){
          i = i - 23;
        }
        
        lv_label_set_text_fmt(g_data.minute, "%02u", curr_datetime.minute);
        lv_label_set_text_fmt(g_data.hour, "%02u", curr_datetime.hour);
        lv_label_set_text_fmt(g_data.bkk, "%02u:%02u", i, curr_datetime.minute);
        lv_label_set_text_fmt(g_data.data, "%02u.%02u.%04u", curr_datetime.day, curr_datetime.month, curr_datetime.year);
        lv_label_set_text_fmt(g_data.percent, "%02u%%", p);
        
    }, 1000, LV_TASK_PRIO_LOW, nullptr);

    lv_task_create([](lv_task_t *t) {
       watch->displaySleep();
       watch->closeBL();
    }, 10000, LV_TASK_PRIO_LOWEST, nullptr);

    lv_task_t * lowenergy = lv_task_create([](lv_task_t *t) {
       sleep();
    }, 60*60*1000, LV_TASK_PRIO_LOWEST, nullptr);
    lv_task_once(lowenergy);

    int i=0;
    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        i++;
        if(i > 10){
          Serial.print("WiFi failed!");
          break;
        }
    }
    
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    struct tm timeinfo;
    if (getLocalTime(&timeinfo)) {
       Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
       Serial.println("Time synchronization succeeded");
       rtc->syncToRtc();
    }
   
    WiFi.disconnect();
   
    setCpuFrequencyMhz(20);

}

void loop()
{    
    lv_task_handler();

    int16_t x, y;
    if (watch->getTouch(x, y)) {
        p = watch->power->getBattPercentage();
        watch->openBL();
        watch->displayWakeup();
    }
    
    if (irq) {
        irq = false;
        watch->power->readIRQ();
        if (watch->power->isVbusPlugInIRQ()) {
            watch->openBL();
            watch->displayWakeup();
            watch->motor_begin();
            watch->motor->onec();
            delay(200);
        }
        if (watch->power->isPEKShortPressIRQ()) {
           p = watch->power->getBattPercentage();
           watch->openBL();
           watch->displayWakeup();
        }
        watch->power->clearIRQ();
    }
        
    delay(5);

}
