//
// Created by sonichka on 16.06.22.
//

#include "Route.h"

double Route::Prime(WeightListGraph &graph) {
    int verticesCount = graph.GetVerticesCount();
    double resultWeight = 0;

    std::set<std::pair<int, double>> pQueue;
    std::vector<bool> inMST(verticesCount, false);

    std::vector<int> parent(verticesCount, -1);
    std::vector<double> minWeight(verticesCount, INT16_MAX);

    pQueue.insert(std::pair<int, double>(0, 0));
    minWeight[0] = 0;

    while(!pQueue.empty()) {
        std::pair<int, double> from = *pQueue.begin();
        pQueue.erase(pQueue.begin());
        inMST[from.first] = true;
        std::vector<std::pair<int, double>> nextVertices = graph.GetNextVertices(from);

        for (auto& next: nextVertices) {
            if(!inMST[next.first] && next.second < minWeight[next.first]) {
                if (minWeight[next.first] != INT16_MAX)
                    pQueue.erase(pQueue.find(std::pair<int, double>(next.first, minWeight[next.first])));
                pQueue.insert(std::pair<int, double>(next.first, next.second));
                minWeight[next.first] = next.second;
                parent[next.first] = from.first;
            }
        }
    }

    for (int i = 0; i < minWeight.size(); ++i) {
        resultWeight += minWeight[i];
    }

    return resultWeight;
}

double Route::Enumeration(WeightListGraph &graph) {
    int verticesCount = graph.GetVerticesCount();
    std::vector<double> weights;

    for (int i = 0; i < verticesCount; ++i) {
        double weight = 0;
        double vertexWeight;
        for (int j = 0; j < verticesCount; ++j) {
            vertexWeight = graph.GetWeight(j, j + 1);
            if(vertexWeight != -1)
                weight += vertexWeight;
        }

        weights.push_back(weight);
    }

    return *std::min_element(weights.begin(), weights.end());
}
