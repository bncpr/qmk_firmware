SRC += bncpr.c

ifdef OLED_SUGAR
	SRC += oled_sugar/oled_sugar.c
endif


ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

SRC += features/secrets.c
SRC += features/select_word.c
SRC += features/alternate_case.c
