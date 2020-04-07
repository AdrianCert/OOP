#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "Spliter.h"
#include <queue>

class lexicographic_order
{
    bool reverse;
public:
    lexicographic_order(const bool& _rev = false)
    {
        reverse = _rev;
    }
    bool operator() ( std::pair<std::string, unsigned int> & left, std::pair<std::string, unsigned int>& right)
    {
        if (left.second != right.second)
        {
            return (bool)(left.second > right.second) xor !reverse;
        }
        for (int i = 0; i < left.first.length(); i++)
        {
            if (left.first[i] != right.first[i])
            {
                return (bool)(left.first[i] < right.first[i]) xor !reverse;
            }
        }
        return (bool)(left.first.length() > right.first.length()) xor reverse;
    }
};

void showpq(std::priority_queue<std::pair<std::string, unsigned int>, std::vector<std::pair<std::string, unsigned int>>, lexicographic_order> gq)
{
    auto g = gq;
    std::cout << "-------------------------------" << std::endl;
    while (!g.empty())
    {
        std::cout << '\t' << g.top().first <<  " => " << g.top().second << std::endl;
        g.pop();
    }
    std::cout << "-------------------------------" << std::endl;
}

int main()
{
    std::string phrase;
    std::ifstream file("Text.txt");
    if (file.is_open())
    {
        while (getline(file, phrase))
        {
            std::cout << "Phrase read: " << std::endl;
            std::cout << phrase << std::endl << std::endl;

            std::vector<std::string> words;
            std::map<std::string, unsigned int> results;
            std::priority_queue<std::pair<std::string, unsigned int>, std::vector<std::pair<std::string, unsigned int>>, lexicographic_order> que;

            std::cout << "\t--> Split in words" << std::endl;
            split(words, phrase, true, [](char c) { return c == ' ' || c == '!' || c == '?' || c == '.' || c == ','; });

            std::cout << "\t--> Map words" << std::endl;
            for (std::vector<std::string>::iterator i = words.begin(); i != words.end(); i++)
            {
                results[*i]++;
            }

            std::cout << std::endl << "Map containts \n{" << std::endl;
            for (auto key : results)
            {
                std::cout << "\t" << key.first << " : " << key.second << std::endl;
                
            }
            std::cout << "}" << std::endl << std::endl;

            for (std::map<std::string, unsigned int>::iterator i = results.begin(); i != results.end(); i++)
            {
                std::cout << "\t--> Add in priority queue ( ";
                std::cout << i->first << " : " << i->second << " )" <<std::endl;

                que.push(std::make_pair(i->first, i->second));
            }
            std::cout << std::endl << "Rezult:" << std::endl;
            showpq(que);
        }
        file.close();
    }

	return 0;
}