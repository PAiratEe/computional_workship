#include "lib.h"

double d_eq(double x) {
    return -x + 2 * x * x + 1;
}

int factorial(int i) {
    if (i == 0)
        return 1;
    else
        return i * factorial(i - 1);
}

double exact_sol(double x) {
    return sqrt(7) * tan((sqrt(7) * x) / 2) / 4 + 0.25;
}

double Taylor(double x_0, double y_0, double h, double n) {
    double y[6];
    y[0] = y_0;
    y[1] = -y[0] + 2 * y[0] * y[0] + 1;
    y[2] = -y[1] + 4 * y[0] * y[1];
    y[3] = -y[2] + 4 * (y[1] * y[1] + y[0] * y[2]);
    y[4] = -y[3] + 4 * (3 * y[1] * y[2] + y[0] * y[3]);
    y[5] = -y[4] + 4 * (3 * (y[2] * y[2] + y[1] * y[3]) + y[1] * y[3] + y[0] * y[4]);
    double res;
    for (int i = -2; i <= n; i++) {
        res = 0;
        for (int j = 0; j < 6; j++)
            res += y[j] * pow(i * h, j) / factorial(j);
    }
    return res;
}

double Euler_1(double x_0, double y_0, double h, double n) {
    double res = y_0;
    for (int i = 1; i <= n; i++)
        res += h * d_eq(res);
    return res;
}

double Euler_2(double x_0, double y_0, double h, double n) {
    double res = y_0;
    double temp;
    for (int i = 1; i <= n; i ++) {
        temp = res + h * d_eq(res) / 2;
        res += h * d_eq(temp);
    }
    return res;
}

double Euler_3(double x_0, double y_0, double h, double n) {
    double res = y_0;
    double temp;
    for (int i = 1; i <= n; i ++) {
        temp = res + h * d_eq(res);
        res += h * (d_eq(res) + d_eq(temp))/ 2;
    }
    return res;
}

double Runge(double x_0, double y_0, double h, double n) {
    double k_1, k_2, k_3, k_4;
    double temp;
    double res = y_0;
    for (int i = 1; i <= n; i ++) {
        temp = res;
        k_1 = h * d_eq(temp);
        k_2 = h * d_eq(temp + k_1 / 2);
        k_3 = h * d_eq(temp + k_2 / 2);
        k_4 = h * d_eq(temp + k_3);
        res += (k_1 + 2 * k_2 + 2 * k_3 + k_4) / 6;
   }
    return res;
}

double Adams(double x_0, double y_0, double h, int n) {
    double tab[7][n + 1];
    for (int i = 0; i <= 6; i++)
        for (int j = 0; j <= n; j++)
            tab[i][j] = 0;

    for (int i = 0; i <= 4; i++) {
        tab[0][i] = x_0 + (i - 2) * h;
        tab[1][i] = Taylor(x_0, y_0, h, i - 2);
        tab[2][i] = h * d_eq(tab[1][i]);
    }

    for (int i = 3; i <= 6; i++)
        for (int j = 0; j <= 6 - i; j++)
            tab[i][j] = (tab[i - 1][j + 1] - tab[i - 1][j]);

    for (int i = 5; i <= n; i++) {
        tab[0][i] = x_0 + (i - 2) * h;
        tab[1][i] = tab[1][i - 1] + tab[2][i - 1] + tab[3][i - 2] / 2 + 5 * tab[4][i - 3] / 12 + 3 * tab[5][i - 4] / 8 + 251 * tab[6][i - 5] / 720;
        tab[2][i] = h * d_eq(tab[1][i]);
        tab[3][i - 1] = (tab[2][i] - tab[2][i - 1]);
        tab[4][i - 2] = (tab[3][i - 1] - tab[3][i - 2]);
        tab[5][i - 3] = (tab[4][i - 2] - tab[4][i - 3]);
        tab[6][i - 4] = (tab[5][i - 3] - tab[5][i - 4]);
    }
//
//    for (int i = 0; i <= 6; i++) {
//        for (int j = 0; j <= n; j++) {
//            cout << tab[i][j] << " ";
//        }
//        cout << endl;
//    }

    return tab[1][n];

}