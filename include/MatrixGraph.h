#ifndef MATRIX_GRAPH_H
#define MATRIX_GRAPH_H

#include "IGraph.h"

class MatrixGraph : public IGraph{
public:
    MatrixGraph(unsigned int verticesNumber_);
    MatrixGraph(const IGraph& graph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual vector<int> GetNextVertices(int vertex) const override;
    virtual vector<int> GetPrevVertices(int vertex) const override;

private:
    unsigned int verticesNumber;

    vector<vector<bool>> edges;
};

#endif //MATRIX_GRAPH_H
