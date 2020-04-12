all: ED
	
ED: main.o
	g++ -o ED main.o ED.o -g -std=c++11 -lsfml-system
main.o: main.cpp ED.o
	g++ -c main.cpp -o main.o -std=c++11 -O1
ED.o: ED.cpp
	g++ -c ED.cpp -o ED.o -std=c++11 -O1
clean:
	rm *.o ED