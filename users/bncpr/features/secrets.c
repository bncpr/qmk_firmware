#include "bncpr.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SECRET_0_MACRO ... SECRET_N_MACRO:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                // Secrets!  Externally defined strings, not stored in repo
                send_string_with_delay(secrets[keycode - SECRET_0_MACRO], SECRET_MACRO_DELAY);
            }
            return false;
            break;
    }
    return true;
}
#endif
