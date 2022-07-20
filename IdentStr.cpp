#include <iostream>
#include <cstring>
#include "String.h"
#include "IdentStr.h"

IdentStr::IdentStr(int len) : String(len)
{
    std::cout << this << " called IdentStr constructor (len)" << std::endl;
}

IdentStr::IdentStr(char symbol) : String(symbol)
{
    std::cout << this << " called IdentStr constructor (char)" << std::endl;
    // Test for the correct symbol
    if (!((m_str[0] >= 'a' && m_str[0] <= 'z') || (m_str[0] >= 'A' && m_str[0] <= 'Z'))) {
        std::cout << "Bad symbol, m_str[0] can't be = " << m_str[0] << std::endl;
        delete[] m_str;
        m_str = new char[m_len + 1];
        m_str[0] = '\0';
        m_len = 0;
    }
}

IdentStr::IdentStr(const char* anotherStr) : String(anotherStr)
{
    std::cout << this << " called IdentStr copy constructor" << std::endl;
    // Test the first symbol is correct
    if (!((m_str[0] >= 'a' && m_str[0] <= 'z') || (m_str[0] >= 'A' && m_str[0] <= 'Z'))) {
        std::cout << "Bad symbol, m_str[0] can't be = " << m_str[0] << std::endl;
        delete[] m_str;
        m_str = new char[m_len + 1];
        m_str[0] = '\0';
        m_len = 0;
    }
    // Test another symbols
    for (int i = 1; i < m_len; ++i) {
        if (!((m_str[i] >= 'a' && m_str[i] <= 'z') || (m_str[i] >= 'A' && m_str[i] <= 'Z') ||
            (m_str[i] >= '0' && m_str[i] <= '9'))) {
            std::cout << "Bad symbol, m_str[" << i << "] can't be = " << m_str[i] << std::endl;
            delete[] m_str;
            m_str = new char[m_len + 1];
            m_str[0] = '\0';
            m_len = 0;
            return;     // Just to leave cycle
        }
    }
    // All cpp keywords
    const char* keyword[] = {
            "aligna", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
            "char", "char8_t", "char16_t", "char32_t", "class",
            "compl", "concept", "const", "const_cast", "consteval", "constexpr", "constinit", "continue", "co_await",
            "co_return", "co_yield", "decltype", "default",
            "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
            "for", "friend", "goto", "if", "inline", "int",
            "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq",
            "private", "protected", "public", "register reinterpret_cast",
            "requires", "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast", "struct",
            "switch", "template", "this", "thread_local", "throw",
            "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile",
            "wchar_t", "while", "xor", "xor_eq"
    };
    // Test that string isn't some keyword
    for (int i = 0; i < 91; ++i) {
        if (strcmp(m_str, keyword[i]) == 0) {
            std::cout << "String can't be = " << m_str << std::endl;
            delete[] m_str;
            m_len = 0;
            m_str = new char[m_len + 1];
            m_str[0] = '\0';
            return;     // Just to leave cycle
        }
    }
}

IdentStr::IdentStr(const IdentStr& sourceStr) : String(sourceStr)
{
    std::cout << this << " called IdentStr copy from another string" << std::endl;
}

IdentStr& IdentStr::operator=(const IdentStr& anotherStr)
{
    std::cout << this << " called IdentStr::operator=" << std::endl;
    if (&anotherStr != this) {
        delete[] m_str;
        m_len = anotherStr.m_len;
        m_str = new char[m_len + 1];
        strcpy(m_str, anotherStr.m_str);
    }
    return *this;
}

char& IdentStr::operator[](int index)
{
    std::cout << this << " called IdentStr [] operator" << std::endl;
    // Can't test that first symbol still correct
    if (index >= 0 && index < m_len) {
        return m_str[index];
    }
    return m_str[0];
}

IdentStr IdentStr::operator~()
{
    std::cout << this << " called IdentStr reverse" << std::endl;
    // Test that the last symbol is correct
    if (!((m_str[m_len - 1] >= 'a' && m_str[m_len - 1] <= 'z') || (m_str[m_len - 1] >= 'A' && m_str[m_len - 1] <= 'Z') || (m_str[m_len - 1] == '_'))) {
        std::cout << "Can't reverse this string, reversed m_str[0] can't be = " << m_str[m_len - 1] << std::endl;
        delete[] m_str;
        m_len = 0;
        m_str = new char[m_len + 1];
        m_str[0] = '\0';
    }
    // String reverse
    for (int i = 0, j = m_len - 1; i < m_len / 2; ++i, --j) {
        char tmp = m_str[i];
        m_str[i] = m_str[j];
        m_str[j] = tmp;
    }
    return *this;
}

IdentStr IdentStr::ToCapital() {
    int len = m_len;
    IdentStr tmp(m_len + 1);
    for (int i = 0; i < m_len; ++i) {
        tmp.m_str[i] = static_cast<char>(toupper(m_str[i]));
    }
    tmp[m_len] = '\0';
    return tmp;
}

IdentStr operator+(const IdentStr& str1, const IdentStr& str2)
{
    std::cout << "operator IdentStr(link) + IdentStr(link) called" << std::endl;
    IdentStr result(str1.GetLen() + str2.GetLen());
    int i = 0, j = 0;
    while ((result.m_str[i++] = str1.m_str[j++])); // copy
    --i; j = 0;
    while ((result.m_str[i++] = str2.m_str[j++])); // concatenation
    return result;
}

IdentStr operator + (const IdentStr& str1, const char* str2)
{
    std::cout << "operator IdentStr(link) + IdentStr(char*) called" << std::endl;
    IdentStr tmp(str2);
    IdentStr result(str1.GetLen() + tmp.GetLen());
    int i = 0, j = 0;
    while ((result.m_str[i++] = str1.m_str[j++])); // copy
    --i; j = 0;
    while ((result.m_str[i++] = tmp.m_str[j++])); // concatenation
    return result;
}

IdentStr operator + (const char* str1, const IdentStr& str2)
{
    std::cout << "operator IdentStr(char*) + IdentStr(link) called" << std::endl;
    IdentStr tmp(str1);
    IdentStr result(str2.GetLen() + tmp.GetLen());
    int i = 0, j = 0;
    while ((result.m_str[i++] = tmp.m_str[j++])); // copy
    --i; j = 0;
    while ((result.m_str[i++] = str2.m_str[j++])); // concatenation
    return result;
}

bool operator == (const IdentStr& obj1, const IdentStr& obj2)
{
    std::cout << "DecStr \"==\" operator called" << std::endl;
    return (obj1.m_str == obj2.m_str);
}

IdentStr::~IdentStr() {
    std::cout << this << " called IdentStr destructor" << std::endl;
}
