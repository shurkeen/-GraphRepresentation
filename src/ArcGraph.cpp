#include "../include/ArcGraph.h"

ArcGraph::Edge::Edge(int from, int to) : from(from), to(to) {}

ArcGraph::ArcGraph(unsigned int verticesNumber_):
    verticesNumber(verticesNumber_)
{}

ArcGraph::ArcGraph(const IGraph& graph):
    verticesNumber(graph.VerticesCount())
{
    for(int i = 0; i < verticesNumber; i++){
        vector<int> vertices = graph.GetNextVertices(i);
        for(int j : vertices){
            AddEdge(i, j);
        }
    }
}

void ArcGraph::AddEdge(int from, int to){
    for(const auto& i : edges){
        if(i.from == from && i.to == to){
            return;
        }
    }

    Edge edge(from, to);
    edges.push_back(edge);
}

int ArcGraph::VerticesCount() const{
    return verticesNumber;
}

vector<int> ArcGraph::GetNextVertices(int vertex) const{
    vector<int> vertices;
    for(const Edge & i : edges){
        if(i.from == vertex){
            vertices.push_back(i.to);
        }
    }
    return vertices;
}
 
vector<int> ArcGraph::GetPrevVertices(int vertex) const{
    vector<int> vertices;
    for(const Edge & i : edges){
        if(i.to == vertex){
            vertices.push_back(i.from);
        }
    }
    return vertices;
}
