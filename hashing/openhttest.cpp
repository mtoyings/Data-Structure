#include <iostream>
#include "openht.h"
#include <sstream>

int main()
{

    HashTable tomato;

    std::string input;

    while (std::getline(std::cin, input))
    {
        std::string T;
        std::stringstream X(input);
        std::string inputline[3]{};
        int i{};

        while (std::getline(X, T, ' '))
        {
            inputline[i] = T;
            i++;
        }

        if (inputline[0] == "m")
        {
            tomato.create(stoi(inputline[1]));
        }
        else if (inputline[0] == "i")
        {
            tomato.insert(stoi(inputline[1]), inputline[2]);
        }
        else if (inputline[0] == "s")
        {
            tomato.search(stoi(inputline[1]));
        }
        else if (inputline[0] == "d")
        {
            tomato.remove(stoi(inputline[1]));
        }
    }
    return 0;
}