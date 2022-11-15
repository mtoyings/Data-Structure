#include <iostream>
#include <vector>

class StudentRecords
{
public:
    int studentNumber = 0;
    std::string studentName = "";
};

class HashTable
{
public:
    void create(unsigned int size);
    void insert(unsigned int studentNum, std::string name);
    void search(unsigned int studentNum);
    void remove(unsigned int studentNum);

private:
    std::vector<StudentRecords> table;
    int capacity = 0;
    int currentSize = 0;
};
