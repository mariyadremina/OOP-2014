#include<iostream>
#include<fstream>

using namespace std;

template <class Type> class Array;

template <class Type>
ostream& operator<< (ostream &os, const Array<Type> &item)
{
    for(int i = 0; i < item._size; i++)
         os << item.val[i] << " ";
    if(!os)
    throw 4;    
    return os;
}

template <class Type>
istream& operator>> (istream &is, const Array<Type> &item)
{
    for(int i = 0; i < item._size; i++)
         is >> item.val[i];
    if(!is)
    throw 5;
    return is;
}

template <class Type> 
class Array
{
    private:
        int _size;
        Type *val;
        static int count;
    public:
        Array(int size = 10)
        {
            if( size >= 1000000)
                throw 0;
            count++;
            _size = size;
            val = new Type[_size];
            if(val == NULL)
            throw 1;
            
        }
        
        Array(const Array <Type> &rhs)
        {
            if(rhs._size >= 1000000)
            throw 0;
            count++;
            _size = rhs._size;
            val = new Type[_size];
            if(val == NULL)
            throw 1;
            for(int i = 0; i < _size; i++)
                val[i] = rhs.val[i];
        }
        
        Array(int size, Type *_val)
        {
            if(size >= 1000000)
            throw 0;
            count++;
            _size = size;
            val = new Type[_size];
            if(val == NULL)
            throw 1;
            for(int i = 0; i < _size; i++)
                val[i] = _val[i];
        }

        ~Array()
        {
            count--;
            delete[] val;
        }
        
        int count_Array()
        {
            return count;
        }
        
        int size()
        {
            return _size;
        }
        
        Type &operator[](int index)
        {
            if((index < 0) || (index >= _size))
            throw 2;
                return val[index];
        }
        
        bool operator == (const Array<Type> &rhs)
        {
            if(_size != rhs._size)
                return false;
            for(int i = 0; i < _size; i++)
            {
                if(val[i] != rhs.val[i])
                    return false;
            }
            return true;
        }

        bool operator != (const Array<Type> &rhs)
        {
            if(_size != rhs._size)
                return true;
            for(int i = 0; i < _size; i++)
            {
                if(val[i] != rhs.val[i])
                    return true;
            }
            return false;
        }

                
        Type &operator = (const Array<Type> &rhs)
        {
            if(_size != rhs._size)
            throw 6;
            if(*this != rhs){
            for(int i = 0; i < _size; i++)
                val[i] = rhs.val[i];
            }
        }


        Array<Type> &mergeArrays(const Array<Type> &array1, const Array<Type> &array2)
        {
            delete[] val;
            _size = array1._size + array2._size;
            val = new Type[_size];
            int m = 0;
            for (int i = 0; i < array1._size; i++)
            {
                int k = 0;
                for(int j = 0; j < array2._size; j++)
                {
                    if(array1.val[i] == array2.val[j])
                    {    
                         _size--;
                         k = 1;
                         break;
                    }
                }
                if(k == 0) {
                    val[m++] = array1.val[i];
                }
            }
            for(int i = m ; i < _size; i++)
            {
                for(int j = 0; j < array2._size; j++, i++)
                {
                    val[i] = array2.val[j];
                }
            }
        }
        
        void print_Array()
        {
            for(int i = 0; i < _size; i++)
                cout << val[i] << " ";
            cout << endl;
        }
        
        friend ostream& operator<< <Type>(ostream &os, const Array<Type> &item);
        friend istream& operator>> <Type>(istream &is, const Array<Type> &item);

            
};

template <class Type>
int Array<Type>:: count = 0;

int main()
{
    try {
        Array<char> ia(20);
        Array<float> ib;
        ia[25] = '4';
    }
    catch(int a)
    {
        if(a == 2)
            cout << "perebor" << endl;
    }
    
    try {
        Array<char> ias(2000000);
    }
    catch(int a)
    {
        if(a == 0)
         cout << "Error of memory" << endl;
    }
    
    try {
        Array<int> ie(10);
        Array<int> ig(15);
        ie = ig;
    }
    catch(int a)
    {
        if(a == 6)
            cout << "ne ravni" << endl;
    }

    try {
        double val[3] = {1.30, 2.25, 3.66};
        Array<double> id(3, val);
        id.print_Array();
        
        cout << "count: " << id.count_Array() << endl;
    }
    catch(int a)
    {
        if(a == 1)
            cout << "ERROR" <<endl;
    }
    
    int mas1[5] = {1, 2,3,4,5};
    int mas2[4] = {6,7,8,9};
    
    Array<int> im(5, mas1);
    Array<int> in(4, mas2);
    Array<int> io(10);
    
    io.mergeArrays(im, in);
    io.print_Array();
        
    return 0;

}
            