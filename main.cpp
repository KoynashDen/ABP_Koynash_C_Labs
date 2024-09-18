#include <iostream>
#include <iomanip>
// #include <locale>
#include <windows.h>

#include "Lab_1/Lab_1.cpp"

using namespace std;

int main() {
    // setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(CP_UTF8);

    int numberLabolatorka;
    cout << "Введіть номер лабораторки: " << endl;
    cin >> numberLabolatorka;

    switch (numberLabolatorka) {
        case 1:
            lab_1();
        break;
        default:
            cout << "Помилка!" << endl;
    }
    return 0;
}