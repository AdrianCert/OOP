#ifndef NUMBER_H
#define NUMBER_H

class Number
{
    short* num = nullptr;
    int count = 0;
    int baze = 0;
    int isNegative = false;
    int commaPosition = -1;
    
    // return the char reprezentation for a a digit // max 15
    int getCValue(int index);
    // return the int number for char reprezentation of digit
    int getIntValue(const char c);
    // sum of digits a and b, result in a, return value of overflow
    bool digitSum(int & a, int b);
    
    Number() = default;
public:
    // Create a Number class with the @value in baze @base
    Number(const char* value, int base);
    Number(const Number& old_num);
    Number(Number && old_num);
    // Distroy instace
    ~Number();

    // Logical Operators

    bool operator==(Number other);
    bool operator>(Number other);
    bool operator<(Number other);
    bool operator<=(Number other);
    bool operator>=(Number other);
    bool operator!=(Number other);

    Number operator+(Number& i);
    Number operator-(Number& i);
    int operator[](int i);
    void operator=(Number & other);
    void operator=(Number && other);

    void SwitchBase(int newBase);
    void Print();
    // returns the number of digits for the current number
    int  GetDigitsCount();
    // return the number sign
    int  GetSign();
    // returns the current base
    int  GetBase();
};

#endif // !NUMBER_H