#ifndef EXAM_DECSTR_H
#define EXAM_DECSTR_H

class DecStr : public String {
public:
    DecStr(int = 0);                                            // Конструктор по длине
    DecStr(char);                                               // Конструктор по символу
    DecStr(const char*);                                        // Конструктор по указателю на С-строку
    DecStr(const DecStr&);                                      // Конструктор копирования
    ~DecStr();                                                  // Деструктор
    DecStr& operator=(const DecStr&);                           // Присваивание
    friend DecStr operator + (const DecStr&, const DecStr&);    // object + object
    friend DecStr operator + (const DecStr&, const int);        // object + number (int)
    friend DecStr operator - (const DecStr&, const DecStr&);    // object - object
    friend bool operator == (const DecStr&, const DecStr&);     // Сравнение
};

#endif //EXAM_DECSTR_H