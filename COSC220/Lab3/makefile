all: list

list: linkFun.o linkedList.o
	g++ linkFun.o linkedList.o -o list

linkedList.o: linkedList.cpp
	g++ -c linkedList.cpp

linkFun.o: linkFun.cpp
	g++ -c linkFun.cpp

clean:
	rm -rf *o list

