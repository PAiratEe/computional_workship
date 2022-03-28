#ifndef COMPUTIONAL_WORKSHIP_REVERSE_INTERPOLATION_H
#define COMPUTIONAL_WORKSHIP_REVERSE_INTERPOLATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "algebraic_interpolation.h"

using namespace std;

double first_method(double F, table grid, long long n);

double f_t(double x, table grid);

double bisection_method_for_table(double A, double B, double epsilon, table grid, double F);

void root_separation_for_table(table grid, double epsilon, double F);

void second_method(double F, table grid, double epsilon);

#endif //COMPUTIONAL_WORKSHIP_REVERSE_INTERPOLATION_H
