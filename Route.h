//
// Created by sonichka on 16.06.22.
//

#ifndef COMMIS_VOYAGEUR_ROUTE_H
#define COMMIS_VOYAGEUR_ROUTE_H

#include "iostream"
#include "set"
#include "stack"
#include "queue"
#include "algorithm"
#include "WeightListGraph.h"


namespace Route {
    void Prime(WeightListGraph& graph, WeightListGraph& mst);
    double MSTRoute(WeightListGraph& graph);
    double Enumeration(WeightListGraph& graph);
};

#endif //COMMIS_VOYAGEUR_ROUTE_H
