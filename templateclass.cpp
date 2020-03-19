#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
    T *m_pData;
    unsigned int m_nSize;

public:
    Array(unsigned int nSize) : m_nSize(nSize)
    {
        if(m_nSize > 0)
            m_pData = new (nothrow) T[m_nSize]; // If new returns NULL/nullptr we've got a problem. Check that in Get and Set.
    }

    virtual ~Array()
    {
        if(m_pData != NULL)
            delete m_pData;  // deleting array using "delete [] m_pData". This point is also not necessary. 2nd tescase
    }

    bool Set(unsigned int nPos, const T& Value)
    {
        if(nPos < m_nSize)  // check if "m_pData != NULL", by changing line to "if(m_pData != NULL && nPos < m_nSize)" - 1st test case
        {
            m_pData[nPos] = Value;
            return true;
        }
        else
            return false;
    }
    T Get(unsigned int nPos)
    {
        if(nPos < m_nSize)  // check if "m_pData != NULL", by changing line to "if(m_pData != NULL && nPos < m_nSize)" - 1st test case
            return m_pData[nPos];
        else
            return T();
    }
};

int main()
{
    return 0;
}

   /* 
     1st test case
     If new returns NULL/nullptr we've got a problem.
     We can prevent that checking if "m_pData != NULL" in Set and Get

     2nd test case
     Incorect way of deleting array.
     Use "delete[] m_pData" instead of "delete m_pData"
     Check is also not necessary
     
     
     III(*)Consider using C++11 or newer
   */
