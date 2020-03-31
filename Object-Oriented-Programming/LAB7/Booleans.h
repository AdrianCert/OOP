#ifndef BOLEANS_H
#define BOLEANS_H

template <class T>
bool cmp(T x, T y)
{
    return x < y;
}
template<>
bool cmp <char*>(char* x, char* y) {
    int sum_x = 0;
    int sum_y = 0;
    for (int i = 0; x[i] != '\0'; i++)
    {
        sum_x += x[i];
    }
    for (int i = 0; y[i] != '\0'; i++)
    {
        sum_x += y[i];
    }
    return sum_x > sum_y;
}

template <class T>
bool eql(T x, T y)
{
    return x == y;
}

template<>
bool eql <char*>(char* x, char* y) {
    int i;
    for (i = 0; x[i] != '\0' && y[i] != '\0'; i++)
    {
        if (x[i] != y[i])
            return false;
    }
    if ((x[i] == '\0') xor (y[i] == '\0'))
    {
        return false;
    }
    return true;
}

#endif
