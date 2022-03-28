#include "tasks.h"

void task_1() {
    cout << "ЧИСЛЕННЫЕ МЕТОДЫ РЕШЕНИЯ НЕЛИНЕЙНЫХ УРАВНЕНИЙ" << endl << endl
         << "f(x) = sin(x) + x^3 - 9x + 3" << endl;

    double A, B, epsilon;
    long long N = 10;

    cout << "Отрезок: ";
    cin >> A >> B;
    cout << "epsilon = ";
    cin >> epsilon;
    cout << endl;

    double h = (B - A) / N;
    root_separation(A, B, h, epsilon);

    cout << "Шалость удалась!";
}

void task_2() {
    cout << "ИНТЕРПОЛИРОВАНИЕ ПО ЗНАЧЕНИЯМ ФУНКЦИИ" << endl
         << "13-ый вариант" << endl;

    long long m, n;
    double a, b;
    cout << "Отрезок: ";
    cin >> a >> b;
    char key;
    cout << "Введите значение ключа: " << endl
         << "s - начать решение" << endl
         << "q - выйти из программы" << endl;

    cin >> key;
    while (key != 'q') {
        cout << "Введите число разбиений m = ";
        cin >> m;
        double h = (b - a) / m;
        table net;

        for (int i = 0; i <= m; i++) {
            net.knot.push_back(a + i * h);
            net.value.push_back(f(a + i * h));
        }

        cout << "Исходная таблица" << endl;
        for (int i = 0; i <= m; i++)
            cout << i << ") " << net.knot[i] << " | " << setprecision(15) << net.value[i] << endl;

        cout << "Введите точку интерполирования x = ";
        cin >> xx;
        cout << "Введите степень интерполяционного многочлена n, не более " << m << " ";
        cin >> n;
        while (n > m) {
            cout << endl
                 << "Введено недопустимое значение n" << endl
                 << "Введите другое n = ";
            cin >> n;
        }

        net.num = n;
        sort(net.knot.begin(), net.knot.end(), comp);
        for (int i = 0; i <= m; i++)
            net.value[i] = f(net.knot[i]);

        cout << endl
             << "Отсортированная таблица" << endl;
        for (int i = 0; i <= m; i++)
            cout << i << ") " << net.knot[i] << " | " << setprecision(15) << net.value[i] << endl;

        cout << endl << "ЛАГРАНЖ" << endl
             << "P_n(x) = " << setprecision(15) << Lagrange(xx, net) << endl
             << "|f(x) - P_n(x)| = " << setprecision(15) << abs(f(xx) - Lagrange(xx, net)) << endl;

        cout << endl << "НЬЮТОН" << endl
             << "P_n(x) = " << setprecision(15) << Newton(xx, net) << endl
             << "|f(x) - P_n(x)| = " << setprecision(15) << abs(f(xx) - Newton(xx, net)) << endl;

        cout << "Давайте прогоним еще раз! Согласны? Введите значение ключа. Напоминаю:" << endl
                << "s - решить еще раз" << endl
                << "q - выйти из программы" << endl;
        cin >> key;
    }
    cout << "Шалость удалась!";
}

void task_3_1() {
    cout << "ЗАДАЧА ОБРАТНОГО ИНТЕРПОЛИРОВАНИЯ" << endl
         << "13-ый вариант" << endl;

    long long m, n;
    double a, b, F, epsilon;

    cout << "Отрезок: ";
    cin >> a >> b;
    cout << "Введите число разбиений m = ";
    cin >> m;

    double h = (b - a) / m;
    table net;

    for (int i = 0; i <= m; i++) {
        net.knot.push_back(a + i * h);
        net.value.push_back(f(a + i * h));
    }

    cout << "Исходная таблица" << endl;
    for (int i = 0; i <= m; i++)
        cout << i << ") " << net.knot[i] << " | " << setprecision(15) << net.value[i] << endl;
    char key;
    cout << "Введите значение ключа:" << endl
         << "s - начать решение" << endl
         << "q - выйти из программы" << endl;
    cin >> key;
    while (key != 'q') {
        cout << "Введите значение, которое должно получиться: ";
        cin >> F;
        cout << "Введите степень интерполяционного многочлена n, не более " << m << " ";
        cin >> n;
        while (n > m) {
            cout << endl
                 << "Введено недопустимое значение n" << endl
                 << "Введите другое n = ";
            cin >> n;
        }
        net.num = m;
        cout << endl << "1-ый метод" << endl
             << "Q_n(F) = " << setprecision(15) << first_method(F, net, n) << endl
             << "|f(Q_n(F)) - F| = " << setprecision(15) << abs(f(first_method(F, net, n)) - F) << endl << endl;

        cout << "Для решения вторым способом введите epsilon = ";
        cin >> epsilon;

        cout << endl << "2-ой метод" << endl;
        second_method(F, net, epsilon);
        cout << "Давайте прогоним еще раз! Согласны? Введите значение ключа. Напоминаю:" << endl
             << "s - решить еще раз" << endl
             << "q - выйти из программы" << endl;
        cin >> key;
    }
    cout << "Шалость удалась!";
}

void task_3_2() {
    cout << "НАХОЖДЕНИЕ ПРОИЗВОДНЫХ ТАБЛИЧНО-ЗАДАННОЙ ФУНКЦИИ ПО ФОРМУЛАМ ЧИСЛЕННОГО ДИФФЕРЕНЦИРОВАНИЯ" << endl
         << "13-ый вариант" << endl
         << "f(x) = exp(6x)" << endl;

    char key;
    cout << "Введите значение ключа:" << endl
         << "s - начать решение" << endl
         << "q - выйти из программы" << endl;
    cin >> key;
    while (key != 'q') {
        long long m;
        cout << "Введите число разбиений m = ";
        cin >> m;
        double a, h;
        cout << "Введите точку начала отсчета a = ";
        cin >> a;
        cout << "Введите шаг h > 0 ";
        cin >> h;
        table net;
        net.num = m;
        for (int i = 0; i <= m; i++) {
            net.knot.push_back(a + i * h);
            net.value.push_back(exp(6 * (a + i * h)));
        }

        cout << "Исходная таблица" << endl;
        for (int i = 0; i <= m; i++)
            cout << i << ") " << net.knot[i] << " | " << setprecision(15) << net.value[i] << endl;
        cout << endl;

        differ(net, h);

        cout << "Давайте прогоним еще раз! Согласны? Введите значение ключа. Напоминаю:" << endl
             << "s - решить еще раз" << endl
             << "q - выйти из программы" << endl;
        cin >> key;
    }
    cout << "Шалость удалась!";
}

void task_4() {
    cout << "ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ ИНТЕГРАЛА ПО КВАДРАТУРНЫМ ФОРМУЛАМ" << endl;
//         << "13-ый вариант" << endl
//         << "f(x) = exp(6x)" << endl;

    double a, b;

    cout << "Отрезок: ";
    cin >> a >> b;
}