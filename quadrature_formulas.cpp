#include "lib.h"

double f_g(double x) {
    return sqrt(x) * pow(exp(1), x * x);
}

double f_m(double x) {
    return log(2 + x) / (1 + x * x * x);
}

double f_ff(double x) {
    return exp(-x) * sin(x);
}

double Legendre(int n, double x) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n > 1)
        return (Legendre(n - 1, x) * (2 * n - 1) * x) / n - ((n - 1) * Legendre(n - 2, x)) / n;
}

double koeffs(int n, double x) {
    return 2 * (1 - x * x) / (n * n * Legendre(n - 1, x) * Legendre(n - 1, x));
}

double sec_method(double x_i, double x_ii, double epsilon, int n, double a, double b) {
    double x_0, x_1, x_m, c_m;
    x_0 = x_i;
    x_1 = x_ii;
    x_m = x_1 - (Legendre(n, x_1) * (x_1 - x_0)) / (Legendre(n, x_1) - Legendre(n, x_0));
    while (abs(x_m - x_1) > epsilon) {
        x_0 = x_1;
        x_1 = x_m;
        x_m = x_1 - (Legendre(n, x_1) * (x_1 - x_0)) / (Legendre(n, x_1) - Legendre(n, x_0));
    }

    return x_m;
//    c_m = (b - a) * koeffs(n, x_m) / 2;
//    intgr += c_m * f_g(x_m);
//    cout << setprecision(12) << x_m << " " << setprecision(12) << c_m << endl;
}

void root_sep(double x_i, double x_ii, double epsilon, int n, double a, double b) {
    double h = (x_ii - x_i) / (10 * n);
    double x_1 = x_i;
    double x_2 = x_1 + h;
    double y_1 = Legendre(n, x_1);
    double y_2;
    double x_m;
    double c_m;
    double res = 0;
    while (x_2 <= x_ii) {
        y_2 = Legendre(n, x_2);
        if (y_1 * y_2 <= 0) {
            x_m = sec_method(x_1, x_2, epsilon, n, a, b);
            c_m = (b - a) * koeffs(n, x_m) / 2;
            x_m = (b - a) * x_m / 2 + (a + b) / 2;
            cout << "x_k = " << setprecision(12) << x_m << " <-> A_k = " << setprecision(12) << c_m << endl;
            res += c_m * f_g(x_m);
        }
        x_1 = x_2;
        x_2 = x_1 + h;
        y_1 = y_2;
    }
    if (a != -1)
        cout << "Полученное значение интеграла равно " << setprecision(12) << res << endl;
}

void Meler(int N) {
    double res = 0;
    for (int i = 1; i <= N; i++) {
        res += f_m(cos(((2 * i - 1) * M_PI) / (2 * N)));
        cout << "x_k = " << setprecision(12) << cos(((2 * i - 1) * M_PI) / (2 * N)) << " <-> A_k = " << setprecision(12) << M_PI / N << endl;
    }
    res *= M_PI / N;
    cout << "Полученное значение интеграла равно " << setprecision(12) << res << endl;
}

void root_sep_2(double x_i, double x_ii, double epsilon, int n, int m, double a, double b) {
    double h = (x_ii - x_i) / (10 * n);
    double x_1 = x_i;
    double x_2 = x_1 + h;
    double y_1 = Legendre(n, x_1);
    double y_2;
    double x_m;
    double c_m;
    double res = 0;
    double ans = 0;
    for (int j = 0; j < m; j++) {
        while (x_2 <= x_ii) {
            y_2 = Legendre(n, x_2);
            if (y_1 * y_2 <= 0) {
                x_m = sec_method(x_1, x_2, epsilon, n, a, b);
                c_m = koeffs(n, x_m) / 2;
                x_m = ((b - a) / m) * x_m + 2 * (a + j * ((b - a) / m) + ((b - a) / m)) / 2;
//                x_m = (b - a) * x_m / 2 + (a + b) / 2;
                cout << "x_k = " << setprecision(12) << x_m << " <-> A_k = " << setprecision(12) << c_m << endl;
                res += c_m * f_ff(x_m);
            }
            x_1 = x_2;
            x_2 = x_1 + h;
            y_1 = y_2;
        }
        ans += res;
        res = 0;
    }

    if (a != -1)
        cout << "Полученное значение интеграла равно " << setprecision(12) << ans * (b - a) / (2 * m) << endl;
}