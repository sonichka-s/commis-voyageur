//
// Created by sonichka on 16.06.22.
//

#ifndef COMMIS_VOYAGEUR_ROUTE_H
#define COMMIS_VOYAGEUR_ROUTE_H

#include "iostream"
#include "set"
#include "algorithm"
#include "WeightListGraph.h"


namespace Route {
    double Prime(WeightListGraph& graph);
    double Enumeration(WeightListGraph& graph);
};


#endif //COMMIS_VOYAGEUR_ROUTE_H
