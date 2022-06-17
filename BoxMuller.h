//
// Created by sonichka on 16.06.22.
//

#ifndef COMMIS_VOYAGEUR_BOXMULLER_H
#define COMMIS_VOYAGEUR_BOXMULLER_H

#include "cstdlib"
#include "vector"
#include "cmath"
#include "ctime"

struct BoxMuller {
    BoxMuller(int count);
    double getWeight(int from, int to);
private:
    std::vector<std::pair<double, double>> points;
};

BoxMuller::BoxMuller(int count) {
    for (int i = 0; i < count; ++i) {
        double u = (rand() * 1.0) / RAND_MAX;
        double v = (rand() * 1.0) / RAND_MAX;

        double x = cos(2 * 3.14 * u) * sqrt(-2 * log(v));
        double y = sin(2 * 3.14 * u) * sqrt(-2 * log(v));
//        std::cout << x << ' ' << y << std::endl;

        points.push_back(std::make_pair(x, y));
    }
}

double BoxMuller::getWeight(int from, int to) {
    std::pair<double, double> _p1 = points[from];
    std::pair<double, double> _p2 = points[to];

    double weight = sqrt(pow(_p1.first - _p2.first, 2)  + pow(_p1.second - _p2.second, 2));
    return weight;
}

#endif //COMMIS_VOYAGEUR_BOXMULLER_H
