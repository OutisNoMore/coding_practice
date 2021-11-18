FLAGS = -g -Wall
CC    = g++

BalancedRegister.bin: src/main.o dep/money.o dep/CashRegsiterLogic.o
	$(CC) -o $@ $^ $(FLAGS) $(LIBS)

main.o: src/main.cpp dep/money.hpp dep/CashRegisterLogic.hpp
	$(CC) -c $< $(FLAGS) $(LIBS)

money.o: dep/money.cpp dep/money.hpp
	$(CC) -c $< $(FLAGS) $(LIBS)

CashRegisterLogic.o: dep/CashRegisterLogic.cpp dep/CashRegisterLogic.hpp
	$(CC) -c $< $(FLAGS) $(LIBS)

clean:
	rm dep/*.o src/*.o BalancedRegister.bin
