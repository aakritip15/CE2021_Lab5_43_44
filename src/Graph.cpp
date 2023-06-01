#include "Graph.h"
#include <iostream>

using namespace std;


Graph:: Graph(bool d)
{
    isdirected = d;
}
int Graph:: numVertices()
{
    return size;
}

int Graph::numEdges(){
    int num = 0;
    for(int i = 0 ; i< size ; i++)
    {   
        while(AdjacencyList[i].next != nullptr)
        {
          num = num+1;
        }
    }
}

int Graph:: outdegree(char vertex)
{   int num = 0;
    for(int i = 0 ; i< size ; i++)
    {   
        if(AdjacencyList[i].name != vertex)
        {
            while(AdjacencyList[i].next != nullptr)
            {
            num = num+1;
            }
            return num;
        }
   
    }
}




