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

// #define MASTER_LEFT
#define EE_HANDS
#define SOFT_SERIAL_PIN D2
#define USE_SERIAL
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

#define DIODE_DIRECTION ROW2COL

#define MATRIX_ROW_PINS \
    { F4, F5, F6, B5 }

// wiring of each half
#define MATRIX_COL_PINS \
    { B4, E6, D7, C6, D4, D3 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define OLED_FONT_H "keyboards/askew/glcdfont.c"
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_KEY_CNTR
