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
    int h;


    cout << "Введіть значення а: ";
    cin >> a;
    cout << "Введіть значення b: ";
    cin >> b;
    cout << "Введіть крок : ";
    cin >> h;

    if (h<=0) {
        cout << "Некорректне значення h";
        return 1;
    }
    cout << "Усі значення функції на проміжку від a до b: \n";

    for (int x = a; x<=b; x+=h) {
        if (x < -3) {
            // Ділянка 1: Пряма (y = x + 3)
            y = x + 3;
        }
        else if (x >= -3 && x <= 0) {
            // Ділянка 2: Верхнє півколо (центр 0,0, R=3)
            y = sqrt(9 - x * x);
        }
        else if (x > 0 && x <= 6) {
            // Ділянка 3: Пряма (y = -0.5x + 3)
            y = -0.5 * x + 3;
        }
        else if (x > 6) {
            // Ділянка 4: Пряма (y = x - 6)
            y = x - 6;
        }
        else {
            // Якщо x знаходиться поза визначеними ділянками
            y = NAN; // Not a Number (не визначено)
        }
        cout << "x: " << x << "  |  y: " << y << endl;
    }
}
