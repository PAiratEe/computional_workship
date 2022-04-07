#ifndef COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H
#define COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double func(double x, int integralchik);

double dfunc(double x, int integralchik);

double d2func(double x, int integralchik);

double d4func(double x, int integralchik);

double integral(double a, double b, int integralchik);

double left_rec(double a, double b, int integralchik);

double right_rec(double a, double b, int integralchik);

double mid_rec(double a, double b, int integralchik);

double trap(double a, double b, int integralchik);

double Simpson(double a, double b, int integralchik);

double three_eights(double a, double b, int integralchik);

double w(double a, double b, long long m, int integralchik);

double q(double a, double b, long long m, int integralchik);

double com_left_rec(double a, double b, long long m, int integralchik);

double com_right_rec(double a, double b, long long m, int integralchik);

double com_mid_rec(double a, double b, long long m, int integralchik);

double com_trap(double a, double b, long long m, int integralchik);

double com_Simpson(double a, double b, long long m, int integralchik);

double runge(double J_h, double J_h_l, long long l, double d);

double maximo(double a, double b, long long m, int d, int integralchik);

#endif //COMPUTIONAL_WORKSHIP_APPROXIMATE_CALCULATION_H
