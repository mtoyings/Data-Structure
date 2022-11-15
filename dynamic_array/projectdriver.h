#include <iostream>
#include <sstream>

class Node
{
public:
    std::string value;
    Node *prev;
    Node *next;
    Node();
    ~Node();
};

class DoublyLinkedList
{
protected:
    Node *p_head;
    Node *p_tail;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    Node *get_head();
    Node *get_tail();
    void set_head(Node *element);
    void set_tail(Node *element);
    void insert_front(const std::string name, const std::string link);
    void insert_back(const std::string name, const std::string link);
    void remove_front();
    void remove_tail();
    void find(const std::string element);
};

class Deque : public DoublyLinkedList
{
private:
    int size{};
    int max_size{};

public:
    void m(int N);
    void isEmpty();
    void print();
    void clear();
    void print_size();
    void decrease_size();
    int get_size();
    void push_front(const std::string name, const std::string link);
    void push_back(const std::string name, const std::string link);
};
