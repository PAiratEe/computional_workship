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

double sec_method(double x_i, double x_ii, double epsilon, int n);

void root_sep(double x_i, double x_ii, double epsilon, int n, double a, double b);

void Meler(int N);

void root_sep_2(double x_i, double x_ii, double epsilon, int n, int m, double a, double b);

double secc_method(double A, double B, double epsilon, double p, double q);

void r_s(double A, double B, int m, double epsilon, double p, double q);

void calc(double a, double b, int m);

#endif //COMPUTIONAL_WORKSHIP_QUADRATURE_FORMULAS_H
