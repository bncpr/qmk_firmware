SRC += bncpr.c

ifdef OLED_SUGAR
	SRC += oled_sugar/oled_sugar.c
endif

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif
