#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 6 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifndef C64TINY
#define C64TINY 1
#endif

#if C64TINY

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */

    /* U+23 "#" */
    0x75, 0xd7, 0x5d, 0xff, 0xff, 0xff, 0x75, 0xd7,
    0x5d,

    /* U+2A "*" */
    0x35, 0xc2, 0xf8, 0xff, 0xf3, 0xac,

    /* U+2E "." */
    0x5f,

    /* U+30 "0" */
    0x2f, 0x87, 0x5d, 0x77, 0xd7, 0xdd, 0x75, 0xd2,
    0xf8,

    /* U+31 "1" */
    0xf, 0x0, 0xf0, 0x1f, 0x0, 0xf0, 0xf, 0x3,
    0xfc,

    /* U+32 "2" */
    0x2f, 0x83, 0x1d, 0x1, 0xc1, 0xf4, 0x34, 0x7,
    0xfc,

    /* U+33 "3" */
    0x2f, 0x83, 0x1d, 0x1, 0xc0, 0xbc, 0x31, 0xc2,
    0xf8,

    /* U+34 "4" */
    0x1, 0xd0, 0x3d, 0x2f, 0xd3, 0xff, 0x1, 0xd0,
    0x1d,

    /* U+35 "5" */
    0x7f, 0xc7, 0x40, 0x3f, 0xc0, 0x1d, 0x31, 0xc2,
    0xf8,

    /* U+36 "6" */
    0x2f, 0x87, 0x4c, 0x74, 0x7, 0x5c, 0x75, 0xd2,
    0xf8,

    /* U+37 "7" */
    0x7f, 0xd2, 0x1c, 0x3, 0x40, 0xf0, 0xf, 0x0,
    0xf0,

    /* U+38 "8" */
    0x2f, 0x87, 0x5d, 0x35, 0xc3, 0x5c, 0x75, 0xd2,
    0xf8,

    /* U+39 "9" */
    0x2f, 0x87, 0x5d, 0x35, 0xd1, 0xfd, 0x31, 0xc2,
    0xf8,

    /* U+3A ":" */
    0xa0, 0xa0,

    /* U+41 "A" */
    0xf, 0x2, 0xa8, 0x75, 0xd7, 0xfd, 0x75, 0xd7,
    0x5d,

    /* U+42 "B" */
    0x7f, 0x87, 0x5d, 0x75, 0xc7, 0x5c, 0x75, 0xd7,
    0xf8,

    /* U+43 "C" */
    0x2f, 0x87, 0x4c, 0x74, 0x7, 0x40, 0x34, 0xc2,
    0xf8,

    /* U+44 "D" */
    0x7f, 0x7, 0x68, 0x75, 0xd7, 0x5d, 0x76, 0x87,
    0xf0,

    /* U+45 "E" */
    0x7f, 0xc7, 0x40, 0x74, 0x7, 0xe0, 0x74, 0x7,
    0xfc,

    /* U+46 "F" */
    0x7f, 0xc7, 0x40, 0x74, 0x7, 0xe0, 0x74, 0x7,
    0x40,

    /* U+47 "G" */
    0x2f, 0x87, 0x4c, 0x74, 0x7, 0x7c, 0x75, 0xd2,
    0xf8,

    /* U+48 "H" */
    0x75, 0xd7, 0x5d, 0x75, 0xd7, 0xfd, 0x75, 0xd7,
    0x5d,

    /* U+49 "I" */
    0x7d, 0x3c, 0x3c, 0x3c, 0x3c, 0x7d,

    /* U+4A "J" */
    0xb, 0xc0, 0x38, 0x3, 0x80, 0x38, 0x33, 0x42,
    0xf0,

    /* U+4B "K" */
    0x75, 0xc7, 0x74, 0x7d, 0x7, 0xd0, 0x7b, 0x47,
    0x5c,

    /* U+4C "L" */
    0x74, 0x7, 0x40, 0x74, 0x7, 0x40, 0x74, 0x7,
    0xfc,

    /* U+4D "M" */
    0x74, 0xb7, 0xdf, 0x7b, 0xf7, 0x5b, 0x74, 0xb7,
    0x4b,

    /* U+4E "N" */
    0x75, 0xd7, 0xdd, 0x7f, 0xd7, 0xbd, 0x76, 0xd7,
    0x5d,

    /* U+4F "O" */
    0x2f, 0x87, 0x5d, 0x75, 0xd7, 0x5d, 0x75, 0xd2,
    0xf8,

    /* U+50 "P" */
    0x7f, 0x87, 0x5d, 0x75, 0xc7, 0xf4, 0x74, 0x7,
    0x40,

    /* U+51 "Q" */
    0x2f, 0x87, 0x5d, 0x75, 0xd7, 0x5d, 0x2f, 0x80,
    0x3c,

    /* U+52 "R" */
    0x7f, 0x87, 0x5d, 0x75, 0xc7, 0xf4, 0x7b, 0x47,
    0x5c,

    /* U+53 "S" */
    0x2f, 0x87, 0x4c, 0x34, 0x1, 0xfc, 0x31, 0xc2,
    0xf8,

    /* U+54 "T" */
    0x3f, 0xc0, 0xf0, 0xf, 0x0, 0xf0, 0xf, 0x0,
    0xf0,

    /* U+55 "U" */
    0x75, 0xd7, 0x5d, 0x75, 0xd7, 0x5d, 0x35, 0xc2,
    0xf8,

    /* U+56 "V" */
    0x75, 0xd7, 0x5d, 0x75, 0xd7, 0x5d, 0x1a, 0x40,
    0xf0,

    /* U+57 "W" */
    0x74, 0xb7, 0x4b, 0x74, 0xb7, 0xbf, 0x7e, 0xf7,
    0x4b,

    /* U+58 "X" */
    0x75, 0xd3, 0x5c, 0xf, 0x0, 0xf0, 0x3a, 0xc7,
    0x5d,

    /* U+59 "Y" */
    0x75, 0xd7, 0x5d, 0x25, 0x80, 0xf0, 0xf, 0x0,
    0xf0,

    /* U+5A "Z" */
    0x3f, 0xd0, 0x1c, 0x3, 0x80, 0xd0, 0x38, 0x7,
    0xfc,

    /* U+61 "a" */
    0x1f, 0x81, 0xfd, 0x35, 0xd2, 0xfd,

    /* U+62 "b" */
    0x74, 0x7, 0x40, 0x75, 0xc7, 0x5d, 0x7f, 0x80,

    /* U+63 "c" */
    0x2f, 0x5d, 0x7, 0x40, 0xbd,

    /* U+64 "d" */
    0x1, 0xd0, 0x1d, 0x35, 0xd7, 0x5d, 0x2f, 0xd0,

    /* U+65 "e" */
    0x2f, 0x87, 0xfc, 0x74, 0x2, 0xf4,

    /* U+66 "f" */
    0xf, 0xf, 0x7, 0xf0, 0xf0, 0x3c, 0x0,

    /* U+67 "g" */
    0x2f, 0xd7, 0x5d, 0x35, 0xd1, 0xfd, 0x3f, 0x80,

    /* U+68 "h" */
    0x74, 0x7, 0x40, 0x7a, 0x87, 0x5d, 0x75, 0xd0,

    /* U+69 "i" */
    0x28, 0x0, 0x78, 0x3c, 0x7d,

    /* U+6A "j" */
    0x3, 0x0, 0x0, 0x74, 0x1d, 0x7, 0x5f, 0x80,

    /* U+6B "k" */
    0x74, 0x7, 0x40, 0x7f, 0x47, 0x74, 0x75, 0xc0,

    /* U+6C "l" */
    0x7c, 0x3c, 0x3c, 0x3c, 0x7d,

    /* U+6D "m" */
    0x75, 0xd7, 0xff, 0x7b, 0xb7, 0x4b,

    /* U+6E "n" */
    0x7f, 0x87, 0x5d, 0x75, 0xd7, 0x5d,

    /* U+6F "o" */
    0x2f, 0x87, 0x5d, 0x75, 0xd2, 0xf8,

    /* U+70 "p" */
    0x7f, 0x87, 0x5d, 0x75, 0xc7, 0xf4, 0x74, 0x0,

    /* U+71 "q" */
    0x2f, 0xd7, 0x5d, 0x35, 0xd1, 0xfd, 0x1, 0xd0,

    /* U+72 "r" */
    0x7f, 0x87, 0x4c, 0x74, 0x7, 0x40,

    /* U+73 "s" */
    0x2f, 0xc3, 0xf4, 0x1, 0xc3, 0xf8,

    /* U+74 "t" */
    0xf, 0x3, 0xfc, 0xf, 0x0, 0xf0, 0x3, 0xc0,

    /* U+75 "u" */
    0x75, 0xd7, 0x5d, 0x75, 0xd2, 0xfd,

    /* U+76 "v" */
    0x75, 0xd7, 0x5d, 0x2a, 0x80, 0xf0,

    /* U+77 "w" */
    0x74, 0xb7, 0xbb, 0x2f, 0xe2, 0xed,

    /* U+78 "x" */
    0x35, 0xc1, 0xf4, 0x1f, 0x43, 0x5c,

    /* U+79 "y" */
    0x75, 0xd7, 0x5d, 0x25, 0xd1, 0xfc, 0x3f, 0x0,

    /* U+7A "z" */
    0x3f, 0xc0, 0x74, 0x1d, 0x3, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 15, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 96, .box_w = 2, .box_h = 3, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 108, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 171, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 96, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 387, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 96, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 408, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 96, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 447, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 455, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 487, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 507, .adv_w = 96, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x3, 0xa, 0xe
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 15, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 48, .range_length = 11, .glyph_id_start = 5,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 16,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 42,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t c64tiny = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 7,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if C64TINY*/

