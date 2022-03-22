/******************************************************************************

                             Крутой справочник

*******************************************************************************/

#include <iostream>

#include <string>

#include <fstream>

using std::string;
using std::cout;
using std::endl;

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
  FILE *f;
  if ((f = fopen("text.txt", "r")) == NULL) {
    std::ofstream oFile("text.txt");

    return *f;
  };
  return *f;
}

void mounted() {

}

int main() {

  FILE file = isFile();

  string teleFile = "text.txt";

  Tele dan;
  dan.id = 1;
  dan.name = "Dan";
  dan.surname = "Ahagna";

  dan.phone = "8348345676";
  dan.print();

  return 0;
}