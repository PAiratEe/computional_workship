#ifndef COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H
#define COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double func(double x);

double integral(double a, double b);

double left_rec(double a, double b);

double right_rec(double a, double b);

double mid_rec(double a, double b);

double trap(double a, double b);

double Simpson(double a, double b);

double three_eights(double a, double b);

#endif //COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H
