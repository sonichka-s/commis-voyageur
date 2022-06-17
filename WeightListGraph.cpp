//
// Created by sonichka on 16.06.22.
//

#include "WeightListGraph.h"

void WeightListGraph::AddEdge(int from, int to, double weight) {
    vertices[from].push_back(std::make_pair(to, weight));
    vertices[to].push_back(std::make_pair(from, weight));
}

std::vector<std::pair<int, double>> WeightListGraph::GetNextVertices(std::pair<int, double> vertex) {
    std::vector<std::pair<int, double>> result(vertices[vertex.first].begin(), vertices[vertex.first].end());
    return result;
}

std::vector<std::pair<int, double>> WeightListGraph::GetPrevVertices(std::pair<int, double> vertex) {
    std::vector<std::pair<int, double>> result(vertices[vertex.first].begin(), vertices[vertex.first].end());
    return result;
}

double WeightListGraph::GetWeight(int from, int to) {
    for (int i = 0; i < vertices.size(); ++i) {
        if (vertices[from][i].first == to)
            return vertices[from][i].second;
    }

    return -1;
}

int WeightListGraph::GetVerticesCount() {
    return vertices.size();
}