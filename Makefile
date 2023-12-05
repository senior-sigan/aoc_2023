CC= gcc
RM= rm -f

CFLAGS= -Wall -Wextra -Werror -pedantic -std=c11 -ggdb
LIBS= -lm

all: day_1

.PHONY: day_1
day_1: day_1.c
	$(CC) $(CFLAGS) -o day_1 day_1.c $(LIBS)
	./day_1 < day_1.txt

.PHONY: echo
echo:
	@echo "CC = $(CC)"
	@echo "RM = $(RM)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "LIBS = $(LIBS)"