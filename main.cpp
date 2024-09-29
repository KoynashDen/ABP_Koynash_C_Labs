#include <iostream>
#include <iomanip>
// #include <locale>
#include <windows.h>

#include "Lab_1/Lab_1.cpp"
#include "Lab_2/Lab_2_1.cpp"
#include "Lab_2/Lab_2_2.cpp"
#include "Lab_3/Lab_3.cpp"


using namespace std;

int main() {
    // setlocale(LC_ALL, "ukr");
    SetConsoleOutputCP(CP_UTF8);

    int numberLabolatorka;
    int numberLabolatorka_2;
    cout << "Введіть номер лабораторки: " << endl;
    cin >> numberLabolatorka;

    switch (numberLabolatorka) {
        case 1:
            lab_1();
        break;
        case 2:
            cout << "Введіть номер ДРУГОЇ лаболаторки: " << endl;
            cin >> numberLabolatorka_2;
            switch (numberLabolatorka_2) {
                case 1:
                    lab_2_1();
                    break;
                case 2:
                    lab_2_2();
                    break;
                default:
                    cout << "Помилка";

            }
            break;
        case 3:
            lab_3();
            break;
        default:
            cout << "Помилка!" << endl;
    }
    return 0;
}