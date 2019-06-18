DEBUG=-g -DDEBUG -Wall
OPTIMUS=-O2
BIN=bin
TESTS=tests
CC=g++
PARAMS=-I./src -Wall

montecarlo: payoff
	$(CC) $(PARAMS) -o bin/montecarlo_price src/options/simplemc.cpp

montecarlo2: payoff simplemc2
	$(CC) $(PARAMS) -o bin/montecarlo2 payoff1.o simplemc2.o src/options/simplemc2main.cpp

tests: payoff simplemc2
	$(CC) $(PARAMS) -o bin/test_payoff payoff1.o tests/test_payoff.cpp

payoff:
	$(CC) $(PARAMS) -c src/options/payoff1.cpp
simplemc2:
	$(CC) $(PARAMS) -c src/options/simplemc2.cpp

clean:
	rm bin/*
	rm *.o
