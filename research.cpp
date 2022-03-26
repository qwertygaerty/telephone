///----------------------------------------------------------------------------|
/// Поиск и замена в текстовом файле.
///----------------------------------------------------------------------------:
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
///----------------------------------------------------------------------------|
/// Старт.
///----------------------------------------------------------------------------:
int main()
{   setlocale(0, "");
    string file = "text.txt";
    
    ifstream fin;
             fin.open(file);
    if (    !fin.is_open())
    {   cout << "Error. File not found." << endl;
    }
    else
    {   cout << "Файл myFile.txt найден...\n";
        
        string word_source = "uberra";
        string word_dest   = "бодро";
        
        string temp; int count = 0;
        temp = "";
        while (fin)
        {   string str;
            getline(fin, str, '\n');
            if(!fin) break;
            
            cout << str << endl;
            
            size_t position = 0;
            
            while(position != std::string::npos)
            {   size_t position_start = position;
                position = str.find(word_source, position);
                
                if(position != std::string::npos)
                {   //std::cout << "    >>>Слово найдено!\n";
                    count++;
                
                    ///------------------------|
                    /// Пишем до найденого.    |
                    ///------------------------:
                    temp     += str.substr(position_start, 
                                           position - position_start);
                    ///------------------------|
                    /// Меняем слово.          |
                    ///------------------------:
                    temp     += word_dest;
                    position += word_source.size();
                }
                else    
                {   temp     += str.substr(position_start, 
                                           position - position_start);
                }
            }
            temp += "\n";
        }
        fin. close();
        
        ///------------------------|
        /// Перезаписываем файл.   |
        ///------------------------:
        ofstream fout("text.txt");
        fout << temp.substr(0, temp.size());
        fout.close();
        
        cout << "Вcего было заменено " << count << " слов(а).\n";
        cout << "\nТекст на выходе------------------------------------------:\n"
             << temp << "\n";
    }
    return 0;
}
