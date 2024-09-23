//
// Created by Denys on 23.09.2024.
//

#include "Lab_2_1.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

int lab_2_1() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double x;
    double y;

    cout << "Введіть х:" << endl;
    cin >> x;
    cout << "Введіть y:" << endl;
    cin >> y;

    if ((x*x + y*y <= 1) && (x>=0 || y>=0) ) {
        cout << "Точка попадає в область" << endl;
    }else {
        cout << "Точка не попадає в область" << endl;
    }

    return 0;
}

