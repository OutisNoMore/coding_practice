FLAGS = -g -Wall
LIBS  = -lncurses
CC    = g++

Sudoku.bin: src/main.o dep/screen.o
	$(CC) -o $@ $^ $(FLAGS) $(LIBS)

main.o: src/main.cpp dep/screen.h
	$(CC) -c $< $(FLAGS) $(LIBS)

screen.o: dep/screen.cpp dep/screen.h
	$(CC) -c $< $(FLAGS) $(LIBS)

clean:
	rm dep/screen.o src/main.o Sudoku.bin
