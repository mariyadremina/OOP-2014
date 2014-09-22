#include <iostream>
#include <istream>

using namespace std;

istream &myfunc(istream &mycin)
{
    int val = 0;
    while(!mycin.eof())
    {
        mycin >> val;
       /* if(mycin.bad())
        {
            cout << "Error of stream!" << endl;
            break;
        }*/
        if(mycin.fail())
        {
            cout << mycin.fail() << endl;
            /*mycin.clear(istream::failbit);
            continue;*/
            break;
        }
        if(mycin.bad())
        {
            cout << "Error of stream!" << endl;
            break;
        }
        cout << "You entered: " << val << ' ' << mycin.fail() << endl;
    }
    mycin.clear();
    return mycin;
}

int main()
{
    myfunc(cin);
}

