#include "../include/SetGraph.h"

SetGraph::SetGraph(unsigned int verticesNumber_) :
    verticesNumber(verticesNumber_),
    backEdges(verticesNumber),
    straightEdges(verticesNumber)
{}

SetGraph::SetGraph(const IGraph& graph):
    verticesNumber(graph.VerticesCount()),
    backEdges(verticesNumber),
    straightEdges(verticesNumber)
{
    for(int i = 0; i < verticesNumber; i++){
        vector<int> vertices = graph.GetNextVertices(i);
        for(int j : vertices){
            AddEdge(i, j);
        }
    }
}

void SetGraph::AddEdge(int from, int to){
    backEdges[from].insert(to);
    straightEdges[to].insert(from);
}

int SetGraph::VerticesCount() const{
    return verticesNumber;
}

vector<int> SetGraph::GetNextVertices(int vertex) const{
    vector<int> vertices;
    for(int i : backEdges[vertex]){
        vertices.push_back(i);
    }
    return vertices;
}

vector<int> SetGraph::GetPrevVertices(int vertex) const{
    vector<int> vertices;
    for(int i : straightEdges[vertex]){
        vertices.push_back(i);
    }
    return vertices;
}
