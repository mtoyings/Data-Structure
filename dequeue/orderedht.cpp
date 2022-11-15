#include <iostream>
#include <cmath>
#include <vector>
#include "orderedht.h"

HashTable::~HashTable()
{
    for (int i = 0; i < capacity; i++)
    {
        while (table[i].p_head != nullptr)
        {
            Node *p_traverse{table[i].p_head};
            table[i].p_head = table[i].p_head->next;
            delete p_traverse;
        }
        delete table[i].p_head;
    }
}

void HashTable::create(unsigned int size)
{

    table.resize(size);
    capacity = size;

    std::cout << "success" << std::endl;
}

void HashTable::insert(unsigned int studentNum, std::string name)
{
    int h1 = studentNum % capacity;
    Node *head_p = table[h1].p_head;

    insert_front(studentNum, name, table[h1].p_head);
}

void HashTable::search(unsigned int studentNum)
{

    int h1 = studentNum % capacity;

    if (table[h1].p_head == nullptr)
    {
        std::cout << "not found" << std::endl;
        return;
    }

    if (table[h1].p_head != nullptr)
    {
        Node *p_traverse = table[h1].p_head;

        while (p_traverse != nullptr)
        {
            if (p_traverse->value.studentNumber == studentNum)
            {
                std::string lastName = p_traverse->value.studentName;
                std::cout << "foud " << lastName << " in " << h1 << std::endl;
                return;
            }
            p_traverse = p_traverse->next;
        }
    }

    std::cout << "not found" << std::endl;
}

void HashTable::remove(unsigned int studentNum)
{

    int h1 = studentNum % capacity;
    extract(studentNum, table[h1].p_head);
}

void HashTable::printChain(unsigned int pos)
{

    if (table[pos].p_head == nullptr || pos > capacity - 1)
    {
        std::cout << "chain is empty" << std::endl;
        return;
    }
    Node *p_traverse = table[pos].p_head;

    while (p_traverse != nullptr)
    {
        std::cout << p_traverse->value.studentNumber << " ";
        p_traverse = p_traverse->next;
    }

    std::cout << std::endl;
}
