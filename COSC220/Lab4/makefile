all: program

program: Node.o LinkedList.o lab3.o
	g++ Node.o LinkedList.o lab3.o -o program

Node.o: Node.cpp
	g++ -c Node.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

Lab3.o: lab3.cpp
	g++ -c lab3.cpp

clean:
	rm -rf *o program
