#ifndef COMPUTIONAL_WORKSHIP_DIFF_EQ_H
#define COMPUTIONAL_WORKSHIP_DIFF_EQ_H

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int factorial(int i);

double exact_sol(double x);

double Taylor(double x_0, double y_0, double h, double n);

double Euler_1(double x_0, double y_0, double h, double n);

double Euler_2(double x_0, double y_0, double h, double n);

double Euler_3(double x_0, double y_0, double h, double n);

double Runge(double x_0, double y_0, double h, double n);

double Adams(double x_0, double y_0, double h, int n);

#endif //COMPUTIONAL_WORKSHIP_DIFF_EQ_H
