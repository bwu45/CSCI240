#include <stdexcept>

#include "queue.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : head{}, tail{} {}

    ~LinkedQueue() { clear(); }

    void add(const T &item) override
    {
        Node *newNode = new Node{item, nullptr};

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;
    }

    T remove() override
    {
        if (empty())
            throw std::runtime_error("remove on empty linked queue");

        Node *tmp = head;
        T item;

        item = tmp->item;
        head = head->next;

        delete tmp;

        if (head == nullptr)
            tail = nullptr;

        return item;
    }

    T peek() const override
    {
        if (empty())
            throw std::runtime_error("peek on an empty linked queue");

        return head->item;
    }

    bool contains(const T &item) const override
    {
        // walking the list

        Node *tmp{head};

        while (tmp != nullptr)
        {
            if (tmp->item == item)
                return true;

            tmp = tmp->next;
        }

        return false;
    }

    bool empty() const override
    {
        return head == nullptr;
    }

    void clear() override
    {
        while (!empty())
            remove();
    }

private:
    struct Node
    {
        T item;
        Node *next;
    };

    Node *head;
    Node *tail;
};

#endif // !LINKED_QUEUE_H
