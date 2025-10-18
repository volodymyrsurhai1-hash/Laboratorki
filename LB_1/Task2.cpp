#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    int a, b, c;
    SetConsoleOutputCP(CP_UTF8);
    cout << "Напишіть число а : ";
    cin >> a;
    cout << "Напишіть число b : ";
    cin >> b;
    cout << "Напишіть число c : ";
    cin >> c;

    if (a >= b && a <= c && b >= 3 && c >= 3) {
        std::cout << "Належить" << std::endl;
    } else {
        std::cout << "НЕ належить" << std::endl;
    }

    return 0;
}