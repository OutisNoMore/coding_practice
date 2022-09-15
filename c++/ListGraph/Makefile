IDIR1 = dep
IDIR2 = util
ODIR  = bin
SDIR  = src
CC    = g++ 
FLAGS = -g -Wall -I $(IDIR1) -I $(IDIR2) 

main.exe: $(ODIR)/main.o $(ODIR)/City.o
	$(CC) $(FLAGS) $^ -o $(ODIR)/$@

$(ODIR)/main.o: $(SDIR)/main.cpp $(IDIR1)/LinkedList/LinkedList.hpp $(IDIR1)/ListGraph/ListGraph.hpp $(IDIR1)/PriorityQueue/PriorityQueue.hpp
	$(CC) $(FLAGS) -c $< -o $@

$(ODIR)/City.o: $(IDIR2)/City.cpp $(IDIR2)/City.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm bin/main.exe bin/*.o

