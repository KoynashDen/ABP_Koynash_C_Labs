#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Officek {
private:
    char *name;
    char *creator;
    unsigned int count;
    float price;

public:

    Officek() : name(nullptr), creator(nullptr), count(0), price(0.0) {}

    Officek(const char *name, const char *creator, unsigned int count, float price)
        : count(count), price(price) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->creator = new char[strlen(creator) + 1];
        strcpy(this->creator, creator);
    }


    Officek(const Officek &o) {
        name = new char[strlen(o.name) + 1];
        strcpy(name, o.name);
        creator = new char[strlen(o.creator) + 1];
        strcpy(creator, o.creator);
        count = o.count;
        price = o.price;
    }


    ~Officek() {
        delete[] name;
        delete[] creator;
    }

    //overload
    Officek &operator=(const Officek &o) {
        if (this != &o) {
            delete[] name;
            delete[] creator;
            name = new char[strlen(o.name) + 1];
            strcpy(name, o.name);
            creator = new char[strlen(o.creator) + 1];
            strcpy(creator, o.creator);
            count = o.count;
            price = o.price;
        }
        return *this;
    }

    // konakntenacia
    Officek operator+(const Officek &o) const {
        Officek result;
        result.name = new char[strlen(name) + strlen(o.name) + 1];
        strcpy(result.name, name);
        strcat(result.name, o.name);

        result.creator = new char[strlen(creator) + strlen(o.creator) + 1];
        strcpy(result.creator, creator);
        strcat(result.creator, o.creator);

        result.count = count + o.count;
        result.price = price + o.price;
        return result;
    }


    bool operator==(const Officek &o) const {
        return (strcmp(name, o.name) == 0 && strcmp(creator, o.creator) == 0 &&
                count == o.count && price == o.price);
    }


    friend ostream &operator<<(ostream &out, const Officek &o) {
        out << "|" << setw(14) << (o.name ? o.name : "Unknown")
            << "|" << setw(10) << (o.creator ? o.creator : "Unknown")
            << "|" << setw(11) << o.count << "|" << setw(15) << o.price << "|";
        return out;
    }


    friend istream &operator>>(istream &in, Officek &o) {
        char tempName[50], tempCreator[50];
        cout << "Введіть найменування, виробника, кількість пакетів, вартість ";
        in >> tempName;


        if (strcmp(tempName, "***") == 0) {
            o.name = nullptr;
            return in;
        }

        in >> tempCreator >> o.count >> o.price;

        o.name = new char[strlen(tempName) + 1];
        strcpy(o.name, tempName);

        o.creator = new char[strlen(tempCreator) + 1];
        strcpy(o.creator, tempCreator);

        return in;
    }


    void show() const {
        cout << *this << endl;
    }


    bool isEmpty() const {
        return name == nullptr;
    }
};


int lab_12() {
    int maxOfficeks = 10;
    Officek* Officeks = new Officek[maxOfficeks];

    int count = 0;
    for (int i = 0; i < maxOfficeks; ++i) {
        cin >> Officeks[i];
        if (Officeks[i].isEmpty()) {
            break;
        }
        count++;
    }

    cout << "-------------------------------------------------------\n";
    cout << "|                   Офісні пакети                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменування | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";
    for (int i = 0; i < count; ++i) {
        Officeks[i].show();
    }
    cout << "-------------------------------------------------------" << endl;

    delete[] Officeks;
    return 0;
}
