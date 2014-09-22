#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    fstream out;
    char letter;

    string line;
    int count = 0;
    int k,i = 0;
    int *array = new int[100];
    int len = 0;

    for (k = 0; k < 100; k++)
        array[k] = 0;
        out.open("test1", ios::in|ios::out|ios::app);
       while(!out.eof())
       {  
            getline(out,line);
            cout << line << endl;
            
            cout << line.length() << endl;
            count = count + line.length() + 1;
            cout << count << endl;
            
            array[i] = count;
            i++;
        }    

        out.clear();
       for (i = 0; array[i] != 0; i++)
            out << array[i] << " " ;

    return 0;
}