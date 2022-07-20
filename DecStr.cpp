#include <iostream>
#include <cstring>
#include "String.h"
#include "DecStr.h"


DecStr::DecStr(int length) : String(length)
{
    std::cout << this << " called DecStr constructor (len) " << std::endl;
}

DecStr::DecStr(char symbol) : String(symbol)
{
    std::cout << this << " called DecStr char constructor " << std::endl;
    if (!((m_str[0] >= '1' && m_str[0] <= '9')))
    {
        std::cout << "Bad simbol, ptr[0] = " << m_str[0] << std::endl;
        if (m_str) delete [] m_str;
        m_len = 0;
        m_str = new char[m_len + 1];
        m_str[0] = '\0';
        return;
    }
}

DecStr::DecStr(const char* str) : String(str) {
    std::cout << this << " called DecStr char* constructor" << std::endl;
    if (!((m_str[0] >= '1' && m_str[0] <= '9') || (m_str[0] == '-' || m_str[0] == '+'))) {
        std::cout << "Invalid symbol, m_str[0] can't be = " << m_str[0] << std::endl;
        delete[] m_str;
        m_len = 0;
        m_str = new char[m_len + 1];
        m_str[0] = '\0';
        return;
    }

    for (int i = 1; i < m_len; i++) {
        if (!(m_str[i] >= '0' && m_str[i] <= '9')) {
            std::cout << "Invalid string: m_str[" << i << "] can't be = " << m_str[i] << std::endl;
            delete[] m_str;
            m_len = 0;
            m_str = new char[m_len + 1];
            m_str[0] = '\0';
            return;
        }
    }
}

DecStr::DecStr(const DecStr& from) : String(from)
{
    std::cout << this << " called DecStr copy constructor" << std::endl;
}

DecStr& DecStr:: operator = (const DecStr& DS)
{
    std::cout << "DecStr operator \"=\" called" << std::endl;
    if (&DS != this) {
        delete[] m_str;
        m_len = strlen(DS.m_str);
        m_str = new char[m_len + 1];
        strcpy_s(m_str, m_len + 1, DS.m_str);
    }
    return *this;
}


DecStr operator + (const DecStr& decStrObj1, const DecStr& decStrObj2)
{
    std::cout << "operator \"+\" (DecStr obj + DecStr obj) called" << std::endl;
    int num1, num2;
    DecStr tmp(decStrObj1);
    num1 = atoi(tmp.GetStr());
    num2 = atoi(decStrObj2.GetStr());
    int sum = num1 + num2;
    char* pTmpCh;
    if (tmp.m_len >= decStrObj2.m_len) {
        pTmpCh = new char[tmp.m_len + 1];
        _itoa_s(sum, pTmpCh, tmp.m_len + 1, 10);
    }
    else {
        pTmpCh = new char[decStrObj2.m_len + 1];
        _itoa_s(sum, pTmpCh, decStrObj2.m_len + 1, 10);
    }
    if (tmp.m_str) delete[] tmp.m_str;
    tmp.m_str = pTmpCh;
    tmp.m_len = strlen(tmp.m_str);
    return tmp;
}

DecStr operator + (const DecStr& decStrObj, const int number) {
    std::cout << "operator \"+\" (DecStr obj + int) called" << std::endl;
    int num1, num2;
    DecStr tmp(decStrObj);
    num1 = atoi(tmp.GetStr());
    num2 = number;
    long long int sum = static_cast<long long>(num1) + num2;
    if ((sum > 2147483647) || (sum < -2147483648)) {
        std::cout <<"ERROR sum more then int size" << std::endl;
        delete[] tmp.m_str;
        tmp.m_len = 0;
        tmp.m_str = new char[tmp.m_len + 1];
        tmp.m_str[0] = '\0';
        return tmp;
    }
    char* pTmpCh;
    int numLen = 0;

    if (num2 < 0) {
        numLen++;
        num2 *= -1;
    }

    while (num2) {
        numLen++;
        num2 /= 10;
    }

    if (tmp.m_len > numLen) {
        pTmpCh = new char[tmp.m_len + 1];
        _itoa_s(sum, pTmpCh, tmp.m_len + 2, 10);
    }
    else {
        pTmpCh = new char[numLen + 2];
        _itoa_s(sum, pTmpCh, numLen + 2, 10);
    }

    if (tmp.m_str) delete[] tmp.m_str;
    tmp.m_str = pTmpCh;
    tmp.m_len = strlen(tmp.m_str);
    return tmp;
}

DecStr operator - (const DecStr& obj1, const DecStr& obj2)
{
    std::cout << "operator \"-\" (DecStr obj - DecStr obj) called" << std::endl;
    int num1, num2;
    DecStr tmp(obj1);
    num1 = atoi(tmp.GetStr());
    num2 = atoi(obj2.GetStr());
    int A = num1 - num2;
    char* pTmpCh;
    if (tmp.m_len >= obj2.m_len) {
        pTmpCh = new char[tmp.m_len + 1];
        _itoa_s(A, pTmpCh, tmp.m_len + 1, 10);
    }
    else {
        pTmpCh = new char[obj2.m_len + 1];
        _itoa_s(A, pTmpCh, obj2.m_len + 1, 10);
    }
    delete[] tmp.m_str;
    tmp.m_str = pTmpCh;
    tmp.m_len = strlen(tmp.m_str);
    return tmp;
}

bool operator == (const DecStr& num1, const DecStr& num2)
{
    std::cout << "DecStr \"==\" operator called" << std::endl;
    return (atoi(num1.GetStr()) == atoi(num2.GetStr()));
}

DecStr:: ~DecStr() {
    std::cout << this << " called DecStr destructor" << std::endl;
}