/******************************************************************************

                             Крутой справочник

*******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
FILE *f;

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

void mounted() {
    int count = 0;
    string tele = "";
    char c;
    while (!feof(f)) if ((c=fgetc(f))=='\n') {
        count++;
        cout << tele << endl;
        tele = "";
    } else {
        tele+=c;
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