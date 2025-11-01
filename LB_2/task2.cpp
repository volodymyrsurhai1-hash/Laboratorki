#include <iostream>
#include <clocale>
#include <cmath>
#include <windows.h>
using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    float x;
    float y;
    float d;

    int r1 = 5;
    int r2 = 7;

    cout<<"Введіть значення х:";
    cin>>x;
    cout<<"Введіть значення y:";
    cin>>y;

    d = sqrt(pow(x,2)+pow(y,2));

    if (x<=0 && y>=0) {
        if (d<r1) {
            cout<<"Влучання!";
        }
        else {
            cout<<"Мимо!";
        }
    }
    else if (x>=0 && y<=0) {
        if (d>r2, d<10) {
            cout<<"Влучання!";
        }
        else {
            cout<<"Мимо!";
        }
    }
    else {
        cout<<"Мимо!";
    }

}