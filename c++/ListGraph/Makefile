IDIR1 = dep
IDIR2 = util
ODIR  = bin
SDIR  = src
CC    = g++
FLAGS = -g -Wall -I $(IDIR1) -I $(IDIR2) 

main: $(ODIR)/main.o $(ODIR)/City.o
	$(CC) $(FLAGS) $^ -o $(ODIR)/$@

$(ODIR)/main.o: $(SDIR)/main.cpp 
	$(CC) $(FLAGS) -c $< -o $@

$(ODIR)/City.o: $(IDIR2)/City.cpp $(IDIR2)/City.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm main *.o

