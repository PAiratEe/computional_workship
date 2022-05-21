#include "lib.h"

double f_g(double x) {
    return sqrt(x) * pow(exp(1), x * x);
}

double f_m(double x) {
    return log(2 + x) / (1 + x * x * x);
}

double f_ff(double x) {
    return sin(x) * exp(-x);
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

double sec_method(double x_i, double x_ii, double epsilon, int n) {
    double x_0, x_1, x_m;
    x_0 = x_i;
    x_1 = x_ii;
    x_m = x_1 - (Legendre(n, x_1) * (x_1 - x_0)) / (Legendre(n, x_1) - Legendre(n, x_0));
    while (abs(x_m - x_1) > epsilon) {
        x_0 = x_1;
        x_1 = x_m;
        x_m = x_1 - (Legendre(n, x_1) * (x_1 - x_0)) / (Legendre(n, x_1) - Legendre(n, x_0));
    }

    return x_m;
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
            x_m = sec_method(x_1, x_2, epsilon, n);
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
    double h_1 = (b - a) / m;
    double x_1;// = x_i;
    double x_2;// = x_1 + h;
    double y_1;// = Legendre(n, x_1);
    double y_2;
    double x_m;
    double x_temp;
    double c_m;
    double res = 0;

    for (int j = 0; j < m; j++) {
        x_1 = x_i;
        x_2 = x_1 + h;
        y_1 = Legendre(n, x_1);
        while (x_2 <= x_ii) {
            y_2 = Legendre(n, x_2);
            if (y_1 * y_2 <= 0) {
                x_m = sec_method(x_1, x_2, epsilon, n);
                c_m = koeffs(n, x_m);
                x_temp = (h_1 * x_m + 2 * (a + j * h_1) + h_1) / 2;
                res += c_m * f_ff(x_temp);
            }
            x_1 = x_2;
            x_2 = x_1 + h;
            y_1 = y_2;
        }

    }

    if (a != -1)
        cout << "Полученное значение интеграла равно " << setprecision(12) << res * h_1 / 2 << endl;
}

double secc_method(double A, double B, double epsilon, double p, double q) {
    double x_0, x_1, x_m;
    x_0 = A;
    x_1 = B;
    x_m = x_1 - ((x_1 * x_1 + p * x_1 + q) * (x_1 - x_0)) / ((x_1 * x_1 + p * x_1 + q) - (x_0 * x_0 + p * x_0 + q));
    while (abs(x_m - x_1) > epsilon) {
        x_0 = x_1;
        x_1 = x_m;
        x_m = x_1 - ((x_1 * x_1 + p * x_1 + q) * (x_1 - x_0)) / ((x_1 * x_1 + p * x_1 + q) - (x_0 * x_0 + p * x_0 + q));
    }
    return x_m;
}

void r_s(double A, double B, int m, double epsilon, double p, double q) {
    double h = (B - A) / m;
    double x_1 = A;
    double x_2 = x_1 + h;
    double y_1 = x_1 * x_1 + p * x_1 + q;
    double y_2;
    vector<double> x_m;
    while (x_2 <= B) {
        y_2 = x_2 * x_2 + p * x_2 + q;
        if (y_1 * y_2 <= 0) {
            x_m.push_back(secc_method(x_1, x_2, epsilon, p, q));
        }
        x_1 = x_2;
        x_2 = x_1 + h;
        y_1 = y_2;
    }
    double mu_0 = com_mid_rec(A, B, m, 0);
    double mu_1 = com_mid_rec(A, B, m, 1);
    double A_1 = (mu_0 * x_m[1] - mu_1) / (x_m[1] - x_m[0]);
    double A_2 = (mu_1 - mu_0 * x_m[0]) / (x_m[1] - x_m[0]);
//    cout << A_1 << " + " << A_2 << " = " << A_1 + A_2 << " " << mu_0 << endl;
//    cout << A_1 << " * " << x_m[0] << " + " <<  A_2 << " * " << x_m[1] << " = " << A_1 * x_m[0] + A_2 * x_m[1] << " " << mu_1 << endl;
    cout << x_m[0] << " " << x_m[1] << endl;
    cout << A_1 << " " << A_2 << endl;
    cout << A_1 * sin(x_m[0]) + A_2 * sin(x_m[1]) << endl;
}

void calc(double a, double b, int m) {
    double mu_0 = com_mid_rec(a, b, m, 0);
    double mu_1 = com_mid_rec(a, b, m, 1);
    double mu_2 = com_mid_rec(a, b, m, 2);
    double mu_3 = com_mid_rec(a, b, m, 3);
    double p = (-mu_2 * mu_1 + mu_3 * mu_0) / (mu_1 * mu_1 - mu_0 * mu_2);
    double q = (-mu_3 * mu_1 + mu_2 * mu_2) / (mu_1 * mu_1 - mu_0 * mu_2);
//    cout << mu_2 + p * mu_1 + q * mu_0 << endl;
//    cout << mu_3 + p * mu_2 + q * mu_1 << endl;
    cout << mu_0 << " " << mu_1 << " " << mu_2 << " " << mu_3 << endl;
    cout << "x^2 + (" << p << ") * x + " << q << endl;
    r_s(a, b, m, 0.000000000001, p, q);
}