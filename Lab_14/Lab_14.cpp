//
// Created by Denys on 20.11.2024.
//

#include "Lab_14.h"
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


class AbstractList {
public:
    virtual void insertHead(int value) = 0;
    virtual void insertTail(int value) = 0;
    virtual void insertAt(int index, int value) = 0;
    virtual void printList() const = 0;
    virtual int find(int value) const = 0;
    virtual int getHead() const = 0;
    virtual int getTail() const = 0;
    virtual ~AbstractList() = default;
};


class DynamicList : public AbstractList {
private:
    vector<int> list;

public:

    DynamicList() = default;

    DynamicList(const vector<int>& initialList) : list(initialList) {}

    DynamicList(const DynamicList& other) : list(other.list) {}


    ~DynamicList() override = default;


    void insertHead(int value) override {
        list.insert(list.begin(), value);
    }


    void insertTail(int value) override {
        list.push_back(value);
    }


    void insertAt(int index, int value) override {
        if (index < 0 || index > list.size()) {
            throw out_of_range("Індекс виходить за межі списку");
        }
        list.insert(list.begin() + index, value);
    }


    void printList() const override {
        for (int val : list) {
            cout << val << " ";
        }
        cout << endl;
    }


    int find(int value) const override {
        for (size_t i = 0; i < list.size(); ++i) {
            if (list[i] == value) {
                return i;
            }
        }
        return -1;
    }


    int getHead() const override {
        if (list.empty()) {
            throw runtime_error("Список порожній");
        }
        return list.front();
    }


    int getTail() const override {
        if (list.empty()) {
            throw runtime_error("Список порожній");
        }
        return list.back();
    }
};


int lab_14() {

    vector<int> initialList = {10, 20, 30, 40};
    DynamicList dynamicList(initialList);

    cout << "Початковий список:" << endl;
    dynamicList.printList();


    cout << "Додаємо елемент 5 на початок:" << endl;
    dynamicList.insertHead(5);
    dynamicList.printList();

    cout << "Додаємо елемент 50 в кінець:" << endl;
    dynamicList.insertTail(50);
    dynamicList.printList();

    cout << "Додаємо елемент 25 на позицію 3:" << endl;
    dynamicList.insertAt(3, 25);
    dynamicList.printList();


    cout << "Голова списку: " << dynamicList.getHead() << endl;
    cout << "Хвіст списку: " << dynamicList.getTail() << endl;


    int searchValue = 25;
    int index = dynamicList.find(searchValue);
    if (index != -1) {
        cout << "Елемент " << searchValue << " знайдено на позиції " << index << endl;
    } else {
        cout << "Елемент " << searchValue << " не знайдено" << endl;
    }


    cout << "Копіюємо список:" << endl;
    DynamicList copiedList = dynamicList;
    copiedList.printList();

    return 0;
}
