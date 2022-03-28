#include "lib.h"

double d_func(double x) {
    return 6 * exp(6 * x);
}

double d2_func(double x) {
    return 36 * exp(6 * x);
}

void differ(table grid, double h) {
    vector <double> first_der_1, first_der_2, second_der, ex_first_der, ex_second_der;

    for (int i = 0; i <= grid.num; i++) {
        ex_first_der.push_back(d_func(grid.knot[i]));
        ex_second_der.push_back(d2_func(grid.knot[i]));
    }
    

    first_der_1.push_back((-3 * grid.value[0] + 4 * grid.value[1] - grid.value[2]) / (2 * h));

    for (int i = 1; i < grid.num; i++)
        first_der_1.push_back((grid.value[i + 1] - grid.value[i - 1]) / (2 * h));

    first_der_1.push_back((3 * grid.value[grid.num] - 4 * grid.value[grid.num - 1] + grid.value[grid.num - 2]) / (2 * h));

    first_der_2.push_back((-11 * grid.value[0] + 18 * grid.value[1] - 9 * grid.value[2] + 2 * grid.value[3]) / (6 * h));
    first_der_2.push_back((grid.value[2] - grid.value[0]) / (2 * h));

    for (int i = 2; i < grid.num - 1; i++)
        first_der_2.push_back((grid.value[i - 2] - 8 * grid.value[i - 1] + 8 * grid.value[i + 1] - grid.value[i + 2]) / (12 * h));

    first_der_2.push_back((grid.value[grid.num] - grid.value[grid.num - 2]) / (2 * h));
    first_der_2.push_back((11 * grid.value[grid.num] - 18 * grid.value[grid.num - 1] + 9 * grid.value[grid.num - 2] - 2 * grid.value[grid.num - 3]) / (6 * h));

    for (int i = 1; i < grid.num; i++)
        second_der.push_back((grid.value[i + 1] - 2 * grid.value[i] + grid.value[i - 1]) / (h * h));

    cout << "x_i f(x_i) f'(x_i)_{ЧД_1} |f'(x_i)_{Т} - f'(x_i)_{ЧД_1}| f'(x_i)_{ЧД_2} |f'(x_i)_{Т} - f'(x_i)_{ЧД_2} f''(x_i)_{ЧД} |f''(x_i)_{Т} - f''(x_i)_{ЧД}|" << endl;
    for (int i = 0; i <= grid.num; i++) {
        if (i == 0 || i == grid.num)
            cout << grid.knot[i] << " " << grid.value[i] << " " << first_der_1[i] << " " << abs(ex_first_der[i] - first_der_1[i]) << " " << first_der_2[i] << " " << abs(ex_first_der[i] - first_der_2[i]) << " __ __" << endl;
        else
            cout << grid.knot[i] << " " << grid.value[i] << " " << first_der_1[i] << " " << abs(ex_first_der[i] - first_der_1[i]) << " " << first_der_2[i] << " " << abs(ex_first_der[i] - first_der_2[i]) << " " << setprecision(12) << second_der[i] << " " << abs(ex_second_der[i] - second_der[i - 1]) << endl;
    }
}
