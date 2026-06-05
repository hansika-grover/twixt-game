CC       ?= gcc
CFLAGS   ?= -Wall -Wextra -std=c11 -O2
CPPFLAGS  = -MMD -MP          # auto-generate header-dependency files
TARGET    = twixt
PREFIX   ?= /usr/local

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

install: $(TARGET)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 $(TARGET) $(DESTDIR)$(PREFIX)/bin/$(TARGET)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: all run install clean

-include $(DEPS)