//
// Created by Denys on 21.10.2024.
//
#include <iostream>
#include <cstring>
#include <stack>
#include <iomanip>
#include <fstream>
#include "Lab_9.h"

using namespace std;
struct Officess {
    char name[20];
    char creator[20];
    int count;
    int cost;
};

void addText(const string &fileName) {
    ofstream file(fileName, ios_base::app);
    string tmpText;
    if (file.is_open()) {
        cout << "Введіть найменування, виробника, кількість пакетів, вартість " << endl;
        cin.ignore();
        getline(cin, tmpText);
        file << tmpText << endl;
        file.close();
        cout << "Text has been added" << endl;
    }else {
        cout << "Unable to open file" << endl;
    }
}
void deleteText(const string &fileName, int lineDelete) {
    ifstream file("lab_9.txt");
    vector<string> lines;
    string line;
    int currentLine = 1;

    if (file.is_open()) {

        while (getline(file, line)) {
            if (currentLine != lineDelete) {
                lines.push_back(line);
            }
            currentLine++;
        }
        file.close();

        ofstream outFile("lab_9.txt");
        for (int i = 0; i < lines.size(); i++) {
            outFile << lines[i] << endl;
        }
        outFile.close();

        cout << "Line " << lineDelete << " has been deleted." << endl;
    } else {
        cout << "Unable to open file" << endl;
    }

}

void lineForDisplay(const string &fileName, int lineDisplay) {
    ifstream file(fileName);
    string line;
    int currentLine = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (currentLine == lineDisplay) {
                cout << line << endl;
                file.close();
                return;
            }
            currentLine++;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
Officess parsing(const string &line) {
    Officess office = {"none", "none", 0, 0};
    istringstream stream(line);
    string tokens[4];
    int i = 0;


    while (stream >> tokens[i] && i < 4) {
        i++;
    }


    if (i >= 1) strncpy(office.name, tokens[0].c_str(), sizeof(office.name) - 1);
    if (i >= 2) strncpy(office.creator, tokens[1].c_str(), sizeof(office.creator) - 1);
    if (i >= 3) office.count = stoi(tokens[2]);
    if (i >= 4) office.cost = stoi(tokens[3]);

    return office;
}
void doesLineExist(const string &fileName, int lineDisplay) {
    ifstream file(fileName);
    string line;
    int currentLine = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (currentLine == lineDisplay) {
                file.close();
                cout << "Існує" << endl;
                return;
            }
            currentLine++;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    cout << "Не існує" << endl;
}

vector<Officess> prepareForDisplay(const string &fileName) {
    ifstream file(fileName);
    string line;
    vector<Officess> offices;

    if (file.is_open()) {
        while (getline(file, line)) {
            offices.push_back(parsing(line));
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
    }

    return offices;
}

void display(const vector<Officess> &offices) {
    cout << "-------------------------------------------------------\n";
    cout << "|                   Офісні пакети                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменування | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";

    for (const auto &office : offices) {
        cout << "| " << setw(12) << office.name
             << " | " << setw(8) << office.creator
             << " | " << setw(9) << office.count
             << " | " << setw(13) << office.cost
             << " |" << endl;
    }

    cout << "-------------------------------------------------------" << endl;

}

int lab_9() {

    string fileName = "lab_9.txt";
    ofstream file(fileName, ios_base::app);
    file.close();
    int numberOfOption;
    int numberFor;
    vector<Officess> offices = prepareForDisplay(fileName);



    start:
    cout << "1.Вивести таблицю"<< endl;
    cout << "2.Додати рядок в кінець" << endl;
    cout << "3.Видалити рядок" << endl;
    cout << "4.Вивести рядок за номером" << endl;
    cout << "5.Перевірити чи існує рядок" << endl;
    cout << "6.Вийти" << endl;
    cin >> numberOfOption;
    switch (numberOfOption) {
        case 1:
            offices = prepareForDisplay(fileName);
            parsing(fileName);
            display(offices);
            break;
        case 2:

            addText(fileName);
            offices = prepareForDisplay(fileName);
            break;
        case 3:
            parsing(fileName);
            display(offices);
            cout << "Номер рядка який видалити:" << endl;
            cin >> numberFor;
            deleteText(fileName,numberFor);
            offices = prepareForDisplay(fileName);
            break;
        case 4:
            parsing(fileName);
            display(offices);
            cout << "Номер рядка який вивести:" << endl;
            cin >> numberFor;
            lineForDisplay(fileName,numberFor);
            break;
        case 5:
            cout << "Номер рядка який хочете перевірити:" << endl;
            cin >> numberFor;
            doesLineExist(fileName,numberFor);
            break;
        case 6:
            break;
        default:
            cout << "Нема такого номера" << endl;

    }
    goto start;




    return 0;
}