#ifndef ARC_GRAPH_H
#define ARC_GRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph{
    struct Edge{
        Edge(int from, int to);
        int from;
        int to;
    };
public:
    ArcGraph(unsigned int verticesNumber);
    ArcGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual vector<int> GetNextVertices(int vertex) const override;
    virtual vector<int> GetPrevVertices(int vertex) const override;

private:
    unsigned int verticesNumber;

    vector<Edge> edges;
};

#endif //ARC_GRAPH_H
