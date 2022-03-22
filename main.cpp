/******************************************************************************

                             Крутой справочник

*******************************************************************************/

#include <iostream>

#include <string>

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

string getClassItem(string t) {
    string word;
    int id;
    string name;
    string surname;
    string phone;
    int flag = 0;

    for(int i=0;i<t.length();i++) {


         if(flag ==3) {
        continue;
        }


         if(flag ==2) {
            if(t[i] != ' ') {
             surname+=t[i];

        } else {
            cout << surname << endl;
            flag = 3;
        }
        continue;

        }


        if(flag ==1) {
            if(t[i] != ' ') {
             name+=t[i];

        } else {
            cout << name << endl;
            flag = 2;
        }
        continue;

        }

        if(t[i] == '.') {
             id = stoi(word);
             cout << id << endl;
             flag = 1;
             word = "";
             continue;
        }




    }

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