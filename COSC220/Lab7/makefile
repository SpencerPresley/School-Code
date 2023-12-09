all: bst

bst: TNode.o BST.o main.o
	g++ TNode.o BST.o main.o -o bst

TNode.o: TNode.cpp
	g++ -c TNode.cpp

BST.o: BST.cpp
	g++ -c BST.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *o bst
