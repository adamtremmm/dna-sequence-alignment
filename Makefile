all: ED

ED: main.o
	g++ -o ED main.o ED.o -std=c++11 -lsfml-system
main.o: main.cpp ED.o
	g++ -c main.cpp -o main.o -std=c++11 -O1 -g
ED.o: ED.cpp
	g++ -c ED.cpp -o ED.o -std=c++11 -O1 -g
clean:
	rm *.o ED