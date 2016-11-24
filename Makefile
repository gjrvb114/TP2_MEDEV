CC = g++

all: TP_PGM clean

TP_PGM : main.o Image.o
	$(CC) -o $@ $^
	
main.o : main.cpp Image.h includes.h
	$(CC) -o $@ -c $< -std=c++11
	
Image.o : Image.cpp Image.h includes.h
	$(CC) -o $@ -c $< -std=c++11
	
clean:
	rm -f *.o