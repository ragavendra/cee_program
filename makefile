CC = gcc
CFLAGS = -I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

# make obj files, $@ means before : and $< means first item after :
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# $^ means all files after :
hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
