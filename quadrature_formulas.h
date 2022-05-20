#ifndef COMPUTIONAL_WORKSHIP_QUADRATURE_FORMULAS_H
#define COMPUTIONAL_WORKSHIP_QUADRATURE_FORMULAS_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "algebraic_interpolation.h"

using namespace std;

double f_g(double x);

double f_ff(double x);

double Legendre(int n, double x);

double koeffs(int n, double x);

double sec_method(double x_i, double x_ii, double epsilon, int n, double a, double b);

void root_sep(double x_i, double x_ii, double epsilon, int n, double a, double b);

void Meler(int N);

void root_sep_2(double x_i, double x_ii, double epsilon, int n, int m, double a, double b);

#endif //COMPUTIONAL_WORKSHIP_QUADRATURE_FORMULAS_H
