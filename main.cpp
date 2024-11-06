#include <iostream>
#include <iomanip>
// #include <locale>
#include <windows.h>

#include "Lab_1/Lab_1.cpp"
#include "Lab_2/Lab_2_1.cpp"
#include "Lab_2/Lab_2_2.cpp"
#include "Lab_3/Lab_3.cpp"
#include "Lab_4/Lab_4.cpp"
#include "Lab_5/Lab_5.cpp"
#include "Lab_6/Lab_6.cpp"
#include "Lab_7/Lab_7.cpp"
#include "Lab_8/Lab_8.cpp"
#include "Lab_9/Lab_9.cpp"
#include "Lab_10/Lab_10.cpp"


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
        case 4:
            lab_4();
            break;
        case 5:
            lab_5();
            break;
        case 6:
            lab_6();
            break;
        case 7:
            lab_7();
            break;
        case 8:
            lab_8();
            break;
        case 9:
            lab_9();
            break;
        case 10:
            lab_10();
            break;
        default:
            cout << "Помилка!" << endl;
    }
    return 0;
}