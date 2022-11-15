#include <iostream>
#include <vector>
#include "chainingList.h"

class HashTable : public LinkedList
{
private:
    std::vector<LinkedList> table;
    int capacity = 0;

public:
    ~HashTable();
    void create(unsigned int size);
    void insert(unsigned int studentNum, std::string name);
    void search(unsigned int studentNum);
    void remove(unsigned int studentNum);
    void printChain(unsigned int pos);
};
