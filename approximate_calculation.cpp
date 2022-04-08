#include "approximate_calculation.h"

double func(double x, int integralchik) {
    if (integralchik == -1)
        return sin(x) + exp(3 * x) - x; // легко берущийся интеграл
    else if (integralchik == 0)
        return - 2.434;
    else if (integralchik == 1)
        return 2 * x;
    else if (integralchik == 2)
        return 1.432 * x * x;
    else if (integralchik == 3)
        return -4 * x * x * x + 1.432 * x * x + 2 * x - 2.434;
}

double dfunc(double x, int integralchik) {
    if (integralchik == -1)
        return cos(x) + 3 * exp(3 * x) - 1;
    else if (integralchik == 0)
        return 0;
    else if (integralchik == 1)
        return 2;
    else if (integralchik == 2)
        return 2 * 1.432 * x;
    else if (integralchik == 3)
        return -12 * x * x + 2 * 1.432 * x + 2;
}

double d2func(double x, int integralchik) {
    if (integralchik == -1)
        return -sin(x) + 9 * exp(3 * x);
    else if (integralchik == 0)
        return 0;
    else if (integralchik == 1)
        return 0;
    else if (integralchik == 2)
        return 2 * 1.432;
    else if (integralchik == 3)
        return -24 * x + 2 * 1.432;
}

double d4func(double x, int integralchik) {
    if (integralchik == -1)
        return sin(x) + 81 * exp(3 * x);
    else if (integralchik == 0)
        return 0;
    else if (integralchik == 1)
        return 0;
    else if (integralchik == 2)
        return 0;
    else if (integralchik == 3)
        return 0;
}

double integral(double a, double b, int integralchik) {
    if (integralchik == -1)
        return -cos(b) - b * b / 2 + exp(3 * b) / 3 + cos(a) + a * a / 2 - exp(3 * a) / 3; // точное значение интеграла
    else if (integralchik == 0)
        return - 2.434 * b + 2.434 * a;
    else if (integralchik == 1)
        return b * b - a * a;
    else if (integralchik == 2)
        return 179 * b * b * b / 375 - 179 * a * a * a / 375;
    else if (integralchik == 3)
        return - b * b * b * b + 179 * b * b * b / 375 + b * b - 2.434 * b + a * a * a * a - 179 * a * a * a / 375 - a * a + 2.434 * a;
}

double left_rec(double a, double b, int integralchik) {
    return (b - a) * func(a, integralchik);
}

double right_rec(double a, double b, int integralchik) {
    return (b - a) * func(b, integralchik);
}

double mid_rec(double a, double b, int integralchik) {
    return (b - a) * func((a + b) / 2, integralchik);
}

double trap(double a, double b, int integralchik) {
    return (b - a) / 2 * (func(a, integralchik) + func(b, integralchik));
}

double Simpson(double a, double b, int integralchik) {
    return (b - a) / 6 * (func(a, integralchik) + 4 * func((a + b) / 2, integralchik) + func(b, integralchik));
}

double three_eights(double a, double b, int integralchik) {
    double h = (b - a) / 3;
    return (b - a) * (func(a, integralchik) + 3 * func(a + h, integralchik) + 3 * func(a + 2 * h, integralchik) + func(b, integralchik)) / 8;
}

double w(double a, double b, long long m, int integralchik) {
    double sum = 0;
    double h = (b - a) / m;
    for (int i = 1; i < m; i++)
        sum += func(a + i * h, integralchik);
    return sum;
}

double q(double a, double b, long long m, int integralchik) {
    double sum = 0;
    double h = (b - a) / m;
    for (int i = 0; i < m; i++)
        sum += func(a + i * h + h / 2, integralchik);
    return sum;
}

double com_left_rec(double a, double b, long long m, int integralchik) {
    double h = (b - a) / m;
    return h * (func(a, integralchik) + w(a, b, m, integralchik));
}

double com_right_rec(double a, double b, long long m, int integralchik) {
    double h = (b - a) / m;
    return h * (w(a, b, m, integralchik) + func(b, integralchik));
}

double com_mid_rec(double a, double b, long long m, int integralchik) {
    double h = (b - a) / m;
    return h * q(a, b, m, integralchik);
}

double com_trap(double a, double b, long long m, int integralchik) {
    double h = (b - a) / m;
    return h / 2 * (func(a, integralchik) + func(b, integralchik)) + h * w(a, b, m, integralchik);
}

double com_Simpson(double a, double b, long long m, int integralchik) {
    double h = (b - a) / m;
    return h / 6 * (func(a, integralchik) + func(b, integralchik)) + 4 * h * q(a, b, m, integralchik) / 6 + 2 * h * w(a, b, m, integralchik) / 6;
}

double runge(double J_h, double J_h_l, long long l, double d) {
    double r = d + 1;
    return (pow(l, r) * J_h_l - J_h) / (pow(l, r) - 1);
}

double maximo(double a, double b, long long m, int d, int integralchik) {
    double h = (b - a) / m;
    double res;
    if (d == 0) {
        res = abs(dfunc(a, integralchik));
        while (a < b) {
            a += h;
            if (abs(dfunc(a, integralchik)) > res)
                res = abs(dfunc(a, integralchik));
        }
        //res = abs(dfunc(b, integralchik));
    }
    else if (d == 1) {
        res = abs(d2func(a, integralchik));
        while (a < b) {
            a += h;
            if (abs(d2func(a, integralchik)) > res)
                res = abs(d2func(a, integralchik));
        }
        //res = abs(d2func(b, integralchik));
    }
    else if (d == 3) {
        res = abs(d4func(a, integralchik));
        while (a < b) {
            a += h;
            if (abs(d4func(a, integralchik)) > res)
                res = abs(d4func(a, integralchik));
        }
        //res = abs(d4func(b, integralchik));
    }
    return res;
}