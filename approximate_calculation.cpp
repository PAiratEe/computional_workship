#include "approximate_calculation.h"

double func(double x) {
    //return sin(x) + exp(3 * x) - x; // легко берущийся интеграл
    //return - 2.434;
    //return 2 * x;
    //return 1.432 * x * x;
    return -4 * x * x * x + 1.432 * x * x + 2 * x - 2.434;
}

double integral(double a, double b) {
    //return -cos(b) - b * b / 2 + exp(3 * b) / 3 + cos(a) + a * a / 2 - exp(3 * a) / 3; // точное значение интеграла
    //return - 2.434 * b + 2.434 * a;
    //return b * b - a * a;
    //return 179 * b * b * b / 375 - 179 * a * a * a / 375;
    return - b * b * b * b + 179 * b * b * b / 375 + b * b - 2.434 * b + a * a * a * a - 179 * a * a * a / 375 - a * a + 2.434 * a;
}

double left_rec(double a, double b) {
    return (b - a) * func(a);
}

double right_rec(double a, double b) {
    return (b - a) * func(b);
}

double mid_rec(double a, double b) {
    return (b - a) * func((a + b) / 2);
}

double trap(double a, double b) {
    return (b - a) / 2 * (func(a) + func(b));
}

double Simpson(double a, double b) {
    return (b - a) / 6 * (func(a) + 4 * func((a + b) / 2) + func(b));
}

double three_eights(double a, double b) {
    double h = (b - a) / 3;
    return (b - a) * (func(a) + 3 * func(a + h) + 3 * func(a + 2 * h) + func(b)) / 8;
}