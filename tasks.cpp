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

void task_4_1() {
    cout << "ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ ИНТЕГРАЛА ПО КВАДРАТУРНЫМ ФОРМУЛАМ" << endl;

    double a, b;

    cout << "Отрезок: ";
    cin >> a >> b;

    double J;
    int integralchik;

    cout << "Какую функцию хотите интегрировать?" << endl
         << "-1: Легко интегрируемая функция sin(x) + exp(3 * x) - x" << endl
         << "0: Многочлен" << endl;
    cin >> integralchik;

    switch (integralchik) {
        case -1:
            J = integral(a, b, integralchik);

            cout << "Точное значение интеграла: " << setprecision(15) << J << endl << endl;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << left_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - left_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << right_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - right_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << mid_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - mid_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << trap(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - trap(a, b, integralchik)) << endl << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << Simpson(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - Simpson(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ 3/8" << endl
                 << "Значение интеграла: " << setprecision(15) << three_eights(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - three_eights(a, b, integralchik)) << endl
                 << endl;

            cout << "Шалость удалась!";
            break;
        case 0:
            cout << "Какой степени? ";
            cin >> integralchik;

            J = integral(a, b, integralchik);

            cout << "Точное значение интеграла: " << setprecision(15) << J << endl << endl;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << left_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - left_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << right_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - right_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << mid_rec(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - mid_rec(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << trap(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - trap(a, b, integralchik)) << endl << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << Simpson(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - Simpson(a, b, integralchik)) << endl
                 << endl;

            cout << "КФ 3/8" << endl
                 << "Значение интеграла: " << setprecision(15) << three_eights(a, b, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - three_eights(a, b, integralchik)) << endl
                 << endl;

            cout << "Шалость удалась!";
            break;
        default:
            cout << "Шалость удалась!";
    }
}

void task_4_2_3() {
    cout << "ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ ИНТЕГРАЛА ПО СОСТАВНЫМ КВАДРАТУРНЫМ ФОРМУЛАМ" << endl;

    double a, b;
    long long m, l;

    cout << "Введите пределы интегрирования: " << endl;
    cin >> a >> b;
    cout << "Введите число промежутков [" << a << ", " << b << "]" << endl;
    cin >> m;

    double h = (b - a) / m;
    double J;
    int integralchik;

    cout << "Какую функцию хотите интегрировать?" << endl
         << "-1: Легко интегрируемая функция sin(x) + exp(3 * x) - x" << endl
         << "0: Многочлен" << endl;
    cin >> integralchik;

    switch (integralchik) {
        case -1:
            J = integral(a, b, integralchik);

            cout << "Точное значение интеграла: " << setprecision(15) << J << endl << endl;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_left_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_left_rec(a, b, m, integralchik))
                 << endl
                 << "Теоретическая погрешность: " << setprecision(15)
                 << 0.5 * (b - a) * h * maximo(a, b, m, 0, integralchik) << endl << endl;

            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_right_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_right_rec(a, b, m, integralchik))
                 << endl
                 << "Теоретическая погрешность: " << setprecision(15)
                 << 0.5 * (b - a) * h * maximo(a, b, m, 0, integralchik) << endl << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_mid_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_mid_rec(a, b, m, integralchik))
                 << endl
                 << "Теоретическая погрешность: " << setprecision(15)
                 << (b - a) * h * h * maximo(a, b, m, 1, integralchik) / 24 << endl << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << com_trap(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_trap(a, b, m, integralchik)) << endl
                 << "Теоретическая погрешность: " << setprecision(15)
                 << (b - a) * h * h * maximo(a, b, m, 1, integralchik) / 12 << endl << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << com_Simpson(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_Simpson(a, b, m, integralchik))
                 << endl
                 << "Теоретическая погрешность: " << setprecision(15)
                 << (b - a) * h * h * h * h * maximo(a, b, m, 3, integralchik) / 2880 << endl << endl;

            cout << "Теперь приступим к заданию 4.3" << endl
                 << "Введите l: ";
            cin >> l;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_left_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_left_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_left_rec(a, b, m, integralchik), com_left_rec(a, b, m * l, integralchik), l, 0))
                 << endl << endl;


            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_right_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_right_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_right_rec(a, b, m, integralchik), com_right_rec(a, b, m * l, integralchik), l, 0))
                 << endl << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_mid_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_mid_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_mid_rec(a, b, m, integralchik), com_mid_rec(a, b, m * l, integralchik), l, 1))
                 << endl << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << com_trap(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_trap(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_trap(a, b, m, integralchik), com_trap(a, b, m * l, integralchik), l, 1)) << endl
                 << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << com_Simpson(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_Simpson(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_Simpson(a, b, m, integralchik), com_Simpson(a, b, m * l, integralchik), l, 3))
                 << endl << endl;

            cout << "Шалость удалась!";
            break;
        case 0:
            cout << "Какой степени? ";
            cin >> integralchik;

            J = integral(a, b, integralchik);
            cout << "Точное значение интеграла: " << setprecision(15) << J << endl << endl;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_left_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_left_rec(a, b, m, integralchik))
                 << endl << endl;

            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_right_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_right_rec(a, b, m, integralchik))
                 << endl << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_mid_rec(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_mid_rec(a, b, m, integralchik))
                 << endl << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << com_trap(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_trap(a, b, m, integralchik)) << endl
                 << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << com_Simpson(a, b, m, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_Simpson(a, b, m, integralchik))
                 << endl << endl;

            cout << "Теперь приступим к заданию 4.3" << endl
                 << "Введите l: ";
            cin >> l;

            cout << "КФ левого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_left_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_left_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_left_rec(a, b, m, integralchik), com_left_rec(a, b, m * l, integralchik), l, 0))
                 << endl << endl;

            cout << "КФ правого прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_right_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_right_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_right_rec(a, b, m, integralchik), com_right_rec(a, b, m * l, integralchik), l, 0))
                 << endl << endl;

            cout << "КФ среднего прямоугольника" << endl
                 << "Значение интеграла: " << setprecision(15) << com_mid_rec(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_mid_rec(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_mid_rec(a, b, m, integralchik), com_mid_rec(a, b, m * l, integralchik), l, 1))
                 << endl << endl;

            cout << "КФ трапеции" << endl
                 << "Значение интеграла: " << setprecision(15) << com_trap(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_trap(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_trap(a, b, m, integralchik), com_trap(a, b, m * l, integralchik), l, 1)) << endl
                 << endl;

            cout << "КФ Симпсона" << endl
                 << "Значение интеграла: " << setprecision(15) << com_Simpson(a, b, m * l, integralchik) << endl
                 << "Абсолютная погрешность: " << setprecision(15) << abs(J - com_Simpson(a, b, m * l, integralchik))
                 << endl
                 << "Погрешность для уточненных значений: " << setprecision(15)
                 << abs(J - runge(com_Simpson(a, b, m, integralchik), com_Simpson(a, b, m * l, integralchik), l, 3))
                 << endl << endl;

            cout << "Шалость удалась!";
            break;
        default:
            cout << "Шалость удалась!";
    }
}

