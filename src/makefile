CC=g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
OBJ=Range.o Term.o Test.o
EXE=main

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o

mrproper:
	rm $(EXE)
	rm *.o
