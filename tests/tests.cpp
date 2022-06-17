//
// Created by sonichka on 17.06.22.
//
#include "gtest/gtest.h"
#include "Experiment.h"
#include "WeightListGraph.h"
#include "Route.h"

//тестовые вершины для графа
std::pair<int, double> v0_1(1, 3);
std::pair<int, double> v0_2(2, 4);

std::pair<int, double> v1_0(0, 3);
std::pair<int, double> v1_2(2, 5);

std::pair<int, double> v2_0(0, 4);
std::pair<int, double> v2_1(1, 5);


//количество вершин
int verticesCount = 3;

TEST(weight_graph, graph_constructor) {
    WeightListGraph graph(3);

    ASSERT_EQ(graph.GetVerticesCount(), verticesCount);
}

TEST(weight_graph, add_vertices) {
    WeightListGraph graph(3);

    graph.AddEdge(0, 1, 3);
    graph.AddEdge(1, 2, 5);
    graph.AddEdge(2, 0, 4);

    std::vector<std::pair<int, double>> firstNextVertices = graph.GetNextVertices(std::make_pair(0, 3));

    ASSERT_EQ(firstNextVertices[0], v0_1);
    ASSERT_EQ(firstNextVertices[1], v0_2);

    std::vector<std::pair<int, double>> secondNextVertices = graph.GetNextVertices(std::make_pair(1, 3));

    ASSERT_EQ(secondNextVertices[0], v1_0);
    ASSERT_EQ(secondNextVertices[1], v1_2);

    std::vector<std::pair<int, double>> thirdNextVertices = graph.GetNextVertices(std::make_pair(2, 4));

    ASSERT_EQ(thirdNextVertices[0], v2_1);
    ASSERT_EQ(thirdNextVertices[1], v2_0);
}

TEST(weight_graph, get_weight) {
    WeightListGraph graph(3);

    graph.AddEdge(0, 1, 3);
    graph.AddEdge(1, 2, 5);
    graph.AddEdge(2, 0, 4);

    ASSERT_EQ(graph.GetWeight(0, 1), v0_1.second);
    ASSERT_EQ(graph.GetWeight(1, 0), v1_0.second);
    ASSERT_EQ(graph.GetWeight(1, 2), v1_2.second);
    ASSERT_EQ(graph.GetWeight(2, 1), v2_1.second);
    ASSERT_EQ(graph.GetWeight(2, 0), v0_2.second);
    ASSERT_EQ(graph.GetWeight(0, 2), v2_0.second);
}

//тествовые входные данные для статистических методов
double testPrimeWeight = 1;
double testOptWeight = 1;
double testApproximation = testPrimeWeight / testOptWeight;

std::vector<double> testValues;

TEST(experiment, approximation) {
    ASSERT_EQ(Experiment::approximation(testPrimeWeight, testOptWeight), testApproximation);
}

TEST(experiment, average_value) {
    for(double i = 0; i < 10; ++i) {
        testValues.push_back(10);
    }

    ASSERT_EQ(Experiment::average(testValues), 10);
}

TEST(experiment, standard_deviation) {
    for(double i = 0; i < 10; ++i) {
        testValues.push_back(10);
    }

    ASSERT_EQ(Experiment::standardDeviation(testValues), 0);
}

TEST(Route, prime) {
    WeightListGraph graph(3);

    graph.AddEdge(0, 1, 3);
    graph.AddEdge(1, 2, 2);
    graph.AddEdge(2, 0, 4);

    ASSERT_EQ(Route::Prime(graph), 5);
}

TEST(Route, enumeration) {
    WeightListGraph graph(3);

    graph.AddEdge(0, 1, 3);
    graph.AddEdge(1, 2, 2);
    graph.AddEdge(2, 0, 4);

    ASSERT_EQ(Route::Enumeration(graph), 5);
}