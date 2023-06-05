#include "Graph.h"
#include <iostream>

using namespace std;

Graph::Graph(bool d)
{
    isdirected = d;
}
Graph::~Graph()
{
}


int Graph::numVertices()
{
    return size;
}



int Graph::outdegree(char vertex)
{
    int outdegree = 0;
    for (int i = 0; i < size; i++)
    {
        if (AdjacencyList[i].name == vertex)
        {
            Node *neighbour = AdjacencyList[i].next;
            while (neighbour != nullptr)
            {
                outdegree = outdegree + 1;
                neighbour = neighbour->next;
            }
            return outdegree;
        }
    }

    return outdegree;
}


void Graph::neighbours(char vertex)
{
    for (int i = 0; i < size; i++)
    {   
        if (AdjacencyList[i].name == vertex)
        {
            cout << "The neighbour of " << AdjacencyList[i].name << " are :" << endl;
            Node *neighbour = AdjacencyList[i].next;
            while (neighbour != NULL)
            {
                cout << neighbour->name << endl;
                neighbour = neighbour->next;
            }
        }
    }

}

bool Graph::neighbour(char vertex1, char vertex2)
{
    bool isneighbour = false;

    // For vertex1 to vertex2 
    for (int i = 0; i < size ; i++)
    {
        if (AdjacencyList[i].name == vertex1)
        {
            Node *neighbour = AdjacencyList[i].next;
            while (neighbour != NULL)
            {
                if (neighbour->name == vertex2)
                {
                    isneighbour = true;
                    return isneighbour; // return true
                }

                neighbour = neighbour->next;
            }
        }
    }

    // Checking for vertex2 to vertex1
    for (int i = 0; i < size; i++)
    {
        if (AdjacencyList[i].name == vertex2)
        {
            Node *neighbour = AdjacencyList[i].next;
            while (neighbour != NULL)
            {
                if (neighbour->name == vertex1)
                {
                    isneighbour = true;
                    return isneighbour; // return true
                }

                neighbour = neighbour->next;
            }
        }
    }

    return isneighbour; // return false
}

void Graph::addVertice(char vertex)
{
    Node newnode = Node(vertex);
    AdjacencyList[size] = newnode;
    cout << size<< AdjacencyList[size].name <<endl;
    size++;
}


void Graph::addEdge(char vertex1, char vertex2)
{
    // Adding vertex1 to vertex2
    for (int i = 0; i < size; i++)
    {
        if (AdjacencyList[i].name == vertex1)
        {
            Node *neighbour = AdjacencyList[i].next;
            Node *vertex = &AdjacencyList[i];
            bool flag = true;
            while (flag)
            {
                if (neighbour == NULL)
                {
                    Node *newnode = new Node(vertex2); // Dynamically allocate memory for the new node
                    vertex->next = newnode;
                    flag = false;
                }
                else
                {
                    vertex = neighbour;
                    neighbour = neighbour->next;
                }
            }
        }
    }

    // Adding vertex2 to vertex1 if it is notdirected
    if (!isdirected)
    { 
        for (int j = 0; j < size; j++)
        {
            if (AdjacencyList[j].name == vertex2)
            {
                Node *neighbour = AdjacencyList[j].next;
                Node *vertex = &AdjacencyList[j];
                bool flag = true;
                while (flag)
                {
                    if (neighbour == NULL)
                    {
                        Node *newnode = new Node(vertex1); // Dynamically allocate memory for the new node
                        vertex->next = newnode;
                        flag = false;
                    }
                    else
                    {
                        vertex = neighbour;
                        neighbour = neighbour->next;
                    }
                }
            }
        }
    }
}

void Graph::removeEdge(char vertex1, char vertex2)
{
    // removing Vertex1 to Vertex2
    for (int i = 0; i < size; i++)
    {
        if (AdjacencyList[i].name == vertex1)
        {
            Node *neighbour = AdjacencyList[i].next;
            Node* vertex = &AdjacencyList[i];
            bool flag = true;
            while ( flag )
            {
                if (neighbour->name == vertex2)
                {
                    vertex->next = neighbour->next;
                    flag = false;
                continue;
                }
                
                vertex = neighbour;
                neighbour = neighbour->next;
                
            }
        }
    }

    // Removing vertex2 to vertex1
    for (int j = 0; j < size; j++)
    {
        if (AdjacencyList[j].name == vertex2)
        {
            Node *neighbour = AdjacencyList[j].next;
            Node* vertex = &AdjacencyList[j];
            bool flag = true;
            while (flag )
            {
                if (neighbour->name == vertex1)
                {
                    vertex->next = neighbour->next;
                    flag = false;
                   
                continue;
                }
                
                vertex = neighbour;
                neighbour = neighbour->next;
    
            }
        }
    }
}