#include "sqstring.h"

SqString::SqString()
{
    s = (char*)malloc(sizeof(char)*_MAX_SIZE_ );
    size = 0;
}


SqString::SqString(char* _str){
    this->s = (char*)malloc(sizeof(char)*_MAX_SIZE_ );
    *this = _str;
}
SqString::SqString(SqString &_str){
    this->s = (char*)malloc(sizeof(char)*_MAX_SIZE_ );
    *this = _str;
}

size_t SqString::length()const{
    return this->size;
}

bool SqString::isEqualTo(SqString& _str)const{
    return *this == _str;
}

bool SqString::isEmpty()const{
    return this->size == 0;
}

char& SqString::operator[](int i)const{
    return this->s[i];
}

bool SqString::operator==(SqString &_str)const{
    if (this->length() != _str.length())
        return false;
    for (int i = 0; i < this->length(); i++){
        if (this->s[i] != _str.s[i])
            return false;
    }
    return true;
}

void SqString::operator=(char* _str){
    int index = 0;
    while (_str[index] != '\0'){
        this->s[index] = _str[index];
        index++;
    }
    this->s[index] = '\0';
    this->size = index;
}

void SqString::operator=(SqString& _str){
    for (int i = 0; i < _str.length(); i++){
        this->s[i] = _str[i];
    }
    this->size = _str.length();
}
