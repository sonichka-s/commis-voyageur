#include "iostream"
#include "ctime"

#include "vector"
#include "BoxMuller.h"
#include "WeightListGraph.h"
#include "Route.h"
#include "Experiment.h"

std::vector<double> experiments(int count) {
    std::vector<double> values;

    for (int i = 0; i < 10; ++i) {
        BoxMuller points(count);
        WeightListGraph graph(count);

        for (int from = 0; from < count; ++from) {
            for (int to = from + 1; to < count; ++to) {
                graph.AddEdge(from, to, points.getWeight(from, to));
            }
        }

        double PrimeWeight = Route::MSTRoute(graph);
        double OptWeight = Route::Enumeration(graph);

        values.push_back(Experiment::approximation(PrimeWeight, OptWeight));
    }

    return values;
}

int main() {
    std::srand(time(0));

    for (int i = 2; i <= 10; ++i) {
        std::vector<double> values = experiments(i);

        std::cout << "For experiment with " << i << " vertices:" << std::endl <<
        "Average value: " << Experiment::average(values) << std::endl << "Standard deviation: " <<
        Experiment::standardDeviation(values) << std::endl << std::endl;
    }

    return 0;
}
