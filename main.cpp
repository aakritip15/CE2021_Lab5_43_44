
#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
  bool direction = true;
  Graph graph(direction);
  
  graph.addVertice('A');
  graph.addVertice('B');
  graph.addVertice('C');
  graph.addVertice('D');
  graph.addVertice('E');

  graph.addEdge('A','B');
  graph.addEdge('A','D');
  graph.addEdge('A','E');

  
  graph.addEdge('B','A');
  graph.addEdge('B','D');
  graph.addEdge('B','C');
  
  graph.addEdge('C','D');
  graph.addEdge('D','A');
  
  graph.addEdge('E','C');
  graph.addEdge('E','A');

  graph.neighbours('A');
  graph.neighbours('B');
  
  cout << "Removing Edge A and D" <<endl;
  graph.removeEdge('A','D');
  graph.neighbours('A');
   
  cout << "The outdegree of A is " << graph.outdegree('A');
  cout << "Number of Vertice: " << graph.numVertices()<<endl;
  cout << "Is B and A neighbour: " << graph.neighbour('A','B') <<endl;
}