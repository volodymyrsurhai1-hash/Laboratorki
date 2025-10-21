#include <iostream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    map<string, int> day_to_int = {
        {"понеділок", 0}, {"вівторок", 1}, {"середа", 2},
        {"четвер", 3}, {"п'ятниця", 4}, {"субота", 5}, {"неділя", 6}
    };

    string current_day_name;
    int k_days;
    cout<<"Введіть назву дня тижня: ";
    cin >> current_day_name;
    cout<<"Введіть k-днів: ";
    cin >> k_days;

    current_day_name = tolower(current_day_name[0]);
    if (day_to_int.count(current_day_name) <= 0 ) {
        cout << "Не правильно написаний день тижня";
        return k_days;
    }

    int current_day_index = day_to_int[current_day_name];
    int new_day_index = (current_day_index + k_days) % 7;
    string new_day_name;

    switch (new_day_index) {
        case 0:
            new_day_name = "Понеділок";
            break;
        case 1:
            new_day_name = "Вівторок";
            break;
        case 2:
            new_day_name = "Середа";
            break;
        case 3:
            new_day_name = "Четвер";
            break;
        case 4:
            new_day_name = "П'ятниця";
            break;
        case 5:
            new_day_name = "Субота";
            break;
        case 6:
            new_day_name = "Неділя";
            break;
    }
    cout << "День тижня через " << k_days << " днів буде: " << new_day_name << endl;
    return 0;
}