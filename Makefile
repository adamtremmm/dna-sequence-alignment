ED: ED.o
	g++ -o ED ED.o -std=c++11
ED.o: ED.cpp
	g++ -c ED.cpp -o ED.o -std=c++11
clean:
	rm *.o ED