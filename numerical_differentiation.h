#ifndef COMPUTIONAL_WORKSHIP_NUMERICAL_DIFFERENTIATION_H
#define COMPUTIONAL_WORKSHIP_NUMERICAL_DIFFERENTIATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "algebraic_interpolation.h"

using namespace std;

double d_func(double x);

double d2_func(double x);

void differ(table grid, double h);

#endif //COMPUTIONAL_WORKSHIP_NUMERICAL_DIFFERENTIATION_H
