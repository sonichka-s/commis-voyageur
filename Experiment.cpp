//
// Created by sonichka on 17.06.22.
//

#include "Experiment.h"
#include "cmath"

double Experiment::approximation(double PrimeWeight, double OptWeight) {
    return PrimeWeight / OptWeight;
}

double Experiment::average(std::vector<double> values) {
    double sum = 0;
    for (auto& val: values)
        sum += val;

    return sum/values.size();
}

double Experiment::standardDeviation(std::vector<double> values) {
    double dispersion = 0;
    double avg = average(values);
    for (auto& val: values)
        dispersion += pow(val - avg, 2);

    return sqrt(dispersion/values.size());
}