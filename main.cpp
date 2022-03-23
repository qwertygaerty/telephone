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
    int id;
    long phone;
    void print() {
        
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
        
        cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\t|" << "\t\tPhone: " << phone << endl;
        
        cout << "---------------------------------------------------------------------------------------------------------" << endl;
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

string toString(int n){
    std::ostringstream ss;
    ss << n;
    return ss.str();
}

string toStringLong(long n){
    std::ostringstream ss;
    ss << n;
    return ss.str();
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
    item.phone = stol (mass[3]);

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
    
    if(count == 0) printStart(); 
    
    Tele teleMass[count];
    getClassMass(teleMass);

    for (int i = 0; i < count; i++) {
        teleMass[i].print();
    }
    
    printStart();

}

void addToFile() {
    string chooseNow;
    string fileText;
     Tele temp;
    
    isFile();
    std::ofstream vmdelet_out;                    
    vmdelet_out.open("text.txt", std::ios::app);
    
    for(int i =0;i < 4;i++) {
    switch (i) {
    case 0: {
        cout << "Введите " << "id" << endl;
        while(true) {
            if((std::cin >> temp.id).good()) break;
            if(std::cin.fail()) {
            std::cin.clear();
            cout << "Введите число"<<endl;
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
    
    
    fileText = toString(temp.id) + ". " + temp.name + " " + temp.surname + " " + toStringLong(temp.phone);
    
    vmdelet_out << fileText << ";" << '\n';                        
    vmdelet_out.close();   
    mounted();
}

void removeToFile() {
   int id;
   char c;
   string teleString = "";
   int flag = 0;

   
   isFile();
   
   cout << "Введите id для Удаления" << endl;
  
   std::cin >> id;
   
    // count = getLengthFile(count);
    // Tele teleMass[count];

    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            teleString = "";
            flag = 0;
        } else {
            teleString += c;
             
            c = ' ';
            
            if(teleString == (toString(id)+=".")) {
                flag = 1;
            }
            
            if(flag) {
               cout << (toString(id)+='.') << endl;
                cout << teleString << endl;
            }
            
        }
 

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
