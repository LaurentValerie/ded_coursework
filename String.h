#ifndef EXAM_STRING_H
#define EXAM_STRING_H

class String {
public:
    String(int = 0);                            // ����������� �� ����� ������
    String(char);                               // ����������� �� ������ �������
    String(const char*);                        // ����������� �� ��������� �� �-������
    String(const String&);                      // ����������� �����������
    ~String();                                   // ����������
    char* GetStr()const { return m_str; }       // ���������� ��������� �� ������
    int GetLen()const { return m_len; }         // ���������� ����� ������
    void Show();                                // ����� ������ � �� �����
    bool IsEmpty();                             // �������� ����� �� ������

protected:                                      // ������ ������, �������� � �������
    int m_len = 0;                              // ����� ������
    char* m_str;                                // ��������� �� ���������� ��� ������ ������
};

#endif //EXAM_STRING_H