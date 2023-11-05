CC = gcc
CFLAGS = -g

all: btc

btc: btc.o main.o
	$(CC) btc.o main.o -o btc

main.o: main.c
	$(CC) -c main.c $(CFLAGS)

btc.o: btc.c
	$(CC) -c btc.c $(CFLAGS)

clean:
	rm -f btc btc.o main.o

