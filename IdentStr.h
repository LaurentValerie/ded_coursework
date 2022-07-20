#ifndef EXAM_IDENTSTR_H
#define EXAM_IDENTSTR_H

class IdentStr :public String {
public:
    IdentStr(int = 0);                                              // ����������� �� �����
    IdentStr(char);                                                 // ����������� �� �������
    IdentStr(const char*);                                          // ����������� �� ��������� �� �-������
    IdentStr(const IdentStr&);                                      // ����������� �����������
    ~IdentStr();                                                    // Destructor
    IdentStr& operator=(const IdentStr&);                           // ������������
    char& operator[](int);                                         // ������ �� �������
    IdentStr operator~();                                           // ��������� ������
    IdentStr ToCapital();                                           // ������� �������� �������� � ������� �������
    friend IdentStr operator+(const IdentStr&, const IdentStr&);    // ������������ ���� ��������
    friend IdentStr operator+(const IdentStr&, const char*);        // ������������ ������� � ������
    friend IdentStr operator+(const char*, const IdentStr&);        // ������������ ������ � �������
    friend bool operator == (const IdentStr&, const IdentStr&);     // ���������
};

#endif //EXAM_IDENTSTR_H