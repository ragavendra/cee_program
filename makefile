CC = gcc
CFLAGS = -I.
DEPS = hellomake.h

hellomake: hellomake.c hellofunc.c
	$(CC) -o hellomake hellomake.c hellofunc.c $(CFLAGS)
