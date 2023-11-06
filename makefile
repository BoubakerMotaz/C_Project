program: btc.o main.o
	gcc btc.o main.o -o program -g
main.o: main.c btc.h
	gcc -c main.c -g
btc.o: btc.c btc.h
	gcc -c btc.c -g

