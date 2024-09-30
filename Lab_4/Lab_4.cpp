//
// Created by Denys on 30.09.2024.
//

#include "Lab_4.h"

int lab_4() {
    int size = 9;
    int Arr[size][size];
    int start = 1;

    for (int i = 0 ; i < size; i++) {
        int row = size - 1, column = i;
        while (row < size && column >= 0) {
            Arr[row][column] = start++;
            row--;
            column--;

        }

    }
    for (int i = size-2 ; i >= 0; i--) {
        int row = i, column = size - 1;
        while (row >= 0 && column >= 0) {
            Arr[row][column] = start++;
            row--;
            column--;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << Arr[i][j];
        }
        cout << endl;
    }

    return 0;
}