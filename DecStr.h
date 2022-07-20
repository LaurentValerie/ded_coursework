#ifndef EXAM_DECSTR_H
#define EXAM_DECSTR_H

class DecStr : public String {
public:
    DecStr(int = 0);                                            // ����������� �� �����
    DecStr(char);                                               // ����������� �� �������
    DecStr(const char*);                                        // ����������� �� ��������� �� �-������
    DecStr(const DecStr&);                                      // ����������� �����������
    ~DecStr();                                                  // ����������
    DecStr& operator=(const DecStr&);                           // ������������
    friend DecStr operator + (const DecStr&, const DecStr&);    // object + object
    friend DecStr operator + (const DecStr&, const int);        // object + number (int)
    friend DecStr operator - (const DecStr&, const DecStr&);    // object - object
    friend bool operator == (const DecStr&, const DecStr&);     // ���������
};

#endif //EXAM_DECSTR_H