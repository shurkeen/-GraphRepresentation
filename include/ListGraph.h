#ifndef LIST_GRAPH_H
#define LIST_GRAPH_H

#include "IGraph.h"
#include <list>

using std::list;

class ListGraph : public IGraph{
public:
    ListGraph(unsigned int verticesNumber_);
    ListGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual vector<int> GetNextVertices(int vertex) const override;
    virtual vector<int> GetPrevVertices(int vertex) const override;
    
private:
    unsigned int verticesNumber;

    vector<list<int> > straightEdges;
    vector<list<int> > backEdges;
};

#endif //LIST_GRAPH_H
