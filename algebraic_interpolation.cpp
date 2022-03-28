#include "lib.h"

double xx = 10;

bool comp(double x_0, double x_1) {    // Функция, находящая ближайшие к х узлы
    return abs(x_0 - xx) < abs(x_1 - xx);
}

double f(double x) {
    //return sin(x) + x / 3;
    return log(1 + x) - exp(x);
}

double Lagrange(double x, table grid) {
    double P_nL = 0, l_kn_num = 1, l_kn_den = 1;
    double tmp;

    for (int i = 0; i <= grid.num; i++) {
        for (int j = 0; j <= grid.num; j++) {
            tmp = grid.knot[i];
            if (grid.knot[j] != tmp) {
                l_kn_num *= (x - grid.knot[j]);
                l_kn_den *= (tmp - grid.knot[j]);
            }
        }
        P_nL += grid.value[i] * l_kn_num / l_kn_den;
        l_kn_num = 1;
        l_kn_den = 1;
    }
    return P_nL;
}

double Newton(double x, table grid) {
    double tab[grid.num + 1][grid.num + 1];
    for (int i = 0; i <= grid.num; i++)
        for (int j = 0; j <= grid.num; j++)
            tab[i][j] = 0;
    for (int i = 0; i <= grid.num; i++)
        tab[0][i] = grid.value[i];

    for (int i = 1; i <= grid.num; i++)
        for (int j = 0; j <= grid.num - i; j++)
            tab[i][j] = (tab[i - 1][j + 1] - tab[i - 1][j]) / (grid.knot[j + i] - grid.knot[j]);

    double tmp;
    double P_nN = 0;
    for (int i = 0; i <= grid.num; i++) {
        tmp = 1;
        for (int j = 0; j < i; j++) {
            tmp *= (x - grid.knot[j]);
        }

        P_nN += tab[i][0] * tmp;
    }
    return P_nN;
}