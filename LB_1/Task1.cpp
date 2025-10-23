#include <iostream>
#include <clocale>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");
    float a;
    float b;
    float h;
    float deg;
    float square;

    cout << "Введіть сторону а:";
    cin >> a;
    cout << "Введіть сторону b:";
    cin >> b;
    cout << "Введіть кут:";
    cin >> deg;

    if (a<=0 || b <= 0 || deg <= 0) {
        cout << " Неможливо обрахувати площу!";
        return 1;
    }

    float maxSide = max(a,b);
    float minSide = min(a,b);
    h = ((maxSide - minSide)/2)*tan((deg)*(M_PI/180));
    square=((a+b)/2) * h;

    std::cout << "Площа:"<<square;

}