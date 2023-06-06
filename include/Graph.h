#ifndef Graph_h
#define Graph_h
#define NULL __null

class Node
{
 public:
 char name;
 Node * next;

Node()
{

}
 Node(char vertex )
 {
    name = vertex;
    next = NULL;
 }
};


class Graph
{
public:
Node* AdjacencyList = new Node(10);
int size = 0;
bool isdirected; 

    Graph(bool d = false) ;
    ~Graph();

    void addVertice(char vertex);
    void addEdge(char vertex1, char vertex2);
    void removeEdge(char vertex1,char  vertex2);
    int numVertices();
    int outdegree(char vertex);
    void neighbours(char vertex);
    bool neighbour(char vertex1,char vertex2);

    bool is_empty();
    bool isDirected():
    int degree(char vertex);
    int indegree(char vertex);
    int numEdges();
    void removeVertice(char vertex);

};
#endif