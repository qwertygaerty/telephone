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
FILE * f;

class Tele {
    public:
        string name;
    string surname;
    string phone;
    int id;
    void print() {
        cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\tPhone: " << phone << endl;
    }
};

FILE isFile() {
    if ((f = fopen("text.txt", "r")) == NULL) {
        std::ofstream oFile("text.txt");
    };
    return *f;
}

int getFirstNonSpaceSymbol(string mass[4]) {
    int count;
    for(int i =0;i < 4; i++) {
        if(mass[i] == "n") {
          count=i;
          break;
        }
    }
    return count;
}

string getStringDelimiter(string s) {
    string mass[4]= {"n", "n", "n", "n"};
    std::istringstream instr(s);
    string w;
    int count;
    while (instr >> w) {
        count = getFirstNonSpaceSymbol(mass);


        mass[count] = w;
    }

     cout << "ID: " << mass[0] << "\tName: " << mass[1] << "\tSurName: " << mass[2] << "\t\tPhone: " << mass[3] << endl;

   return "";
}

string getClassItem(string t) {
    string word;
    int id;
    string name = "";
    string surname;
    string phone;
    int flag = 0;
    getStringDelimiter(t);
    // cout << "ID: " << id << "\tName: " << name << "\tSurName: " << surname << "\t\tPhone: " << phone << endl;
    
    return "";
}

void mounted() {
    int count = 0;
    string teleString = "";
    char c;
    string teleMass[1000];
    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            count++;
            
            teleMass[count] = getClassItem(teleString);
            teleString = "";
        } else {
            teleString += c;
        }
    
}

int main() {
    
    isFile();
    mounted();

    //   Tele dan;
    //   dan.id = 1;
    //   dan.name = "Dan";
    //   dan.surname = "Ahagna";

    //   dan.phone = "8348345676";
    //   dan.print();

    return 0;
}