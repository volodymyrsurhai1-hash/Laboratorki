#include <iostream>
#include <clocale>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    float y;

    float a;
    float b;
    float h;


    cout << "Введіть значення а: ";
    if (!(cin >> a)) {
        cout<< "Введіть корректні значення!";
        return 1;
    }
    cout << "Введіть значення b: ";
    if (!(cin >> b)) {
        cout<< "Введіть корректні значення!";
        return 1;
    }
    cout << "Введіть крок : ";
    if (!(cin >> h)) {
        cout<< "Введіть корректні значення!";
        return 1;
    }

    if (h<=0) {
        cout << "Некорректне значення h";
        return 1;
    }
    cout << "Усі значення функції на проміжку від a до b: \n";

    for (float x = a; x<=b; x+=h) {
        if (x < -3) {
            y = x + 3;
        }
        else if (x >= -3 && x <= 0) {
            y = sqrt(9 - x * x);
        }
        else if (x > 0 && x <= 6) {
            y = -0.5 * x + 3;
        }
        else if (x > 6) {
            y = x - 6;
        }
        else {
            y = NAN;
        }
        cout << "x: " << x << "  |  y: " << y << endl;
    }
}
