TARGET  := matchengine
INCS = -I ../network -I ../utils
LIBS = -L ../utils -L ../network -lutils -lnetwork -Wl,-Bstatic -lev -ljansson -lmpdec -lmysqlclient -lz -lrdkafka -lssl -lcrypto -lhiredis -Wl,-Bdynamic -lm -lpthread -ldl
include ../makefile.inc
