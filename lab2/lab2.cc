#include <iostream>

using namespace std;

class IntArray
{
    private:
        int _size;
        int *val;
        static int count;
    public:
        
        //по умолчанию
        IntArray(int size = 10)
        {
            _size = size;
            val = new int[_size];
            count++;
        }
        
        //копирующий
        IntArray(const IntArray &rhs)
        {
            _size = rhs._size;
            val = new int[_size];
            for(int i = 0; i < _size; i++)
            {
                val[i] = rhs.val[i];
            }
            count++;
        }
        
        //иниц встроенным массивом
        IntArray(int size, int *_val)
        {
            _size = size;
            val = new int[_size];
            for(int i = 0; i < _size; ++i)
                val[i] = _val[i];
            count++;
        }
        
        //деструктор
        ~IntArray()
        {
            delete[] val;
        }
        
        void CountIntArray()
        {
            cout << count << endl;
        }
        
        int size()
        {
            return _size;
        }
        
        int &operator[](int index)
        {
            return val[index];
        }
        
        //оператор проверки на равенство
        bool operator == (const IntArray &rhs)
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
        
        //оператор присваивания
        IntArray& operator = (const IntArray &rhs)
        {
            if(*this == rhs)
                return *this;

            delete[] val;
            _size = rhs._size;
            val = new int [_size];
            for(int i = 0; i < _size; i++)
                val[i] = rhs.val[i];
            return *this;
        }
        /*Для определения текущего объекта класса адрес этого объекта всегда передается функции-члену как скрытый первый аргумент. 
        Соответственно внутри функции, когда нужно узнать, какой именно объект является текущим, используется этот указатель. 
        Всякий раз, когда функция обращается к другому члену класса, 
        не называя имени его объекта явно, компилятор считает, что он является членом этого (this) объекта.*/
        
        
        int Min()
        {
            int min = 0;
            for(int i = 0; i < _size; i++)
            {
                if(val[i] < val[min])
                {
                    min = i;
                }
            }
            return val[min];
        }
        
        
        int Max()
        {
            int max = 0;
            for(int i = 0; i < _size; i++)
            {
                if(val[i] > val[max])
                    max = i;
            }
            return val[max];
        }
        
        //ввод
        IntArray& InputArray()
        {
            for(int i = 0; i < _size; i++)
                cin >> val[i];
            return *this;
        }

        //вывод
        void OutPutArray()
        {
            for(int i = 0; i <_size; i++)
                cout << val[i] << " " ;
                
        }
        
        IntArray& Sort(int r, int l);
        IntArray& sSort(int r, int l);
};

IntArray& IntArray::Sort(int r, int l)
{
    int i = r, j = l;
    int pivot = val[(l + r) / 2];
    int temp;

    do {
        while(val[i] < pivot) i++;
        while(val[j] > pivot) j--;

        if (i <= j)
        {
            if(val[i] > val[j])
            {
                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
            i++;
            j--;
        }
    } while(i <= j);
               
    if (i < l)
        Sort(i, l);
    if (r < j)
        Sort(r, j);

    return *this;
}
IntArray& IntArray::sSort(int r, int l)
{
    int i = r, j = l;
    int pivot = val[(l + r) / 2];
    int temp;

    do {
        while(val[i] > pivot) i++;
        while(val[j] < pivot) j--;

        if (i <= j)
        {
            if(val[i] < val[j])
            {
                temp = val[i];
                val[i] = val[j];
                val[j] = temp;
            }
            i++;
            j--;
        }
    } while(i <= j);
               
    if (l > i)
        sSort(i, l);
    if (j > r)
        sSort(r, j);

    return *this;
}

int IntArray::count = 0;

int main()
{
    IntArray mas(5);
    
    mas.InputArray();
    
    IntArray cmas(mas);
    
    //cmas.OutPutArray();
    cout << endl;
   
    int ccmas[5] = {0, 2, 4, 6, 8};
    IntArray cccmas(5, ccmas);
    cccmas.OutPutArray();
    cout << endl;
     
    mas.Sort(0 , 4);
    //mas.OutPutArray();
    cout << endl; 
    
    mas.sSort(0 , 4);
    //mas.OutPutArray();
    cout << endl;
    
    //cmas.CountIntArray(); 
    
    return 0;

}
            