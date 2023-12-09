all: glist

glist: gfun.o glist.o
	g++ gfun.o glist.o -o glist

glist.o: glist.cpp
	g++ -c glist.cpp

gfun.o: gfun.cpp
	g++ -c gfun.cpp

clean:
	rm -rf *o glist
