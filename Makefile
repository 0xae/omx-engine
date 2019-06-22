DEBUG=-g -DDEBUG -Wall
OPTIMUS=-O2
BIN=bin
TESTS=tests
CC=g++
PARAMS=-I./src -Wall -std=c++11 -g -DDEBUG

all: payoff payoff2 doubledigital vanillaoption simplemc2 simplemc3 simplemc4

montecarlo: payoff
	$(CC) $(PARAMS) -o bin/montecarlo_price src/options/simplemc.cpp

montecarlo2: payoff simplemc2
	$(CC) $(PARAMS) -o bin/montecarlo2 payoff1.o simplemc2.o src/options/simplemc2main.cpp

montecarlo3: payoff2 simplemc3
	$(CC) $(PARAMS) -o bin/montecarlo3 PayOff2.o simplemc3.o src/options/simplemc3main.cpp

montecarlo4: payoff2 simplemc3
	$(CC) $(PARAMS) -o bin/montecarlo4 PayOff2.o simplemc3.o src/options/simplemc4main.cpp

montecarlo5: payoff2 doubledigital simplemc3
	$(CC) $(PARAMS) -o bin/montecarlo5 doubledigital.o PayOff2.o simplemc3.o src/options/simplemc5main.cpp

vanillamain: vanillaoption doubledigital simplemc4 payoff2
	$(CC) $(PARAMS) -o bin/vanillamain vanilla.o doubledigital.o PayOff2.o simplemc4.o src/options/vanillamain.cpp

tests: payoff simplemc2 simplemc3 simplemc4 payoff2 vanillaoption
	$(CC) $(PARAMS) -o bin/test_uniqueptr vanilla.o doubledigital.o PayOff2.o simplemc4.o tests/test_uniqueptr.cpp
	$(CC) $(PARAMS) -o bin/test_vanillaoption vanilla.o doubledigital.o PayOff2.o simplemc4.o tests/test_vanillaoption.cpp

payoff:
	$(CC) $(PARAMS) -c src/options/payoff1.cpp
payoff2:
	$(CC) $(PARAMS) -c src/options/PayOff2.cpp
doubledigital:
	$(CC) $(PARAMS) -c src/options/doubledigital.cpp
vanillaoption:
	$(CC) $(PARAMS) -c src/options/vanilla.cpp
simplemc2:
	$(CC) $(PARAMS) -c src/options/simplemc2.cpp
simplemc3:
	$(CC) $(PARAMS) -c src/options/simplemc3.cpp
simplemc4:
	$(CC) $(PARAMS) -c src/options/simplemc4.cpp

clean:
	rm bin/*
	rm *.o
