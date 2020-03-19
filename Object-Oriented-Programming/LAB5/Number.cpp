#include "Number.h"
#include <iostream>

Number::Number(const char* _value, int _base)
{
    if (_value[0] == '-')
        isNegative = true;
    while (_value[count] != '\0')
    {
        if (_value[count] == ',') {
            commaPosition = count - isNegative;
        }
        count++; 
    }

    count = isNegative ? count-- : count;
    count = commaPosition != -1 ? count-- : count;
    num = new short[count + 1];
    baze = _base;
    bool com_i_skip = false;
    for(int i = isNegative; i < count + isNegative; i++)
    {
        if (_value[i] == ',') {
            com_i_skip = true;
            continue;
        }
        num[i - isNegative - com_i_skip] = getIntValue(_value[i]);
    }
}

Number::Number(const Number& old_num)
{
    count = old_num.count;
    baze = old_num.baze;
    commaPosition = old_num.commaPosition;
    num = new short[count];
    for (int i = isNegative; i < count; i++)
    {
        num[i] = old_num.num[i];
    }
}

 
Number::Number(Number && other)
{
    num = other.num;
    this->baze = other.baze;
    this->count = other.count;
    this->isNegative = other.isNegative;
    this->commaPosition = other.commaPosition;
    other.num = nullptr;
}

Number::~Number()
{
    if (num != nullptr)
    {
        delete[] num;
    }
    num = nullptr;
}

bool Number::operator==(Number other)
{
    if (isNegative != other.isNegative)
        return false;
    if (commaPosition != other.commaPosition)
        return false;
    if (count != other.count) {
        return false;
    }
    else {
        if (baze != other.baze) {
            return false;
            // sau convertim bazele
        }
        for (int i = 0; i < count; i++) {
            if (num[i] != other.num[i])
                return false;
        }
    }
    return true;
}

bool Number::operator>(Number other)
{
    if (operator==(other))
        return false;
    if (isNegative && !other.isNegative)
        return false;
    if (commaPosition == -1 ? count + 1 : commaPosition < other.commaPosition == -1 ? other.count + 1 : other.commaPosition)
        return false;
    for (int i = commaPosition - 1; i >= 0; i--) 
        if (num[i] <= other.num[i])
            return false;
    for (int i = commaPosition; i < count; i++)
        if (num[i] <= other.num[i])
            return false;
    return true;
}

bool Number::operator<(Number other)
{
    if (operator==(other))
        return false;
    if (!isNegative && other.isNegative)
        return false;
    if (commaPosition == -1 ? count + 1 : commaPosition > other.commaPosition == -1 ? other.count + 1 : other.commaPosition)
        return false;
    for (int i = commaPosition - 1; i >= 0; i--)
        if (num[i] >= other.num[i])
            return false;
    for (int i = commaPosition; i < count; i++)
        if (num[i] >= other.num[i])
            return false;
    return true;
}

bool Number::operator<=(Number other)
{
    return !operator>(other);
}

bool Number::operator>=(Number other)
{
    return !operator<(other);
}

bool Number::operator!=(Number other)
{
    return !operator==(other);
}

int Number::operator[](int _i)
{
    if (_i > count || _i < 0) return -1;
    return getCValue(num[_i]);
}

Number Number::operator+(Number& _i)
{
    if (this->isNegative xor _i.isNegative)
        std::cout << "call - operator";

    Number rez;
    int a, b;
    bool of = false;

    rez.count =  this->count > _i.count ?
        this->count : _i.count;
    
    rez.isNegative = isNegative;
    rez.num = new short[rez.count + 1];

    for (int i = 0; i <= rez.count; i++)
    {
        a = getIntValue((*this)[this->count - 1 - i]);
        if (a == -1) a = 0;
        b = getIntValue(_i[_i.count - 1 - i]);
        if (b == -1) b = 0;
        
        of = digitSum( a, b + of);
        rez.num[rez.count - i] = a;
    }

    if (rez.num[0] == 0)
    {
        short* rez_shifted = new short[rez.count];
        for (int i = 1; i <= rez.count; i++)
            rez_shifted[i - 1] = rez.num[i];
        delete[] rez.num;
        rez.num = rez_shifted;
        
        // std::cout << "curent count " << rez.count << std::endl;
        // .Print();
        return rez;
    }

    rez.count++;
    
    // std::cout << "curent count " << rez.count << std::endl;
    // rez.Print();
    return rez;
}

// to be implemented
Number Number::operator-(Number& _i)
{
    Number rez;
    if (this->isNegative xor _i.isNegative) {
        rez.operator=(*this);
        _i.isNegative = rez.isNegative;
        return rez.operator+(_i);
    }
    //int a, b;
    //bool of = false;

    //rez.count = this->count > _i.count ?
    //    this->count : _i.count;

    //rez.num = new short[rez.count + 1];

    //for (int i = 0; i <= rez.count; i++)
    //{
    //    a = getIntValue((*this)[this->count - 1 - i]);
    //    if (a == -1) a = 0;
    //    b = getIntValue(_i[_i.count - 1 - i]);
    //    if (b == -1) b = 0;

    //    of = digitSum(a, b + of);
    //    rez.num[rez.count - i] = a;
    //}

    //if (rez.num[0] == 0)
    //{
    //    short* rez_shifted = new short[rez.count];
    //    for (int i = 1; i <= rez.count; i++)
    //        rez_shifted[i - 1] = rez.num[i];
    //    delete[] rez.num;
    //    rez.num = rez_shifted;

    //    // std::cout << "curent count " << rez.count << std::endl;
    //    // .Print();
    //    return rez;
    //}

    //rez.count++;
}

void Number::operator=(Number & other) {
    this->baze = other.baze;
    this->count = other.count;
    this->isNegative = other.isNegative;

    if (this->num != nullptr) delete[] num;
    num = new short[count];
    for (int i = 0; i < count; i++)
    {
        num[i] = other.num[i];
    }
}

void Number::operator=(Number && other) {
    this->baze = other.baze;
    this->count = other.count;
    this->isNegative = other.isNegative;
    num = other.num;
    other.num = nullptr;
}

// have to be implemented
void Number::SwitchBase(int newBase)
{

}

void Number::Print()
{
    if (isNegative)
        std::cout << "-";
    for (int i = 0; i < count; i++)
    {
        if (i == commaPosition) std::cout << ',';
        std::cout << (char)getCValue(num[i]);
    }
    std::cout << std::endl;
}

int Number::GetDigitsCount()
{
    return count;
}

int Number::GetSign()
{
    return isNegative;
}

int Number::GetBase()
{
    return baze;
}

int Number::getCValue(int _index) {
    if (_index >= 0) {
        if (_index < 10)
            return '0' + _index;
        if (_index < 16)
            return 'A' - 10 + _index;
    }
    return '\0';
}

int Number::getIntValue(const char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

bool Number::digitSum(int & _a, int _b) {
    _a = _a + _b;
    if (_a < baze)
        return false;
    _a = _a % baze;
    return true;
}
