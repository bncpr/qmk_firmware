#pragma once

#include "quantum.h"

bool process_alternate_case(uint16_t keycode, keyrecord_t *record, uint16_t altcase_keycode);

#define ALTERNATE_CASE_TIMEOUT 3000

#ifdef ALTERNATE_CASE_TIMEOUT
void alternate_case_task(void);
#endif // ALTERNATE_CASE_TIMEOUT
