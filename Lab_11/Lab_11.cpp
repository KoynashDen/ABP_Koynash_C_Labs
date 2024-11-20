//
// Created by Denys on 09.11.2024.
//

#include "Lab_11.h"
#include <iostream>

using namespace std;

class Applicant {
private:
    string pib;
    int birthday;
    int avgScore;

public:
    Applicant(const string &pib, int birthday, int avg_score)
        : pib(pib),
          birthday(birthday),
          avgScore(avg_score) {
    }

    string get_pib() const {
        return pib;
    }

    void set_pib(const string &new_pib) {
        pib = new_pib;
    }

    int get_birthday() const {
        return birthday;
    }

    void set_birthday(int new_birthday) {
        birthday = new_birthday;
    }

    int get_avg_score() const {
        return avgScore;
    }

    void set_avg_score(int new_avg_score) {
        avgScore = new_avg_score;
    }

    void display_birthday() const {
        cout << "Рік народження: " << birthday << endl;
    }

    void display_all_data() const {
        cout << "ПІБ: " << pib << endl;
        cout << "Рік народження: " << birthday << endl;
        cout << "Середня оцінка: " << avgScore << endl;
    }

    ~Applicant() = default;
};

class Student : public Applicant {
private:
    string numberOfBook;

public:
    Student(const string &pib, int birthday, int avg_score, const string &number_of_book)
        : Applicant(pib, birthday, avg_score),
          numberOfBook(number_of_book) {
    }

    string get_number_of_book() const {
        return numberOfBook;
    }

    void set_number_of_book(const string &new_number_of_book) {
        numberOfBook = new_number_of_book;
    }

    void display_all_data() const {
        Applicant::display_all_data();
        cout << "Номер залікової книжки: " << numberOfBook << endl;
    }

    ~Student() = default;
};

int lab_11() {

    Student student("Тарас Іванов", 2005, 11, "3242");


    cout << "Виведення дати народження:" << endl;
    student.display_birthday();
    cout << endl;
    cout << "Початкові данні:" << endl;
    student.display_all_data();
    cout << endl;
    cout << "Зміна ПІБ і середнього балу..." << endl;
    student.set_pib("Іван Петров");
    student.set_avg_score(8);
    cout << endl;
    cout << "Оновлені данні:" << endl;
    student.display_all_data();


    return 0;
}
