#include <algorithm>
#include <iostream>
#include <random>
#include <bits/ranges_algo.h>
using namespace std;
void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void addElement(int*& arr, int& size, int newElement) {
    int* tmpArr = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        tmpArr[i] = arr[i];
    }
    tmpArr[size] = newElement;
    delete[] arr;
    arr = tmpArr;
    ++size;
}

void findMaxAndMin(int* tmpArr, int* arr, int size) {
    int max_id = tmpArr[0];
    int min_id = tmpArr[0];

    for (int i = 0; i < size; ++i) {
        if (arr[tmpArr[i]] > arr[max_id]) {
            max_id = tmpArr[i];
        } else if (arr[tmpArr[i]] < arr[min_id]) {
            min_id = tmpArr[i];
        }
    }

    int tmpValue = arr[max_id];
    arr[max_id] = arr[min_id];
    arr[min_id] = tmpValue;
}

void mainProcess(int* arr, int size) {
    int countOfNegatives = 0;
    int* tmpArr = nullptr;

    for (int i = 0; i < size; i++) {

        if (arr[i] < 0) {
            if (i == size - 1 && countOfNegatives > 0) {
                addElement(tmpArr, countOfNegatives, i);
                findMaxAndMin(tmpArr, arr, countOfNegatives);
            }else {
                addElement(tmpArr, countOfNegatives, i);
            }

        } else if (countOfNegatives > 1) {
            findMaxAndMin(tmpArr, arr, countOfNegatives);
            delete[] tmpArr;
            tmpArr = nullptr;
            countOfNegatives = 0;
        } else {
            delete[] tmpArr;
            tmpArr = nullptr;
            countOfNegatives = 0;
        }
    }
}

int lab_5() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    random_device rd;
    mt19937_64 rng(rd());
    uniform_int_distribution<int> dist(-50, 50);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(rng);
    }

    printArr(arr, size);
    cout << endl;

    mainProcess(arr, size);

    printArr(arr, size);

    delete[] arr;
    return 0;
}
