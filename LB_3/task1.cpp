#include <iostream>
#include <clocale>
#include <cmath>
#include <windows.h>
#include <string>
using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int max = 0;
    int sum = 0;

    int limit_a = 2;
    int limit_b = 10;
    int counter = 0;

    int len;
    cout << "Напишіть розмір масиву: ";
    if (!(cin >> len) || len<=0) {
        cout << "Некорректне значення розміру масиву" << endl;
        return 1;
    }

    int arr[len];
    for (int i = 0; i < len; i++) {
        cout<<"Введіть число для елементу масиву номер "<<i+1<<": ";
        if (!(cin >> arr[i])) {
            cout << "Некорректне значення" << endl;
            return 1;
        }

    }

    for (int i = 0; i < len; i++) {
        sum += arr[i];
        if (arr[i]>max) {
            max = arr[i];
            sum = 0;
        }
        if (limit_b>arr[i] && arr[i]>limit_a) {
            counter = counter + 1;
        }
    }
    cout<<"Сума елементів після максимального: "<<sum<<endl<<"Максимальний елемент: "<<max<<endl<<"Кількість елементів від А до Б: "<<counter<<endl;


    for (int i = 0; i < len; i++) {
        if (arr[i]<0) {
            arr[i] = -arr[i];
        }
    }

    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (arr[j]>arr[j+1]) {
                int num = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = num;
            }
        }
    }

    cout<<"Відсортований масив: ";
    for (int i = 0; i < len; ++i) {
        cout<<arr[i]<<" ";
    }
    return 0;
}