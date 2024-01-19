SRC += bncpr.c

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

ifdef OLED_ENABLE
	SRC += features/oled.c
endif

SRC += features/secrets.c
SRC += features/select_word.c
SRC += features/alternate_case.c
