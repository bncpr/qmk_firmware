// Copyright 2023 Ben Cooper (@bncpr)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT

#define MASTER_LEFT
/* #define EE_HANDS */
#define SPLIT_USB_DETECT
/* #define SPLIT_USB_TIMEOUT 2000 */
#define SOFT_SERIAL_PIN GP1

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

#define DIODE_DIRECTION ROW2COL

#define MATRIX_ROW_PINS \
    { GP29, GP28, GP27, GP9 }

// wiring of each half
#define MATRIX_COL_PINS \
    { GP8, GP7, GP6, GP5, GP4, GP0 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define OLED_FONT_H "keyboards/askew/glcdfont.c"

#define SERIAL_DEBUG
