#include <iostream>
#include <clocale>
#include <cmath>
#include <windows.h>
#include <string>
using namespace std;

void fillArray(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << "Введіть число для елементу масиву номер " << i + 1 << ": ";
        while (!(cin >> arr[i])) {
            cout << "Некорректне значення! Спробуйте ще раз: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

void print_arr(int *arr, int len){
    for (int i = 0; i < len; ++i) {
        cout<<arr[i]<<" ";
    }
}

void make_absolute(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        if (arr[i] < 0) {
            arr[i] = -arr[i];
        }
    }
}

void bubble_sort(int *arr, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (arr[j]>arr[j+1]) {
                int num = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = num;
            }
        }
    }
}

int count_after_max(int *arr, int len, int* counter) {
    int max = 0;
    int sum = 0;

    int limit_a = 2;
    int limit_b = 10;


    for (int i = 0; i < len; i++) {
        sum += arr[i];
        if (arr[i]>max) {
            max = arr[i];
            sum = 0;
        }
        if (limit_b>arr[i] && arr[i]>limit_a) {
            *counter = *counter + 1;
        }
    }
    cout<<"Максимальний елемент: "<<max;
    return sum;

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int num = 1;
    int counter = 0;
    int len;
    cout << "Напишіть розмір масиву: ";
    if (!(cin >> len) || len<=0) {
        cout << "Некорректне значення розміру масиву" << endl;
        return 1;
    }

    int arr[len];
    fillArray(arr, len);

    int sum = count_after_max(arr, len, &counter);
    cout<<"Сума елементів після максимального: "<<sum<<endl<<endl<<"Кількість елементів від А до Б: "<<counter<<endl;

    make_absolute(arr, len);
    bubble_sort(arr, len);

    cout<<"Відсортований масив: ";
    print_arr(arr, len);

    return 0;
}