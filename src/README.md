Building the engine
===

In order to build the engine you need to have make, gcc and buildtools installed
Instalation has been tested successfully on linux (ubuntu) only.

## Build the core Libraries


### Build the utils
```cd engine/utils && make```

### Build the network lib
```cd engine/network && make```


## Build the core applications

### Build match engine

```cd engine/matchengine && make```

You can also use zig programming language, to build the binaries

```zig cc -g -DDEBUG -rdynamic -o omx-match-engine  me_operlog.o  me_persist.o  me_cli.o  me_load.o  me_balance.o  me_config.o  me_dump.o  me_main.o  me_server.o  me_trade.o  me_history.o  me_update.o  me_message.o  me_market.o -L ../utils -lutils -L ../network -lnetwork -Wl,-Bstatic -lev -ljansson -lmpdec -lmysqlclient -lz -lrdkafka -lssl -lcrypto -lhiredis -Wl,-Bdynamic -lm -lpthread -ld```

### Run the match engine
```./matchengine/omx-match-engine ./matchengine/config.json``
