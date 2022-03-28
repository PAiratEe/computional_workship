#ifndef COMPUTIONAL_WORKSHIP_NONLINEAR_EQUATION_H
#define COMPUTIONAL_WORKSHIP_NONLINEAR_EQUATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double f_f(double x);

double df_f(double x);

double d2f_f(double x);

void bisection_method(double A, double B, double epsilon);

void newton_method(double A, double B, double epsilon);

void modified_newton_method(double A, double B, double epsilon);

void secant_method(double A, double B, double epsilon);

void root_separation(double A, double B, double h, double epsilon);

#endif //COMPUTIONAL_WORKSHIP_NONLINEAR_EQUATION_H
