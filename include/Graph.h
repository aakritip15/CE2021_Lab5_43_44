#ifndef Graph_h
#define Graph_h


class Node
{
 public:
 char name;
 Node * next;
};



class Graph
{
public:
Node* AdjacencyList = new Node;
int size = 0;
bool isdirected; 

    Graph(bool d=false) ;
    ~Graph();
    void removeEdge(char vertex1,char  vertex2);
    int numVertices();
    int numEdges();
    int indegree(char vertex);
    int outdegree(char vertex);
    int degree(char vertex);
    char neighbours(char vertex);
    bool neighbour(char vertex1,char vertex2);
};



#endif