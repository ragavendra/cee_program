CC = gcc
CFLAGS = -I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.c hellofunc.c
	$(CC) -o hellomake hellomake.c hellofunc.c -T.
