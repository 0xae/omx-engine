TARGET  := marketprice.exe
INCS = -I ../network -I ../utils
LIBS = -L ../utils -lutils -L ../network -lnetwork -Wl,-Bstatic -lev -ljansson -lmpdec -lrdkafka -lz -lssl -lcrypto -lhiredis -Wl,-Bdynamic -lm -lpthread -ldl -g -lcurl 
include ../makefile.inc

tests:
	gcc -Wall -Wno-strict-aliasing -Wno-uninitialized -g -rdynamic -std=gnu99 -c -o mp_test.o mp_test.c -I ../network -I ../utils
	gcc -g -rdynamic -o mk_test mp_test.o  -L ../utils -lutils -L ../network -lnetwork -Wl,-Bstatic -lev -ljansson -lmpdec -lrdkafka -lz -lssl -lcrypto -lhiredis -Wl,-Bdynamic -lm -lpthread -ldl -g -lcurl