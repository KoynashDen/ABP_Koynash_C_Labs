#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Ofice {
private:
    char *name;
    char *creator;
    unsigned int count;
    float price;

public:
    Ofice(const char *name, const char *creator, unsigned int count, float price)
        : count(count), price(price) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->creator = new char[strlen(creator) + 1];
        strcpy(this->creator, creator);
    }

    Ofice() : name(nullptr), creator(nullptr), count(0), price(0.0) {}

    ~Ofice() {
        delete[] name;
        delete[] creator;
    }

    void show() const {
        cout << "|" << setw(14) << (name ? name : "Unknown") << "|" << setw(10) << creator
             << "|" << setw(11) << count << "|" << setw(15) << price << "|" << endl;
    }

    const char* get_name() const {
        return name;
    }

    void set_name(const char *name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    const char* get_creator() const {
        return creator;
    }

    void set_creator(const char *creator) {
        delete[] this->creator;
        this->creator = new char[strlen(creator) + 1];
        strcpy(this->creator, creator);
    }

    unsigned int get_count() const {
        return count;
    }

    void set_count(unsigned int count) {
        this->count = count;
    }

    float get_price() const {
        return price;
    }

    void set_price(float price) {
        this->price = price;
    }
};

int lab_10() {
    int maxCars = 10;
    Ofice* cars = new Ofice[maxCars];

    int kilkist = 0;
    for (int i = 0; i < maxCars; ++i) {
        char name[20];
        char creator[20];
        unsigned int count;
        float price;

        cout << "Введите наименование, трансмиссию, объем двигателя и скорость " << i + 1 << " (введите '***' для завершения):" << endl;
        cin >> name;

        if (strcmp(name, "***") == 0) {
            break;
        }
        cin >> creator >> count >> price;
        cars[i].set_name(name);
        cars[i].set_creator(creator);
        cars[i].set_count(count);
        cars[i].set_price(price);
        kilkist++;
    }

    cout << "-------------------------------------------------------\n";
    cout << "|                   Офисные пакеты                     |\n";
    cout << "|-----------------------------------------------------|\n";
    cout << "| Найменование | Виробник | Кількість |  Вартість ($) |\n";
    cout << "|              |          |  пакетів  |               |\n";
    cout << "|--------------|----------|-----------|---------------|\n";
    for (int i = 0; i < kilkist; ++i) {
        cars[i].show();
    }
    cout << "-------------------------------------------------------" << endl;

    delete[] cars;
    return 0;
}
