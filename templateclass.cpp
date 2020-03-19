#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *m_pData;
    unsigned int m_nSize;

public:
    Array(int nSize)
    {
        if(nSize <= 0)
        {
            cout << "Wrong size value!!" << endl;
        }
    }

    Array(unsigned int nSize) : m_nSize(nSize)
    {
        if(m_nSize > 0)
            m_pData = new (nothrow) T[m_nSize]; //nullptr od c++11 uzywany nowych standardow czyli c++11 wzwyz
    }

    virtual ~Array()
    {
        if(m_pData != NULL)
            delete m_pData;    // deleting array using "delete[]"
    }

    bool Set(unsigned int nPos, const T& Value)
    {
        if(m_pData != NULL && nPos < m_nSize) // m_pData != NULL sprawdzac czy NULL rozwiazanie do 1st test case
        {
            m_pData[nPos] = Value;
            return true;
        }
        else
            return false;
    }
    T Get(unsigned int nPos)
    {
        if(m_pData != NULL && nPos < m_nSize) // m_pData != NULL sprawdzac czy NULL rozwiazanie do 1st test case
            return m_pData[nPos];
        else
            return T();
    }
};

int main()
{
    //1nd test case
    //int a = 1;
   // int b = 69;
    Array<int> array;

    Array<int> arr(-1);
    arr.Set(0,1);

    //array.Set(0,a);
    //array.Set(1,b);
    // jesli new zwroci nam NULL/nullptr to jest lipa
    // jak zapobiec -> m_pData != NULL sprawdzac czy NULL w SET i GET

    //2nd test case
    //wszystko ok, usuwamy array, wywołuje się ~Array()
    //jak zapobiec -> powinnismy usunac m_pData za pomoce delete []


    //3rd test case
    //przy tworzeniu obiektu do konstruktora trafia liczba ujemna, rzutowanie niejawne na unsigned int i wielka liczba
    // jak zapobiec

    cout << "Hello world!" << endl;

    return 0;
}
