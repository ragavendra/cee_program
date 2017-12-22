IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = ../lib

#incl macro libs mathlib
LIBS = -lm

#patsub replace whitespace txt
_DEPS = hellomake.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

# make obj files, $@ means before : and $< means first item after :
%(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# $^ means all files after :
hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
