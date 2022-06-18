//
// Created by sonichka on 16.06.22.
//

#include "Route.h"

void Route::Prime(WeightListGraph &graph, WeightListGraph& mst) {
    int verticesCount = graph.GetVerticesCount();

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
        std::vector<std::pair<int, double>> nextVertices = graph.GetNextVertices(from.first);

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

    for (int i = 1; i < minWeight.size(); ++i) {
        mst.AddEdge(i, parent[i], minWeight[i]);
    }
}

double Route::MSTRoute(WeightListGraph &graph) {
    int verticesCount = graph.GetVerticesCount();

    WeightListGraph mst(verticesCount);
    Prime(graph, mst);

    std::pair<int, double> root(0, 0);
    std::vector<int> visited(verticesCount, false);
    std::stack<std::pair<int, double>> stack;
    std::vector<int> order;

    stack.push(root);
    double mstWeight = 0;

    while (!stack.empty()) {
        std::pair<int, double> from = stack.top();
        order.push_back(from.first);
        stack.pop();

        visited[from.first] = true;
        std::vector<std::pair<int, double>> nextVertices = mst.GetNextVertices(from.first);
        std::reverse(nextVertices.begin(), nextVertices.end());

        for (auto& next: nextVertices) {
            if(!visited[next.first]) {
                stack.push(next);
            }
        }
    }

    for (int i = 0; i < order.size() - 1; ++i) {
        double vertexWeight = graph.GetWeight(order[i], order[i + 1]);
        if (vertexWeight != -1)
            mstWeight += vertexWeight;
    }
    mstWeight += graph.GetWeight(order[order.size() - 1], 0);

    return mstWeight;
}

double Route::Enumeration(WeightListGraph &graph) {
    int verticesCount = graph.GetVerticesCount();
    std::vector<double> weights;

    std::vector<int> vertices;
    for (int i = 0; i < verticesCount; ++i) {
        vertices.push_back(i);
    }

    while (std::next_permutation(vertices.begin(), vertices.end())) {
        double weight = 0;
        for (int i = 0; i < verticesCount - 1; ++i) {
            double vertexWeight = graph.GetWeight(vertices[i], vertices[i + 1]);
            if(vertexWeight != -1)
                weight += vertexWeight;
        }

        weight += graph.GetWeight(vertices[verticesCount - 1], 0);

        weights.push_back(weight);
    }

    return *std::min_element(weights.begin(), weights.end());
}
