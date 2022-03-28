#include "lib.h"

double f_f(double x) {    // возвращает значение функции
    return sin(x) + x * x * x - 9 * x + 3;
}

double df_f(double x) {   // возвращает значение производной
    return cos(x) + 3 * x * x - 9;
}

double d2f_f(double x) {  // возвращает значение второй производной
    return -sin(x) + 6 * x;
}

void bisection_method(double A, double B, double epsilon) {
    cout << "МЕТОД БИСЕКЦИИ" << endl;

    int counter = 0;
    while (B - A > 2 * epsilon) {
        double C = (A + B) / 2;
        if (f_f(A) * f_f(C) <= 0)
            B = C;
        else
            A = C;
        counter++;
    }
    double x = (A + B) / 2;
    double delta = (B - A) / 2;

    cout << "Количество шагов: " << setprecision(12) << counter << endl
         << "Приближенное решение: " << x << endl
         << "x_{m} - x_{m - 1}: " << delta << endl
         << "Абсолютная величина невязки: " << abs(f_f(x) - 0) << endl << endl;
}

void newton_method(double A, double B, double epsilon) {
    cout << "МЕТОД НЬЮТОНА" << endl;

    double x_0, x_m;
    int counter = 0;
    if (f_f(A) * f_f(B) < 0) {
        if (f_f(A) * d2f_f(A) > 0)
            x_0 = A;
        else
            x_0 = B;
        x_m = x_0 - f_f(x_0) / df_f(x_0);
        counter++;
        while (abs(x_0 - x_m) > epsilon) {
            x_0 = x_m;
            x_m = x_0 - f_f(x_0) / df_f(x_0);
            counter++;
        }
    }
    else
        cout << "Нет корней" << endl;
    double delta = x_m - x_0;

    cout << "Количество шагов: " << counter << endl
         << "Приближенное решение: " << setprecision(12) << x_m << endl
         << "x_{m} - x_{m - 1}: " << delta << endl
         << "Абсолютная величина невязки: " << abs(f_f(x_m) - 0) << endl << endl;
}

void modified_newton_method(double A, double B, double epsilon) {
    cout << "МОДИФИЦИРОВАННЫЙ МЕТОД НЬЮТОНА" << endl;

    double x_0, x_m;
    int counter = 0;
    if (f_f(A) * f_f(B) < 0) {
        if (f_f(A) * d2f_f(A) > 0)
            x_0 = A;
        else
            x_0 = B;
        double df_x_0 = df_f(x_0);
        x_m = x_0 - f_f(x_0) / df_x_0;
        counter++;
        while (abs(x_0 - x_m) > epsilon) {
            x_0 = x_m;
            x_m = x_0 - f_f(x_0) / df_x_0;
            counter++;
        }
    }
    else
        cout << "Нет корней" << endl;
    double delta = x_m - x_0;

    cout << "Количество шагов: " << counter << endl
         << "Приближенное решение: " << setprecision(12) << x_m << endl
         << "x_{m} - x_{m - 1}: " << delta << endl
         << "Абсолютная величина невязки: " << abs(f_f(x_m) - 0) << endl << endl;
}

void secant_method(double A, double B, double epsilon) {
    cout << "МЕТОД СЕКУЩИХ" << endl;

    double x_0, x_1, x_m;
    int counter = 0;
    x_0 = A;
    x_1 = B;
    x_m = x_1 - (f_f(x_1) * (x_1 - x_0)) / (f_f(x_1) - f_f(x_0));
    counter++;
    while (abs(x_m - x_1) > epsilon) {
        x_0 = x_1;
        x_1 = x_m;
        x_m = x_1 - (f_f(x_1) * (x_1 - x_0)) / (f_f(x_1) - f_f(x_0));
        counter++;
    }
    double delta = x_m - x_1;

    cout << "Количество шагов: " << counter << endl
         << "Приближенное решение: " << setprecision(12) << x_m << endl
         << "x_{m} - x_{m - 1}: " << delta << endl
         << "Абсолютная величина невязки: " << abs(f_f(x_m) - 0) << endl << endl;
}

void root_separation(double A, double B, double h, double epsilon) {    // процедура отделения корней
    int counter = 0;
    double x_1 = A;
    double x_2 = x_1 + h;
    double y_1 = f_f(x_1);
    double y_2;
    while (x_2 <= B) {
        y_2 = f_f(x_2);
        if (y_1 * y_2 <= 0) {
            counter++;
            cout << counter << "-й отрезок: " << "[" << x_1 << ";" << x_2 << "]" << endl;
            bisection_method(x_1, x_2, epsilon);
            newton_method(x_1, x_2, epsilon);
            modified_newton_method(x_1, x_2, epsilon);
            secant_method(x_1, x_2, epsilon);
        }
        x_1 = x_2;
        x_2 = x_1 + h;
        y_1 = y_2;
    }

    cout << "Количество отрезков = " << counter << endl;
}