#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <sstream>
#include <fstream>

using namespace std;
using std::string;
using std::cout;
using std::endl;

void printStart(int count);

FILE *f;

void color (int color) {
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
    COORD c;
    c.X =x;
    c.Y =y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void gotoy(int x) {
    COORD c;
    c.X =x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void gotox(int x) {
    COORD c;
    c.X =x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

string toString(int n) {
    std::ostringstream ss;
    ss << n;
    return ss.str();
}

string toStringLong(long long n) {
    std::ostringstream ss;
    ss << n;
    return ss.str();
}

void smileLinePrint() {
    cout << "\t\t\t\t\t" << "----------------------------------------------------------------------------"<< endl;
}

class Tele {
public:
    string name;
    string surname;
    int id;
    long long phone;
    void print() {
        smileLinePrint();
        cout << "\t\t\t\t\t" <<"ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t|" << "\tPhone: " << phone
             << endl;

        smileLinePrint();
    }

    string toLine() {
        return toString(this->id) + ". " + this->name + " " + this->surname + " " + toStringLong(this->phone) + ";";
    }
};

void isFile() {
    if ((f = fopen("text.txt", "r")) == NULL) {
        std::ofstream oFile("text.txt");
    };
}

int getFirstNonSpaceSymbol(string mass[4]) {
    int count;
    for (int i = 0; ; i++) {
        if (mass[i] == "n") {
            count = i;
            break;
        }
    }
    return count;
}

bool isNumberOfPhone(long long number) {
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
    string mass[4] = {"n", "n", "n", "n"};
    getStringDelimiter(t, mass);
    Tele item;
    item.id = stoi(mass[0]);
    item.name = mass[1];
    item.surname = mass[2];
    item.phone = stoll(mass[3]);

    return item;
}

int getLengthFile() {
    int count = 0;
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
    count = getLengthFile();
     system("cls");
    if (count == 0) printStart(0);
    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
            color(7);
        teleMass[i].print();
    }
    printStart(count);
}

int getId() {
int choose;
    int count = 0;
    count = getLengthFile();
    int Set[count]; //DEFAULT COLORS
    Tele teleMass[count];
    getClassMass(teleMass);
    int counter = count/2;
    char key;
    for(int i = 0 ;;) {
        system("cls");
        for (int i = 0; i < count; i++) {
            if(i != counter) Set[i]=7;
        Set[counter] = 12;
        color(Set[i]);
        teleMass[i].print();
        }
        key = _getch();

        if (key == 13)
                {
                        return teleMass[counter].id;
                }

        if (key == 72) {
                    counter --;
            }
        if (key == 80) // 80 = down arrow
            {
                counter++;
            }
         if (key == 13)
                {
                    Set[i]=7;
                    color(Set[i]);
                        return teleMass[counter].id;
                }
    }

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
        std::cout << "Введите строку: ";
    }
    return value;
}

long long isOnlyLong(std::string query) {
    long long value;
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

Tele setAllTempValue(Tele temp) {
    std::cout << temp.id << " - id" << std::endl;
    temp.name = isOnlyString("Введите name: ");
    temp.surname = isOnlyString("Введите surname: ");
    temp.phone = isOnlyLong("Введите phone: ");
    return temp;
}

void addToFile() {
    Tele temp;
    int count = 0;
    int numberOfPhones = 0;
    count = getLengthFile();
    Tele teleMass[count];
    getClassMass(teleMass);
    numberOfPhones = teleMass[count-1].id;
    if(count == 0) numberOfPhones = 0;
    isFile();
    std::ofstream vmdelet_out;
    vmdelet_out.open("text.txt", std::ios::app);
    temp.id = numberOfPhones + 1;
    temp = setAllTempValue(temp);
    vmdelet_out << temp.toLine() << '\n';
    vmdelet_out.close();
    mounted();
}

void removeToFile() {
    int id;
    int count = 0;
    count = getLengthFile();
    Tele teleMass[count];
    getClassMass(teleMass);

    id = getId();
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

void restoreToFile() {
    int id;
    int count = getLengthFile();
    id = getId();
    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        if (teleMass[i].id == id) {
            string str = teleMass[i].toLine();
            cout << "Поиск: " << str << endl;
            teleMass[i] = setAllTempValue(teleMass[i]);
            searchInFile(str, teleMass[i].toLine());
        }
    }

    mounted();
}

void printStart(int count) {
    int Set[] = {7,7,7}; //DEFAULT COLORS
    int counter = 2;
    char key;
    for(int i = 0 ;;) {
        gotoxy(0, 10);
        color(Set[0]);
        cout << "Добавить номер телефона" << "\n";

        gotoxy(0, 11);
        color(Set[1]);
        cout << "Удалить номер телефона" << "\n";

        gotoxy(0, 12);
        color(Set[2]);
        cout << "Редактировать номер телефона" << "\n";

        key = _getch();

       if (key == 72 && (counter >=2 && counter <=3 )) {
            counter --;
        }
        if (key == 80 && (counter >=1 && counter <=2) ) // 80 = down arrow
        {
        counter++;
        }
        if (key == 13)
        {
            if (counter == 1 ) {
                gotoxy(0, 6);
                if(count == 0) cout << "Введите свой первый телефонный номер";
                gotoxy(0, 13);
                addToFile();
            }
            if (counter == 2 && count != 0 ) {
                removeToFile();
            }  else {
                gotoxy(0, 6);
            cout << "Пока нет ни одной записи. ";
            }
            if (counter == 3 && count != 0) {
                restoreToFile();
            } else {
                gotoxy(0, 6);
            cout << "Пока нет ни одной записи. ";
            }
        }

        Set[0]=7;
        Set[1]=7;
        Set[2]=7;

        if(counter == 1 ) Set[0] = 12;
        if(counter == 2 ) Set[1] = 12;
        if(counter == 3 ) Set[2] = 12;

    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    isFile();
    mounted();
    return 0;
}
