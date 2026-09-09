CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
LDFLAGS = -lcriterion

all: src/tinyprintf.o 

src/tinyprintf.o: src/tinyprintf.c src/tinyprintf.h 
	$(CC) $(CFLAGS) -c src/tinyprintf.c -o src/tinyprintf.o 

check: src/tinyprintf.o
	$(CC) $(CFLAGS) -o test src/tinyprintf.c tests/test_tinyprintf.c $(LDFLAGS)
	./test

clean: 
	rm -f src/tinyprintf.o test

