//
// Created by Denys on 08.10.2024.
//
#include <iostream>
#include <random>
#include "Lab_6.h"
#include <iomanip>
using namespace std;

void fillMatrix(int size, int** arr) {
    random_device rd;
    mt19937_64 rng(rd());
    uniform_int_distribution<int> dist(0, 99);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = dist(rng);
        }
    }
}

void printMatrix(int size, int** arr) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) <<  arr[i][j];
        }
        cout << endl;
    }
}

void workWithMatrix(int size, int** arr) {

    int** temp = new int*[size];
    for (int i = 0; i < size; i++) {

        temp[i] = new int[size];
    }
    for (int i = 0; i <= size/2; i++) {
        for (int j = 0; j < size; j++) {
            if(j>=i and j<=(size-j)) {
                temp[i][j] = arr[size-i-1][j];
                temp[size-i-1][j] = arr[i][j];
            }else {
                temp[i][j] = arr[i][j];
                temp[size-i-1][j] = arr[size-i-1][j];
            }
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            arr[i][j] = temp[i][j];
        }
    }
    delete temp;
}


int lab_6() {
    int size;
    cout << "Enter size of matrix: ";
    cin >> size;
    cout << endl;
    int** arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
    }

    fillMatrix(size, arr);
    printMatrix(size, arr);
    cout << endl;
    workWithMatrix(size, arr);
    printMatrix(size, arr);

    delete arr;

    return 0;
}
