all: heap

heap: heap.o main.o
	g++ heap.o main.o -o heap

heap.o: heap.cpp
	g++ -c heap.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o heap
