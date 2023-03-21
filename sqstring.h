#ifndef SQSTRING_H
#define SQSTRING_H
#include <iostream>
#define _MAX_SIZE_ 100

typedef class SqString
{
    char* s;
    size_t size;
public:
    SqString();
    SqString(char* _s);
    SqString(SqString &_str);

    size_t length()const;
    bool isEqualTo(SqString& _s)const;
    bool isEmpty()const;
    SqString append(char* _s);

    char& operator[](int i)const;
    bool operator==(SqString& _str)const;
    void operator=(char* _str);
    void operator=(SqString& _str);
}string;

#endif // SQSTRING_H
