CC = gcc
LD = $(CC)

LUA52 ?= no

EXT = so
FPIC = -fPIC

CFLAGS = -std=c99
ifeq ($(LUA52),no)
	INC := $(shell pkg-config --cflags lua5.1)
else
	INC := $(shell pkg-config --cflags lua5.2)
endif

all: htime.$(EXT)

htime.$(EXT): htime.c
	@echo "Compiling $@..."
	@$(CC) $(FPIC) $(CFLAGS) $(INC) --shared -o $@ $^

clean:
	@rm -f htime.$(EXT)
