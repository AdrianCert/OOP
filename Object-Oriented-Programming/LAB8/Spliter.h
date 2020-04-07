#include <vector>
#include <string>
#ifndef SPLITER_H
#define SPLITER_H

bool def(char c) { return c == ' ' || c == '!' || c == '?' || c == '.' || c == ','; }

int split(std::vector<std::string>& results, std::string text,bool lowering = false,  bool (*funct)(char) = nullptr)
{
    std::string key = "";
    char c;

    if (funct == nullptr) funct = def;

    for (int i = 0; i < text.length(); i++)
    {
        c = text[i];
        if (!funct(c))
        {
            if (lowering && c <= 'Z' && c >= 'A')
                c = c - ('A' - 'a');
            key += c;
        }
        else if (key.length() > 0) {
            results.push_back(key);
            key = "";
        }
    }
	return 1;
}

#endif // !SPLITER_H
