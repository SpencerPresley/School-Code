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
   cout << "Enter vertex: ";
   cin >> newVertex;
   cout << endl;

  set<char> reachableVertex;
  reachableVertex = bfs(graphB, newVertex);
  
  writeContainer(reachableVertex.begin(), reachableVertex.end(), " ");
  cout << endl;

  list<char> vList;
  dfs(graphB, vList);
  writeContainer(vList.begin(), vList.end(), " ");
  cout << endl;

  return 0;

}

