DEBUG=-g -DDEBUG -Wall
OPTIMUS=-O2
BIN=bin
TESTS=tests
CC=g++
PARAMS=-Ioptions/ -Wall

montecarlo: payoff
	$(CC) $(PARAMS) -o bin/montecarlo_price options/simplemc.cpp

payoff:
	$(CC) $(PARAMS) -c options/payoff1.cpp

clean:
	rm bin/montecarlo_price
