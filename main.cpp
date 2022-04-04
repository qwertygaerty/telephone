/******************************************************************************
                             Крутой справочник
*******************************************************************************/

#include <iostream>

#include <string>

#include <sstream>

#include <fstream>

using namespace std;
using std::string;
using std::cout;
using std::endl;

void printStart(int count);

FILE *f;

string toString(int n) {
    std::ostringstream ss;
    ss << n;
    return ss.str();
}

string toStringLong(long n) {
    std::ostringstream ss;
    ss << n;
    return ss.str();
}

class Tele {
public:
    string name;
    string surname;
    int id;
    long phone;

    void print() {

        cout
                << "---------------------------------------------------------------------------------------------------------"
                << endl;

        cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\t|" << "\t\tPhone: " << phone
             << endl;

        cout
                << "---------------------------------------------------------------------------------------------------------"
                << endl;
    }

    string toLine() {
        return toString(this->id) + ". " + this->name + " " + this->surname + " " + toStringLong(this->phone) + ";";
    }

    void restore(int id, string name, string surname, long phone) {
        if (id != -1) this->id = id;
        if (name != " ") this->name = name;
        if (surname != " ") this->surname = surname;
        if (phone != -1) this->phone = phone;
    }
};

void isFile() {
    if ((f = fopen("text.txt", "r")) == NULL) {
        std::ofstream oFile("text.txt");
    };
}

int getFirstNonSpaceSymbol(string mass[4]) {
    int count;
    for (int i = 0; i < 4; i++) {
        if (mass[i] == "n") {
            count = i;
            break;
        }
    }
    return count;
}

bool isNumberOfPhone(long number) {
    if (number > 999999999 && number < 10000000000) return true;
    return false;
}

string getStringDelimiter(string s, string mass[4]) {
    std::istringstream instr(s);
    string w;
    int count;
    while (instr >> w) {
        count = getFirstNonSpaceSymbol(mass);
        mass[count] = w;
    }

    return *mass;
}

Tele getClassItem(string t) {
    string mass[4] = {
            "n",
            "n",
            "n",
            "n"
    };

    getStringDelimiter(t, mass);

    Tele item;
    item.id = stoi(mass[0]);
    item.name = mass[1];
    item.surname = mass[2];
    item.phone = stol(mass[3]);

    return item;
}

int getLengthFile(int count) {
    isFile();
    char c;
    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            count++;
        }
    return count;
}

Tele getClassMass(Tele *teleMass) {
    string teleString = "";
    int n = 0;
    char c;
    isFile();
    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            teleMass[n] = getClassItem(teleString);
            n++;
            teleString = "";
        } else {
            teleString += c;
        }
    return *teleMass;
}

void mounted() {
    int count = 0;
    count = getLengthFile(count);

    if (count == 0) printStart(0);

    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        teleMass[i].print();
    }

    printStart(count);

}

void searchInFile(string word_source, string word_dest) {
    ifstream fin;

    isFile();
    fin.open("text.txt");
    string temp;
    int count = 0;
    temp = "";
    while (fin) {
        string str;
        getline(fin, str, '\n');
        if (!fin) break;

        size_t position = 0;

        while (position != std::string::npos) {
            size_t position_start = position;
            position = str.find(word_source, position);

            if (position != std::string::npos) {
                count++;

                temp += str.substr(position_start,
                                   position - position_start);
                temp += word_dest;
                position += word_source.size();
            } else {
                temp += str.substr(position_start,
                                   position - position_start);
            }
        }
        temp += "\n";
    }
    fin.close();

    // Перезаписываем файл. 
    ofstream fout("text.txt");
    fout << temp.substr(0, temp.size());
    fout.close();
}


string isOnlyString(std::string query) {
    string value;
    std::cout << query.c_str();
    while (!(std::cin >> value)) {
        if (std::cin.eof()) { throw "eof"; }
        std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
        std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
        std::cout << "Try again: ";
    }
    return value;
}

long isOnlyLong(std::string query) {
    long value;
    std::cout << query.c_str();
    while (!(std::cin >> value) || !isNumberOfPhone(value)) {
        if (std::cin.eof()) { throw "eof"; }
        std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
        std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
        std::cout << "Введите номер телефона 10 цифр: ";
    }
    return value;
}


int isOnlyInt(std::string query) {
    int value;
    std::cout << query.c_str();
    while (!(std::cin >> value)) {
        if (std::cin.eof()) { throw "eof"; }
        std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
        std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
        std::cout << "Введите корректный id: ";
    }
    return value;
}


void addToFile(int numberOfPhones) {
    string fileText;
    Tele temp;
    isFile();
    std::ofstream vmdelet_out;
    vmdelet_out.open("text.txt", std::ios::app);

    for (int i = 0; i < 4; i++) {
        switch (i) {
            case 0: {
                temp.id = numberOfPhones + 1;
                cout << temp.id << " - id" << endl;
                break;
            }
            case 1: {
                temp.name = isOnlyString("Введите name: ");
                break;
            }
            case 2: {
                temp.surname = isOnlyString("Введите surname: ");
                break;
            }

            case 3: {
                temp.phone = isOnlyLong("Введите phone: ");
                break;
            }
        }
    }

    fileText = temp.toLine();
    vmdelet_out << fileText << '\n';
    vmdelet_out.close();
    mounted();
}

void removeToFile() {
    bool isId = true;
    int id;
    int count = 0;

    id = isOnlyInt("Введите id для Удаления: ");

    count = getLengthFile(count);
    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        if (teleMass[i].id == id) {
            string str = teleMass[i].toLine();
            cout << "Удалено" << endl;
            cout << str << endl;
            searchInFile(str, " ");
            isId = true;
        } else {
            isId = false;
        }
    }

    if (!isId) removeToFile();

    mounted();

}

void printStart(int count) {

    int choose;
    cout << "Введите 0 для добавления" << endl;
    cout << "Введите 1 для Удаления" << endl;
    cout << "Введите 2 для Редактирования" << endl;

    std::cin >> choose;

    switch (choose) {
        case 0: {
            addToFile(count);
        }
        case 1: {
            removeToFile();
        }
        case 2: {

        }

    }

}

int main() {
    isFile();
    mounted();
    return 0;
}
