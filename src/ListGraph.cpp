#include "../include/ListGraph.h"

ListGraph::ListGraph(unsigned int verticesNumber_):
    verticesNumber(verticesNumber_),
    straightEdges(verticesNumber),
    backEdges(verticesNumber)
{}

ListGraph::ListGraph(const IGraph& graph):
    verticesNumber(graph.VerticesCount()),
    straightEdges(verticesNumber),
    backEdges(verticesNumber)
{
    for(int i = 0; i < verticesNumber; i++){
        vector<int> vertices = graph.GetNextVertices(i);
        for(int j : vertices){
            AddEdge(i, j);
        }
    }
}

void ListGraph::AddEdge(int from, int to){
    if(straightEdges.size() < backEdges.size()){
        for(int i : straightEdges[to]){
            if(i == from){
                return ;
            }
        }
    }
    else{
        for(int i : backEdges[from]){
            if(i == to){
                return ;
            }
        }
    }
    straightEdges[to].push_back(from);
    backEdges[from].push_back(to);
}

int ListGraph::VerticesCount() const{
    return verticesNumber;
}

vector<int> ListGraph::GetNextVertices(int vertex) const{
    vector<int> vertices;
    for(int i : backEdges[vertex]){
        vertices.push_back(i);
    }
    return vertices;
}

vector<int> ListGraph::GetPrevVertices(int vertex) const{
    vector<int> vertices;
    for(int i : straightEdges[vertex]){
        vertices.push_back(i);
    }
    return vertices;
}
