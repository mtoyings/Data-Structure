#include <iostream>
#include <sstream>

class StudentRecords
{
public:
    int studentNumber = 0;
    std::string studentName = "";
};

class Node
{
public:
    StudentRecords value;
    Node *next;
    Node();
    ~Node();
};

class LinkedList
{
private:
    Node *p_head;

public:
    ~LinkedList();
    LinkedList();
    void insert_front(unsigned int studentNum, std::string lastName, Node *&head_p);
    void extract(unsigned int studentNum, Node *&head_p);
    bool isFound(unsigned int studentNum, Node *head);

    friend class HashTable;
};
