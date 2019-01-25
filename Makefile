montecarlo:
	g++ -o bin/montecarlo_price -Wall options/simplemc.cpp

clean:
	rm bin/montecarlo_price
