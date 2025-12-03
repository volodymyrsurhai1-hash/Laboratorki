#include <iostream>
#include <clocale>
#include <windows.h>
#include <string>
#include <iomanip>


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int a;
    int b;

    cout<<"Введіть кількість рядків: ";
    if (!(cin>>a) || a <= 0) {
        cout << "Некоректне значення" << endl;
        return 1; // Виходимо, якщо розмір поганий
    }
    cout<<"Введіть кількість стовпців: ";
    if (!(cin>>b) || b <= 0) {
        cout << "Некоректне значення" << endl;
        return 1;
    }

    int arr[a][b];
    cout << "\n--- Заповнення матриці ---\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "Введіть елемент [" << i << "][" << j << "]: ";
            if (!(cin >> arr[i][j])) {
                cout << "Помилка!";
                cin.clear();
                return 1;
            }
        }
    }

    cout << "\n--- Ваша матриця ---" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------------------\n";


    int firstPositiveColumn = -1;

    for (int j = 0; j < b; j++) {
        bool hasNegative = false;
        for (int i = 0; i < a; i++) {
            if (arr[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative == false) {

            cout << "  ЗНАЙДЕНО! Стовпець " << j << " - перший, де немає від'ємних чисел.\n";
            firstPositiveColumn = j;
            break;
        }
    }

    int row_frequencies[a];

    for (int i = 0; i < a; i++) {
        int max_freq_in_row = 0;
        for (int j = 0; j < b; j++) {
            int current_element = arr[i][j];
            int current_freq = 0;
            for (int k = 0; k < b; k++) {
                if (arr[i][k] == current_element) {
                    current_freq++;
                }
            }
            if (current_freq > max_freq_in_row) {
                max_freq_in_row = current_freq;
            }
        }
        if (b > 0 && max_freq_in_row == 0) {
            max_freq_in_row = 1;
        }
        row_frequencies[i] = max_freq_in_row;

    }


    for (int i = 0; i < a - 1; i++) {
        for (int j = 0; j < a - 1 - i; j++) {


            if (row_frequencies[j] > row_frequencies[j + 1]) {


                int temp_freq = row_frequencies[j];
                row_frequencies[j] = row_frequencies[j + 1];
                row_frequencies[j + 1] = temp_freq;


                for (int k = 0; k < b; k++) {
                    int num = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = num;
                }
            }
        }
    }
    

    cout << "\n--- ВІДСОРТОВАНА матриця ---" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << setw(6) << arr[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\n--- Результат Частини 2 (Пошук стовпця) ---\n";
    if (firstPositiveColumn != -1) {
        cout << "Номер першого стовпця без від'ємних елементів: " << firstPositiveColumn << endl;
    } else {
        cout << "Такого стовпця не знайдено." << endl;
    }

    return 0;
}