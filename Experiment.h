//
// Created by sonichka on 17.06.22.
//

#ifndef COMMIS_VOYAGEUR_EXPERIMENT_H
#define COMMIS_VOYAGEUR_EXPERIMENT_H

#include "vector"

namespace Experiment {
    double approximation(double PrimeWeight, double OptWeight);
    double average(std::vector<double> values);
    double standardDeviation(std::vector<double> values);
};


#endif //COMMIS_VOYAGEUR_EXPERIMENT_H
