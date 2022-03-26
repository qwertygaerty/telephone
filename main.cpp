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
void printStart();

FILE * f;

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

        cout << "---------------------------------------------------------------------------------------------------------" << endl;

        cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\t|" << "\t\tPhone: " << phone << endl;

        cout << "---------------------------------------------------------------------------------------------------------" << endl;
    }

    string toLine() {
        return toString(this -> id) + ". " + this -> name + " " + this -> surname + " " + toStringLong(this -> phone) + ";";
    }

    void restore(int id, string name, string surname, long phone) {
        if (id != -1) this -> id = id;
        if (name != " ") this -> name = name;
        if (surname != " ") this -> surname = surname;
        if (phone != -1) this -> phone = phone;
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

Tele getClassMass(Tele * teleMass) {
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

    if (count == 0) printStart();

    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        teleMass[i].print();
    }

    printStart();

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

void addToFile() {
    string fileText;
    Tele temp;
    isFile();
    std::ofstream vmdelet_out;
    vmdelet_out.open("text.txt", std::ios::app);

    for (int i = 0; i < 4; i++) {
        switch (i) {
        case 0: {
            cout << "Введите " << "id" << endl;
            while (true) {
                if ((std::cin >> temp.id).good()) break;
                if (std::cin.fail()) {
                    std::cin.clear();
                    cout << "Введите число" << endl;
                    std::cin.ignore();
                }
            }
            break;
        }
        case 1: {
            cout << "Введите " << "name" << endl;
            std::cin >> temp.name;
            break;
        }
        case 2: {
            cout << "Введите " << "surname" << endl;
            std::cin >> temp.surname;
            break;
        }

        case 3: {
            cout << "Введите " << "phone" << endl;
            std::cin >> temp.phone;
            break;
        }
        }
    }

    fileText = temp.toLine();

    vmdelet_out << fileText << ";" << '\n';
    vmdelet_out.close();
    mounted();
}

void removeToFile() {
    int id;
    int count = 0;
    cout << "Введите id для Удаления" << endl;
    std::cin >> id;
    count = getLengthFile(count);
    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        if (teleMass[i].id == id) {
            string str = teleMass[i].toLine();
            cout << "Удалено" << endl;
            cout << str << endl;
            searchInFile(str, " ");
        }
    }

    mounted();

}

void printStart() {

    int choose;
    cout << "Введите 0 для добавления" << endl;
    cout << "Введите 1 для Удаления" << endl;
    cout << "Введите 2 для Редактирования" << endl;

    std::cin >> choose;

    switch (choose) {
    case 0: {
        addToFile();
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
