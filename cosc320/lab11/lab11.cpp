#include "d_graph.h"
#include <iostream>
#include "d_util.h"

using namespace std;

int main()
{

    graph<char> graphB;
    ifstream graph;
    graph.open("graphB.dat");
    char v, e; // Declaring Vertex and Edge variables
    int w;
    int x = 0;
    graph >> x;
    

    for(int i = 0 ; i < x; i++)
    {
        graph >> v;
        graphB.insertVertex(v);
    }

    graph >> x;
    for(int i = 0 ; i < x; i++)
    {
        graph >> v >> e >> w;
        graphB.insertEdge(v,e,w);
    }

   char newVertex;
   cout << "Enter new vertex: ";
   cin >> newVertex;
   cout << endl;

  set<char> reachableVertex =  bfs(graphB, newVertex);
  
   set<char>::iterator itr;
   list<char> vList;
   list<char> tmp;

int wLargest = minimumPath(graphB, newVertex, *reachableVertex.begin(), vList);
int wTmp;

for(itr = reachableVertex.begin()++; itr!=reachableVertex.end(); itr++)
{
	wTmp = minimumPath(graphB, newVertex, *itr, tmp);
	if(wLargest < wTmp)
	{
		wLargest = wTmp;
		vList = tmp;
	}
}

cout << "Vertex with largest minimum-path value = ";
cout << *(--vList.end()) << endl;

cout << endl << "Minimum-path value = ";
cout << wLargest << endl;

cout << "Vertexes with greatest weight:\n";

for(itr = reachableVertex.begin()++; itr!=reachableVertex.end(); itr++)
	cout << *itr << ", ";
 
    return 0;
}

