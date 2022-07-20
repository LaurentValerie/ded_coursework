#include <iostream>
#include <cstring>
#include "String.h"

String::String(int len) : m_len(len), m_str(new char[m_len + 1])
{
    std::cout << this << " called default String constructor (len)" << std::endl;
    if (len == 0) *m_str = '\0';
}

String::String(char symbol) : m_len(1), m_str(new char[m_len + 1])
{
    std::cout << this << " called default String constructor (symbol)" << std::endl;
    m_str[0] = symbol;
    m_str[1] = '\0';
}

String::String(const char* anotherStr) : m_len(strlen(anotherStr)), m_str(new char[m_len + 1])
{
    std::cout << this << " called String copy from another string (ptr)" << std::endl;
    strcpy(m_str, anotherStr);
}

// Version without using cstring lib
/*
String::String(const char* anotherStr)
{
    m_len = 0;
    while(*(anotherStr+m_len)) {
        m_len++;
    }

    m_str = new char[m_len + 1];
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = anotherStr[i];
    }
    m_str[m_len] = '\0';

    //strcpy(m_str, m_len + 1, anotherStr);
    std::cout << this << " copy from another string (ptr)" << std::endl;
}
*/

String::String(const String& sourceStr) : m_len(strlen(sourceStr.m_str)), m_str(new char[sourceStr.m_len + 1])
{
    std::cout << this << " called String copy from another string (link)" << std::endl;
    strcpy(m_str, sourceStr.m_str);
}

// Version without using cstring lib
/*
String::String(const String& sourceStr)
{
    m_len = 0;
    while(*(sourceStr.m_str+m_len)) {
        m_len++;
    }

    m_str = new char[sourceStr.m_len + 1];
    for (int i = 0; i < m_len; ++i) {
        m_str[i] = sourceStr.m_str[i];
    }
    m_str[m_len] = '\0';

    //strcpy(m_str, m_len + 1, sourceStr.m_str);
    std::cout << this << " copy from another string (link)" << std::endl;
}
*/

String::~String() {
    std::cout << this << " called String destructor" << std::endl;
    delete[] m_str;
}

void String::Show() {
    std::cout << this << " string = " << m_str << std::endl;
    std::cout << this << " m_len = " << m_len << std::endl;
}

bool String::IsEmpty() {
    std::cout << this << " called IsEmpty" << std::endl;
    if (m_str[0] == '\0') { return true; }
    return false;
}
