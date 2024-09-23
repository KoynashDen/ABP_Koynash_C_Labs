//
// Created by Denys on 23.09.2024.
//
#include <cmath>

#include "Lab_2_2.h"
#include <iostream>
#include <iomanip>

double calculate_example(long n) {
    return pow(-1,n) * ((n+1) / pow(2,n-1));
}


int lab_2_2() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    long n=0;
    double sum = 0.0;
    const double eps = 0.000001;
    double term;

    while (true) {
        term = calculate_example(n);

        if (n==10) {
            cout << "Сума 10 членів ряду = " << sum << endl;
        }
        if (fabs(term)<eps) {
            break;
        }
        sum += term;
        n++;
    }
    cout << "Повна сума ряду = " << sum << endl;


    return 0;
}