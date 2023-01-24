#include <iostream>
#include "../include/MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned int verticesNumber_):
    verticesNumber(verticesNumber_),
    edges(verticesNumber)
{
    for(vector<bool>& i : edges){
        i.assign(verticesNumber, false);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph):
    verticesNumber(graph.VerticesCount()),
    edges(verticesNumber)
{
    for(vector<bool> & i : edges){
        i.assign(verticesNumber, false);
    }

    for(int i = 0; i < verticesNumber; i++){
        vector<int> vertices = graph.GetNextVertices(i);
        for(int j : vertices){
            AddEdge(i, j);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to){
    edges[from][to] = true;
}

int MatrixGraph::VerticesCount() const{
    return verticesNumber;
}

vector<int> MatrixGraph::GetNextVertices(int vertex) const{
    vector<int> vertices;
    for(int i = 0; i < verticesNumber; i++){
        if(edges[vertex][i]){
            vertices.push_back(i);
        }
    }
    return vertices;
}

vector<int> MatrixGraph::GetPrevVertices(int vertex) const{
    vector<int> vertices;
    for(int i = 0; i < verticesNumber; i++){
        if(edges[i][vertex]){
            vertices.push_back(i);
        }
    }
    return vertices;
}
