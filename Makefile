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

montecarlo3: payoff2 simplemc3
	$(CC) $(PARAMS) -o bin/montecarlo3 PayOff2.o simplemc3.o src/options/simplemc3main.cpp

tests: payoff simplemc2
	$(CC) $(PARAMS) -o bin/test_payoff payoff1.o tests/test_payoff.cpp

payoff:
	$(CC) $(PARAMS) -c src/options/payoff1.cpp
payoff2:
	$(CC) $(PARAMS) -c src/options/PayOff2.cpp
simplemc2:
	$(CC) $(PARAMS) -c src/options/simplemc2.cpp
simplemc3:
	$(CC) $(PARAMS) -c src/options/simplemc3.cpp

clean:
	rm bin/*
	rm *.o
