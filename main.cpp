/******************************************************************************
                             Крутой справочник
*******************************************************************************/

#include <iostream>

#include <string>

#include <sstream>

#include <fstream>

using std::string;
using std::cout;
using std::endl;
void printStart();


FILE * f;

class Tele {
    public:
        string name;
    string surname;
    string phone;
    int id;
    void print() {
        
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        
        cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\t|" << "\t\tPhone: " << phone << endl;
        
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
    }

    void restore(int id, string name, string surname, string phone) {

        if (id != -1) this -> id = id;
        if (name != " ") this -> name = name;
        if (surname != " ") this -> surname = surname;
        if (phone != " ") this -> phone = phone;
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
    item.phone = mass[3];

    return item;
}

int getLengthFile(int count) {
    char c;
    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            count++;
        }
    return count;
}

void mounted() {

    int count = 0;
    int n = 0;
    string teleString = "";
    char c;

    count = getLengthFile(count);

    isFile();
    Tele teleMass[count];

    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            teleMass[n] = getClassItem(teleString);
            n++;
            teleString = "";
        } else {
            teleString += c;
        }

    for (int i = 0; i < count; i++) {
        teleMass[i].print();
    }
    
    printStart();

}

void addToFile() {
    string chooseNow;
    string fileText;
    string temp;
    
    isFile();
    std::ofstream vmdelet_out;                    
    vmdelet_out.open("text.txt", std::ios::app);
    
    
    for(int i =0;i < 4;i++) {
        
    
    switch (i) {
    case 0: {
       chooseNow = "id";
       break;
    }
    case 1: {
        chooseNow = "name";
        break;
    }
    case 2: {
        chooseNow = "surname";
        break;
    }
    
     case 3: {
        chooseNow = "phone";
        break;
    }
    }
    
    cout << "Введите " << chooseNow << endl;
    
    std::cin >> temp;
    
    if(chooseNow == "id") {
        temp+=".";
    }
    
    fileText += temp + '\t';
    
    }
    
    vmdelet_out << fileText << ";" << '\n';                        
    vmdelet_out.close();   
    mounted();
}

void removeToFile() {
   int id;
   
   isFile();
   
   cout << "Введите id для Удаления" << endl;
  
   std::cin >> id;
   
   
   
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
