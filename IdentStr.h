#ifndef EXAM_IDENTSTR_H
#define EXAM_IDENTSTR_H

class IdentStr :public String {
public:
    IdentStr(int = 0);                                              // Конструктор по длине
    IdentStr(char);                                                 // Конструктор по символу
    IdentStr(const char*);                                          // Конструктор по указателю на С-строку
    IdentStr(const IdentStr&);                                      // Конструктор копирования
    ~IdentStr();                                                    // Destructor
    IdentStr& operator=(const IdentStr&);                           // Присваивание
    char& operator[](int);                                         // Доступ по индексу
    IdentStr operator~();                                           // Переворот строки
    IdentStr ToCapital();                                           // Перевод строчных символов в верхний регистр
    friend IdentStr operator+(const IdentStr&, const IdentStr&);    // Конкатенация двух обьектов
    friend IdentStr operator+(const IdentStr&, const char*);        // Конкатенация обьекта и строки
    friend IdentStr operator+(const char*, const IdentStr&);        // Конкатенация строки и обьекта
    friend bool operator == (const IdentStr&, const IdentStr&);     // Сравнение
};

#endif //EXAM_IDENTSTR_H