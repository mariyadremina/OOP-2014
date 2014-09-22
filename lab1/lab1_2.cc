#include <iostream>
#include <istream>
#include <fstream>

using namespace std;

int main()
{
    ofstream out("out");
    if(!out)
    {
    cout << "Error for open file" << endl;
    return 1;
    }
    char file[3][15] = {"test1", "test2", "test3"};
    int i = 0;

    for( i = 0; i < 3; i++)
    {
        ifstream in(file[i]);
        if(!in)
        {
            cout << "Error, but continue" << endl;
            continue; 
        }
        
        string line;
        int count = 0;

        while(getline(in, line))
        {
            out << file[i] <<" : " << line << endl;
            count++;
        }
        cout << file[i] << " col of line = " << count << endl;
    }
    return 0;
}
            