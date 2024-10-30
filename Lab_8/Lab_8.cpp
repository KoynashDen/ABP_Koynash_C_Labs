//
// Created by Denys on 09.10.2024.
//

#include "Lab_8.h"
#include <iostream>
#include <cstring>
#include <stack>
#include <iomanip>


using namespace std;


struct Offices{
    char name[20];
    char creator[20];
    int count;
    int cost;
};



void inputOffices(stack<Offices>& officeStack) {
    Offices office;
    int n = 0;
    while (n < 10) {
        cout << "Введіть найменування, виробника, кількість пакетів, вартість " << n + 1 << " (введіть '***' для завершення):" << endl;
        cin >> office.name;


        if (strcmp(office.name, "***") == 0) {
            break;
        }

        cin >> office.creator >> office.count >> office.cost;
        officeStack.push(office);
        n++;

    }
}


void printOffices(stack<Offices>& officeStack) {

    cout << "-------------------------------------------------------\n";
    cout << "|                   Офісні пакети                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменування | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";
    while(!officeStack.empty()) {
        Offices office = officeStack.top();
        officeStack.pop();
        cout << "|" << setw(14) << office.name << "|" << setw(10) << office.creator << "|" << setw(11)
             << office.count << "|" << setw(15) << office.cost << "|" << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}



int lab_8() {
    stack<Offices> officeStack;

    int n;

    inputOffices(officeStack);

    cout << "Таблиця до сортування:\n";
    printOffices(officeStack);


    // cout << "Таблиця після сортування за назвою:\n";
    // printOffices(offices, n);

    return 0;
}

