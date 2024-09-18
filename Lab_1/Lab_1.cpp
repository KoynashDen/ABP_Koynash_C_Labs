//
// Created by Denys on 18.09.2024.
//
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Lab_1.h"
using namespace std;

int lab_1() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    char name1[20], name2[20], name3[20];
    int cnt1, cnt2, cnt3;
    char creator1[20], creator2[20], creator3[20];

    int cost1, cost2, cost3;

    cout << "1. Введіть найменування, виробника, кількість, вартість (латинськими):" << endl;
    cin >> name1 >> creator1 >> cnt1 >> cost1;
    cout << "2. Введіть найменування, виробника, кількість, вартість (латинськими):" << endl;
    cin >> name2 >> creator2 >> cnt2 >> cost2;
    cout << "3. Введіть найменування, виробника, кількість, вартість (латинськими):" << endl;
    cin >> name3 >> creator3 >> cnt3 >> cost3;

    cout << "-------------------------------------------------------\n";
    cout << "|                   Офісні пакети                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменування | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";

    cout << "|" << setw(14) << name1 << "|" << setw(10) << creator1 << "|" << setw(11) << cnt1
    << "|" << setw(14) << fixed << setprecision(1) << setw(15) << cost1 << "|" << endl;
    cout << "|" << setw(14) << name2 << "|" << setw(10) << creator2 << "|" << setw(11) << cnt2
    << "|" << setw(14) << fixed << setprecision(1) << setw(15) << cost2 << "|" << endl;
    cout << "|" << setw(14) << name3 << "|" << setw(10) << creator3 << "|" << setw(11) << cnt3
    << "|" << setw(14) << fixed << setprecision(1) << setw(15) << cost3 << "|" << endl;

    cout << "|-----------------------------------------------------|" << endl;
    cout << "| Примітка: можна безкоштовно отримати продукт        |" << endl;
    cout << "| StarOffice через Internet                           |" << endl;
    cout << "-------------------------------------------------------" << endl;

    return 0;

};
