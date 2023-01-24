#ifndef SET_GRAPH_H
#define SET_GRAPH_H

#include <unordered_set>
#include "IGraph.h"

using std::unordered_set;

class SetGraph : public IGraph{
public:
    SetGraph(unsigned int verticesNumber_);
    SetGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual vector<int> GetNextVertices(int vertex) const override;
    virtual vector<int> GetPrevVertices(int vertex) const override;

private:
    unsigned int verticesNumber;

    vector<unordered_set<int> > straightEdges;
    vector<unordered_set<int> > backEdges;

};

#endif //SET_GRAPH_H
