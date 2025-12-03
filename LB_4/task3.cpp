#include <iostream>
#include <clocale>
#include <windows.h>
#include <string>
#include <iomanip>
using namespace std;


void reverse() {
    int n;
    cout << "Введіть число: ";
    cin >> n;

    if (n == 0) {
        return;
    }
    else {
        reverse();
        cout << n << " ";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "Введіть числа (0 для кінця): ";
    reverse();
    return 0;
}