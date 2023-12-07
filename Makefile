CC= gcc
RM= rm -f

CFLAGS= -Wall -Wextra -pedantic -std=c11 -ggdb # -Werror
LIBS= -lm

all: day_1 day_2

.PHONY: day_1
day_1: day_1.c
	$(CC) $(CFLAGS) -o day_1 day_1.c $(LIBS)
	./day_1 < day_1.txt

.PHONY: day_2
day_2: day_2.c
	$(CC) $(CFLAGS) -o day_2 day_2.c $(LIBS)
	./day_2 < day_2.txt

.PHONY: echo
echo:
	@echo "CC = $(CC)"
	@echo "RM = $(RM)"
	@echo "CFLAGS = $(CFLAGS)"
	@echo "LIBS = $(LIBS)"