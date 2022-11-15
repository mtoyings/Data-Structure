#include <iostream>
#include <sstream>
#include "chainingList.h"

Node::Node()
{
    next = nullptr;
}

Node::~Node()
{
    next = nullptr;
}

LinkedList::LinkedList()
{
    p_head = nullptr;
}

LinkedList::~LinkedList()
{
    while (p_head != nullptr)
    {
        Node *p_traverse{p_head};
        p_head = p_head->next;
        delete p_traverse;
    }
    delete p_head;
}

bool LinkedList::isFound(unsigned int studentNum, Node *head)
{

    if (head != nullptr)
    {
        Node *p_traverse = head;

        while (p_traverse != nullptr)
        {
            if (p_traverse->value.studentNumber == studentNum)
            {
                return true;
            }
            p_traverse = p_traverse->next;
        }
    }
    return false;
}

void LinkedList::insert_front(unsigned int studentNum, std::string lastName, Node *&head_p)
{

    Node *new_node = new Node;
    new_node->value.studentName = lastName;
    new_node->value.studentNumber = studentNum;

    if (head_p == nullptr)
    {
        head_p = new_node;
        std::cout << "success" << std::endl;
        return;
    }
    if (isFound(studentNum, head_p))
    {
        delete new_node;
        std::cout << "failure" << std::endl;
        return;
    };

    new_node->next = head_p;
    head_p = new_node;

    std::cout << "success" << std::endl;
}

void LinkedList::extract(unsigned int studentNum, Node *&head_p)
{
    if (head_p == nullptr)
    {
        std::cout << "failure" << std::endl;
        return;
    }
    Node *p_temp = nullptr;

    if (head_p != nullptr && head_p->value.studentNumber == studentNum)
    {
        p_temp = head_p;
        if (head_p->next != nullptr)
        {
            head_p = head_p->next;
        }
        delete p_temp;
        std::cout << "success" << std::endl;

        return;
    }
    else
    {
        Node *p_traverse = head_p;
        while (p_traverse != nullptr)
        {
            if (p_traverse->value.studentNumber == studentNum)
            {
                p_temp->next = p_traverse->next;
                delete p_traverse;
                std::cout << "success" << std::endl;
                return;
            }
            p_temp = p_traverse;           // prev
            p_traverse = p_traverse->next; // curr
        }
        std::cout << "failure" << std::endl;

        return;
    }
}