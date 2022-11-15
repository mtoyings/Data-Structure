#include <iostream>
#include <cmath>
#include <vector>
#include "openht.h"

void HashTable::create(unsigned int size)
{
    table.resize(size);
    capacity = size;

    std::cout << "success" << std::endl;
}

void HashTable::insert(unsigned int studentNum, std::string name)
{

    if (currentSize == capacity)
    {
        std::cout << "failure" << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i].studentNumber == studentNum)
            {
                std::cout << "failure" << std::endl;
                return;
            }
        }
    }

    int h1 = studentNum % capacity;
    int h2 = int(floor((studentNum / capacity))) % capacity;

    if (h2 % 2 == 0)
    {
        h2++;
    }

    if (table[h1].studentNumber == 0)
    {
        table[h1].studentNumber = studentNum;
        table[h1].studentName = name;
    }
    else
    {
        int temp = h1;
        int counter = 1;

        while (table[temp].studentNumber != 0)
        {
            temp = (h1 + counter * h2) % capacity;
            counter++;
        }
        table[temp].studentName = name;
        table[temp].studentNumber = studentNum;
    }

    currentSize++;
    std::cout << "success" << std::endl;
}

void HashTable::search(unsigned int studentNum)
{
    std::string lastName = "";
    int position = 0;

    while (table[position].studentNumber != studentNum)
    {
        if (position > capacity)
        {
            std::cout << "not found" << std::endl;
            return;
        }
        position++;
    }
    lastName = table[position].studentName;

    std::cout << "foud " << lastName << " in " << position << std::endl;
}

void HashTable::remove(unsigned int studentNum)
{
    for (int i = 0; i < capacity; i++)
    {
        if (table[i].studentNumber == studentNum)
        {
            table[i].studentNumber = 0;
            table[i].studentName = "";
            currentSize--;
            std::cout << "success" << std::endl;
            return;
        }
    }
    std::cout << "failure" << std::endl;
}
