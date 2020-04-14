#include<stdio.h>
#include "Map.h"
#include <vector>
int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[200] = "max";
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }


    m.Delete(20);
    printf("\nShow after delete \n");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[201] = "Mac";
    m[404] = "Not Found";
    int key_set = 55;
    const char * val_set= "Masina";
    m.Set(key_set,val_set);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    Map<int, const char*> n;

    n[10] = "C++";
    n[30] = "Poo";
    printf("\nm.Includes(n) = %d \n", m.Includes(n));

    return 0;
}