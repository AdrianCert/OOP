#ifndef CONVERSION_H
#define CONVERSION_H

float convChar(const char* val) {
    bool flagComaAp = false;
    float value = 0;
    float value_c = 0;
    float expo_c = 0.10f;
    while ((*val) != 0)
    {
        if (((*val) >= '0' && (*val) <= '9') || (*val) == '.')
        {
            if (flagComaAp)
            {
                value_c = value_c + ((*val) - '0') * expo_c;
                expo_c /= 10;
            }
            else if ((*val) == '.')
            {
                flagComaAp = true;
            }
            else
            {
                value = value * 10 + (*val) - '0';
            }
        }
        val++;
    }
    return value + value_c;
}

float operator"" _Kelvin(const char* val)
{
    return convChar(val) - 273.15f;
}

float operator"" _Fahrenheit(const char* val)
{
    return (convChar(val) - 32) / 1.8f;
}

#endif // !CONVERSION_h

