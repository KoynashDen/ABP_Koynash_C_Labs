//
// Created by Denys on 25.09.2024.
//

#include "Lab_3.h"

#include <iostream>
#include <ostream>
#include <random>
#include <vector>

using namespace std;

int sumVectors(std::vector<int> tmp[10]) {
    int totalSum = 0;


    for (int i = 0; i < 10; ++i) {
        totalSum+=tmp->at(i);
    }

    return totalSum;
}
int sumMass(int tmp[10]) {
    int totalSum = 0;


    for (int i = 0; i < 10; ++i) {
        totalSum+=tmp[i];
    }

    return totalSum;
}
int lab_3() {
    SetConsoleOutputCP(CP_UTF8);

    random_device rd;
    mt19937_64 rng(rd());

    uniform_int_distribution<int> dist(0, 100);

    int mas[200];
    vector<int> tmp[10];
    int result_mas[10];
    int totalSum = 0;


    for (int i = 0; i < 200; i++) {
        mas[i] = dist(rng);
    }

    for (int i = 0; i < 200; i++) {
        cout << mas[i] << " ";
    }

    for (int i = 0; i < 200; i++) {
        if (i<10) {
            tmp->push_back(mas[i]);
            copy(tmp->begin(), tmp->end(), result_mas);
        }else {

            if (sumMass(result_mas) < (sumVectors(tmp)-tmp->at(0)+mas[i])) {

                tmp->erase(tmp->begin());
                tmp->push_back(mas[i]);
                copy(tmp->begin(), tmp->end(), result_mas);
                totalSum = sumVectors(tmp);
            }else {
                tmp->erase(tmp->begin());
                tmp->push_back(mas[i]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << result_mas[i] << " ";
    }






    cout << endl;
    cout << totalSum << endl;



    return 0;
}