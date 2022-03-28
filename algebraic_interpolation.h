#ifndef COMPUTIONAL_WORKSHIP_ALGEBRAIC_INTERPOLATION_H
#define COMPUTIONAL_WORKSHIP_ALGEBRAIC_INTERPOLATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

extern double xx;

bool comp(double x_0, double x_1);

typedef struct table {
    long long num;
    vector<double> knot;
    vector<double> value;
} table;

double f(double x);

double Lagrange(double x, table grid);

double Newton(double x, table grid);

#endif //COMPUTIONAL_WORKSHIP_ALGEBRAIC_INTERPOLATION_H
