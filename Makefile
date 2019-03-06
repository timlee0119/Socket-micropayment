CFLAGS = -g -Wall -std=c++11 -pthread -lcrypto

.PHONY: all clean 

all: server client

server: server.cpp aes.cpp aes.h server.h common.h
	g++ server.cpp aes.cpp -o $@ $(CFLAGS)

client: client.cpp aes.cpp aes.h common.h
	g++ client.cpp aes.cpp -o $@ $(CFLAGS)	

clean:
	rm -rf server client
