#include <cstddef>
#include <stdexcept>

#ifndef STACK_H
#define STACK_H

template <typename T>
class LinkedStack
{
public:
    LinkedStack() : head{} {}

    ~LinkedStack() { while(!empty()) pop(); } 
    
    void push(const T &item) // T is passed as reference
    {
        head = new Node{item, head};
    }

    void pop() // don't forget to delete the node as well
    {
        if (empty())
            throw std::runtime_error("pop on an empty stack");

        Node *tmp = head;
        head = head->next;
        delete tmp;
    }

    T peek()
    {
        if (empty())
            throw std::runtime_error("peek on an empty stack");

        return head->item;
    }

    bool empty()
    {
        return head == nullptr;
    }

private:
    struct Node
    {
        T item;
        Node *next;
    };

    Node *head;
};

#endif /* STACK_H */