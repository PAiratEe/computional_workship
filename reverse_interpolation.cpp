#include "lib.h"

double first_method(double F, table grid, long long n) {
    xx = F;
    table rev_grid;
    rev_grid.num = grid.num;

    sort(grid.value.begin(), grid.value.end(), comp);

    for (int i = 0; i <= grid.num; i++)
        for (int j = 0; j <= grid.num; j++)
            if (f(grid.knot[j]) == grid.value[i]) {
                rev_grid.knot.push_back(grid.value[i]);
                rev_grid.value.push_back(grid.knot[j]);
            }

    rev_grid.num = n;

    return Lagrange(F, rev_grid);
}

double f_t(double x, table grid, double F) {
    xx = x;
    sort(grid.knot.begin(), grid.knot.end(), comp);
    for (int i = 0; i <= grid.num; i++)
        grid.value[i] = f(grid.knot[i]);
    return Lagrange(x, grid) - F;
}

double bisection_method_for_table(double A, double B, double epsilon, table grid, double F) {
    while (B - A > 2 * epsilon) {
        double C = (A + B) / 2;
        if (f_t(A, grid, F) * f_t(C, grid, F) <= 0)
            B = C;
        else
            A = C;
    }
    double x = (A + B) / 2;

    return x;
}

void root_separation_for_table(table grid, double epsilon, double F) {
    double h = (grid.knot[grid.num] - grid.knot[0]) / grid.num;
    double x_1 = grid.knot[0];
    double x_2 = x_1 + h;
    double y_1 = f_t(x_1, grid, F);
    double y_2;
    while (x_2 <= grid.knot[grid.num]) {
        y_2 = f_t(x_2, grid, F);
        if (y_1 * y_2 <= 0) {
            cout << "Q_n(F) = " << bisection_method_for_table(x_1, x_2, epsilon, grid, F) << endl
                 << "|f(Q_n(F)) - F| = " << abs(F - f(bisection_method_for_table(x_1, x_2, epsilon, grid, F))) << endl;
        }
        x_1 = x_2;
        x_2 = x_1 + h;
        y_1 = y_2;
    }
}

void second_method(double F, table grid, double epsilon) {
    root_separation_for_table(grid, epsilon, F);
}