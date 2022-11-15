#include <iostream>
#include <sstream>

#include "projectdriver.h"


Node::Node()
{
    value = "";
    prev = nullptr;
    next = nullptr;
}

Node::~Node()
{
    prev = nullptr;
    next = nullptr;
}


DoublyLinkedList::DoublyLinkedList()
{
    p_tail = nullptr;
    p_head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while ((get_head() != nullptr))
    {
        Node *p_traverse{get_head()};
        set_head(get_head()->next);
        delete p_traverse;
    }
    delete p_tail;
    delete p_head;
}

Node *DoublyLinkedList::get_head()
{
    return p_head;
}

Node *DoublyLinkedList::get_tail()
{
    return p_tail;
}

void DoublyLinkedList::set_head(Node *element)
{
    p_head = element;
}

void DoublyLinkedList::set_tail(Node *element)
{
    p_tail = element;
}


void DoublyLinkedList::insert_front(const std::string name, const std::string link)
{
    Node *new_node = new Node;
    new_node->value = name + " " + link;
    if (get_head() != nullptr)
    {
        new_node->next = p_head;
        p_head->prev = new_node;
        p_head = new_node;
    }
    else
    {
        p_head = new_node;
        p_tail = new_node;
    }
    std::cout << "success" << std::endl;
}

void DoublyLinkedList::insert_back(const std::string name, const std::string link)
{
    Node *new_node = new Node;
    new_node->value = name + " " + link;
    if (get_head() != nullptr)
    {
        new_node->prev = p_tail;
        p_tail->next = new_node;
        p_tail = new_node;
    }
    else
    {
        p_head = new_node;
        p_tail = new_node;
    }
    std::cout << "success" << std::endl;
}

void DoublyLinkedList::remove_front()
{

    if (get_head() != nullptr)
    {
        Node *p_temp = get_head();
        if(get_head()->next != nullptr){
            p_head = (get_head()->next);
            p_head->prev = nullptr;
        }
        else
        {
            set_tail(nullptr);
            set_head(nullptr);
        }

        delete p_temp;
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
}

void DoublyLinkedList::remove_tail()
{
    if (get_head() != nullptr)
    {
         Node *p_temp = get_tail();
        if(get_tail()->prev != nullptr){
            set_tail(get_tail()->prev);
            get_tail()->next = nullptr;
        }
        else
        {
            set_tail(nullptr);
            set_head(nullptr);
        }
        delete p_temp;
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
}

void DoublyLinkedList::find(const std::string element)
{
    if (get_head() != nullptr)
    {
        Node *p_traverse = get_head();

        while (p_traverse != nullptr)
        {
            std::stringstream URLNameURL(p_traverse->value);
            std::string URLName;
            getline(URLNameURL, URLName, ' ');
            if (URLName == element)
            {
                std::cout << "found " << p_traverse->value << std::endl;
                return;
            }
            p_traverse = p_traverse->next;
        }
        std::cout << "not found " << element << std::endl;
    }
    else
    {
        std::cout << "not found " << element << std::endl;
    }

}

void Deque::m(const int N)
{
    max_size = N;
    std::cout << "success \n";
}

void Deque::isEmpty()
{
    std::cout << "empty " << ((get_head() == nullptr) && (get_tail() == nullptr)) << std::endl;
}

void Deque::print()
{   if((get_head() == nullptr) && (get_tail() == nullptr)){
    std::cout << "deque is empty" << std::endl;
    return;
    }
    Node *p_printing = get_tail();
    while (p_printing != nullptr)
    {
        std::cout << p_printing->value << std::endl;
        p_printing = p_printing->prev;
    }
}

void Deque::clear()
{
    while (get_head() != nullptr)
    {
        Node *p_traverse{get_head()};
        set_head(get_head()->next);
        delete p_traverse;
    }
    delete p_head;
    set_tail(nullptr);
    size = 0;
    std::cout << "success" << std::endl;
}

void Deque::push_front(const std::string name, const std::string link){
    if (size == max_size)
    {
        Node * tmp = get_tail();
        set_tail(get_tail()->prev) ;
        delete tmp;
        get_tail()->next = nullptr;
        size--;
    }
    insert_front(name, link);
    size++;
}
void Deque::push_back(const std::string name, const std::string link) {
    if (size == max_size)
    {
        Node * tmp = get_head();
        set_head(get_head()->next);
        delete tmp;
        get_head()->prev = nullptr;
        size--;
    }
    insert_back(name, link);
    size++;

}

void Deque::print_size() {
    std::cout << "size is " << size << std::endl;
}

void Deque::decrease_size() {
    size--;
}


int Deque::get_size() {
    return size;
}
