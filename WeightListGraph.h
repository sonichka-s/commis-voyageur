//
// Created by sonichka on 16.06.22.
//

#ifndef COMMIS_VOYAGEUR_WEIGHTLISTGRAPH_H
#define COMMIS_VOYAGEUR_WEIGHTLISTGRAPH_H

#include "vector"

class WeightListGraph {
public:
    explicit WeightListGraph(int n) : vertices(n) {}

    ~WeightListGraph() {}

    void AddEdge(int from, int to, double weight);

    std::vector<std::pair<int, double>> GetNextVertices(std::pair<int, double> vertex);

    std::vector<std::pair<int, double>> GetPrevVertices(std::pair<int, double> vertex);

    double GetWeight(int from, int to);

    int GetVerticesCount();

private:
    std::vector<std::vector<std::pair<int, double>>> vertices;
};


#endif //COMMIS_VOYAGEUR_WEIGHTLISTGRAPH_H
