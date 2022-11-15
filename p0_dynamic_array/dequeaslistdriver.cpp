#include <iostream>
#include <sstream>

#include "projectdriver.h"

int main()
{
    Deque project1;
    std::string input;

    std::string inputs;

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
            project1.m(stoi(inputline[1]));
        }
        else if (inputline[0] == "push_front")
        {
            project1.push_front(inputline[1], inputline[2]);
        }
        else if (inputline[0] == "push_back")
        {
            project1.push_back(inputline[1], inputline[2]);
        }
        else if (inputline[0] == "pop_front")
        {
            project1.remove_front();
            if(project1.get_size() > 0)
            {
                project1.decrease_size();
            }
        }
        else if (inputline[0] == "pop_back")
        {
            project1.remove_tail();
            if(project1.get_size() > 0)
            {
                project1.decrease_size();
            }
        }
        else if (inputline[0] == "clear")
        {
            project1.clear();
        }
        else if (inputline[0] == "size")
        {
            project1.print_size();
        }
        else if (inputline[0] == "front")
        {
            if (project1.get_head() == nullptr)
            {
                std::cout << "failure \n";
            }
            else
            {
                std::cout << "front is " << project1.get_head()->value << std::endl;
            }
        }
        else if (inputline[0] == "back")
        {
            if (project1.get_tail() == nullptr)
            {
                std::cout << "failure \n";
            }
            else
            {
                std::cout << "back is " << project1.get_tail()->value << std::endl;
            }
        }
        else if (inputline[0] == "empty")
        {
            project1.isEmpty();
        }
        else if (inputline[0] == "find")
        {
            project1.find(inputline[1]);
        }
        else if (inputline[0] == "print")
        {
            project1.print();
        }
        else if (inputline[0] == "exit")
        {
            return 0;
        }
    }
    return 0;
}