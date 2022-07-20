#ifndef EXAM_STRING_H
#define EXAM_STRING_H

class String {
public:
    String(int = 0);                            // Конструктор по длине строки
    String(char);                               // Конструктор из одного символа
    String(const char*);                        // Конструктор из указателя на С-строку
    String(const String&);                      // Конструктор копирования
    ~String();                                   // Деструктор
    char* GetStr()const { return m_str; }       // Возвращает указатель на строку
    int GetLen()const { return m_len; }         // Возвращает длину строки
    void Show();                                // Вывод строки и ее длины
    bool IsEmpty();                             // Проверка пуста ли строка

protected:                                      // Членам класса, потомкам и друзьям
    int m_len = 0;                              // Длина строки
    char* m_str;                                // Указатель на выделенную под строку память
};

#endif //EXAM_STRING_H