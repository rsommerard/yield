CC	= gcc
CFLAGS	= -Wall -Werror -pedantic -m32
OBJS	= main.o yield.o hw.o start_schedule.o
EXEC	= main

all: $(EXEC)

main: $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.c
tw.o: tw.c tw.h
start_schedule.o: start_schedule.c start_schedule.h
yield.o: yield.c yield.h

.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC) *~
