#include <iostream>
#include <cmath>

double f(double x) {
    return pow(sin(x), 2) - 3 * cos(x);
}

double secantMethod(double a, double b, double epsilon) {
    double x0 = a;
    double x1 = b;
    double x2;
    double f0 = f(x0);
    double f1 = f(x1);

    while (std::abs(f1) > epsilon) {
        if (std::abs(f0 - f1) < epsilon) {
            std::cout << "Недостаточная сходимость." << std::endl;
            return NAN;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        x0 = x1;
        f0 = f1;

        x1 = x2;
        f1 = f(x1);
    }

    return x1;
}

int main() {
    setlocale(LC_ALL, "ru");
    double a, b;
    std::cout << "Введите начало отрезка [a]: ";
    std::cin >> a;
    std::cout << "Введите конец отрезка [b]: ";
    std::cin >> b;

    double epsilon;
    std::cout << "Введите точность epsilon: ";
    std::cin >> epsilon;

    std::cout << "Поиск корней функции f(x) = sin(x)^2 - 3cos(x) на отрезке [" << a << ", " << b << "]" << std::endl;

    double x = a;
    while (x < b) {
        double root = secantMethod(x, x + 1, epsilon);
        if (!std::isnan(root)) {
            std::cout << "Корень: " << root << std::endl;
        }
        x += 1;
    }

    return 0;
}
