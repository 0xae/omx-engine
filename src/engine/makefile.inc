SOURCE := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SOURCE))
CC := g++
CFLAGS := -Wall -Wno-strict-aliasing -Wno-uninitialized -g -rdynamic -std=gnu99
LFLAGS := -g -DDEBUG -rdynamic


.PHONY : all clean install 

all : $(TARGET)

clean :
	rm -rf *.d *.o $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS) $(LIBS)
.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< $(INCS)

install :

