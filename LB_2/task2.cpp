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

    for (int i = 1; i <= 10; i++)
    {
        cout << "\n--- Постріл " << i << " ---\n";
        cout<<"Введіть значення х:";
        if (!(cin>>x)){
            cout<<"Неправильні вхідні дані!";
            return 1;
        }
        cout<<"Введіть значення y:";
        if (!(cin>>y)){
            cout<<"Неправильні вхідні дані!";
            return 1;
        }

        d = sqrt(pow(x,2)+pow(y,2));

        if (x<=0 && y>=0) {
            if (d<r1) {
                cout<<"Влучання!"<<endl;
                continue;
            }

            cout<<"Мимо!"<<endl;
            continue;
        }

        if (x>=0 && y<=0) {
            if (d>=r1 && d<=r2) {
                cout<<"Влучання!"<<endl;
                continue;
            }

            cout<<"Мимо!"<<endl;
            continue;
        }

        cout<<"Мимо!"<<endl;

    }

}