void task_5() {
    cout << "ВЫЧИСЛЕНИЕ ИНТЕГРАЛОВ ПРИ ПОМОЩИ КВАДРАТУРНЫХ ФОРМУЛ НАИВЫСШЕЙ АЛГЕБРАИЧЕСКОЙ СТЕПЕНИ ТОЧНОСТИ" << endl;

    double a, b, n;
    double epsilon = 0.000000000001;
    cout << "Перейдем к нахождению интеграла при помощи квадратурной формулы Гаусса" << endl;
    char key;
    cout << "Введите значение ключа:" << endl
         << "s - начать решение" << endl
         << "q - выйти из программы" << endl;
    cin >> key;
    while (key != 'q') {
        cout << "Введите N: ";
        cin >> n;
        root_sep(-1, 1, epsilon, n, -1, 1);
        cout << "Введите пределы интегрирования: " << endl;
        cin >> a >> b;
        root_sep(-1, 1, epsilon, n, a, b);
        cout << "Давайте прогоним еще раз! Согласны? Введите значение ключа. Напоминаю:" << endl
             << "s - решить еще раз" << endl
             << "q - выйти из программы" << endl;
        cin >> key;
    }


    cout << "Теперь перейдем к нахождению интеграла при помощи квадратурной формулы Мелера" << endl;
    int N_1, N_2, N_3;
    cout << "Введите количество узлов N_1, N_2, N_3" << endl
         << "N_1 = ";
    cin >> N_1;
    cout << "N_2 = ";
    cin >> N_2;
    cout << "N_3 = ";
    cin >> N_3;
    cout << "Для N_1 = " << N_1 << " получаем следующее:" << endl;
    Meler(N_1);
    cout << endl;
    cout << "Для N_2 = " << N_2 << " получаем следующее:" << endl;
    Meler(N_2);
    cout << endl;
    cout << "Для N_3 = " << N_3 << " получаем следующее:" << endl;
    Meler(N_3);
    cout << "Шалость удалась!";
}

void task_6() {
    cout << "ПРИБЛИЖЕННОЕ ВЫЧИСЛЕНИЕ ИНТЕГРАЛОВ ПРИ ПОМОЩИ КВАДРАТУРНЫХ ФОРМУЛ НАИВЫСШЕЙ АЛГЕБРАИЧЕСКОЙ СТЕПЕНИ ТОЧНОСТИ" << endl;

    double a, b, n, m;
    double epsilon = 0.000000000001;
    char key;
    cout << "Введите значение ключа:" << endl
         << "s - начать решение" << endl
         << "q - выйти из программы" << endl;
    cin >> key;
    while (key != 'q') {
        cout << "Введите N: ";
        cin >> n;
        cout << "Введите m: ";
        cin >> m;
        root_sep(-1, 1, epsilon, n, -1, 1);
        cout << "Введите пределы интегрирования: " << endl;
        cin >> a >> b;
        root_sep_2(-1, 1, epsilon, n, m, a, b);
        cout << endl;
        calc(a, b, m);
        cout << "Давайте прогоним еще раз! Согласны? Введите значение ключа. Напоминаю:" << endl
             << "s - решить еще раз" << endl
             << "q - выйти из программы" << endl;
        cin >> key;
    }
}