
//
// Created by Denys on 09.10.2024.
//

#include "Lab_7.h"
#include <iostream>
#include <cstring>

using namespace std;


struct Office {
    char name[20];
    char creator[20];
    int count;
    int cost;
};


void inputOffices(Office offices[], int& n) {
    n = 0;
    while (n < 10) {
        cout << "Введіть найменування, виробника, кількість пакетів, вартість " << n + 1 << " (введіть '***' для завершення):" << endl;
        cin >> offices[n].name;


        if (strcmp(offices[n].name, "***") == 0) {
            break;
        }

        cin >> offices[n].creator >> offices[n].count >> offices[n].cost;
        n++;
    }
}


void printOffices(Office offices[], int n) {

    cout << "-------------------------------------------------------\n";
    cout << "|                   Офісні пакети                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменування | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";
    for (int i = 0; i < n; i++) {
        cout << "|" << setw(14) << offices[i].name << "|" << setw(10) << offices[i].creator << "|" << setw(11)
             << offices[i].count << "|" << setw(15) << offices[i].cost << "|" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

void sortOffices(Office offices[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(offices[j].name, offices[minIndex].name) < 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            Office temp = offices[i];
            offices[i] = offices[minIndex];
            offices[minIndex] = temp;
        }
    }
}

int lab_7() {
    Office offices[10];
    int n;

    inputOffices(offices, n);

    cout << "Таблиця до сортування:\n";
    printOffices(offices, n);


    sortOffices(offices, n);


    cout << "Таблиця після сортування за назвою:\n";
    printOffices(offices, n);

    return 0;
}