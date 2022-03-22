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
    
    void restore(int id, string name, string surname, string phone) {
        
        if(id != -1) this->id = id;
        if(name != " ") this->name = name;
        if(surname != " ") this->surname = surname;
        if(phone != " ") this->phone = phone;
    }
};

void isFile() {
    if ((f = fopen("text.txt", "r")) == NULL) {
        std::ofstream oFile("text.txt");
    };
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
    string mass[4]= {"n", "n", "n", "n"};
    
    
    getStringDelimiter(t, mass);
    
    Tele item;
    item.id =  stoi(mass[0]);
    item.name = mass[1];
    item.surname = mass[2];
    item.phone = mass[3];
    
    return item;
}

void mounted(int flag) {
    
     if(!flag) {
        
        
          isFile();
    
    std::ofstream vmdelet_out;                    
    vmdelet_out.open("text.txt", std::ios::app);  
    vmdelet_out << "\n 7.    qqf       trer     9090909090;";                        
    vmdelet_out.close();   
        
        mounted(1);
    }
    
    int count = 0;
    int n = 0;
    string teleString = "";
    char c;
   
    
    while (!feof(f))
        if ((c = fgetc(f)) == ';') {
            count++;
        } 
        
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
        
 
for(int i = 0; i< count;i++) {
    teleMass[i].restore(-1, "СОФИЯ", " ", " ");
    teleMass[i].print();
}

}

int main() {
    
    isFile();
    mounted(0);


    return 0;
}
