#include "empty_queue_exception.h"
#include "queue.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template <typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : head{}, tail{} {} // list initialization, helps to have it up here for visual clarity

    ~LinkedQueue() { clear(); }

    void enqueue(const T &item)
    {
        if (empty())
        {
            tail = new Node{item, nullptr};
            head = tail;
        }
        else
        {
            tail->next = new Node{item, nullptr};
            tail = tail->next;
        }
    }

    void dequeue()
    {
        Node *tmp{head};

        if (empty())
            throw EmptyQueueException("dequeue on empty queue");

        head = head->next;
        delete tmp;

        if (empty())
            tail = nullptr;
    }

    T front() const
    {
        if (empty())
            throw EmptyQueueException("front on empty queue");
        return head->item;
        // return {}; // returns default value
    }

    bool empty() const
    {
        return head == nullptr;
    }

private:
    struct Node
    {
        T item;     // item
        Node *next; // pointer
    };

    void clear()
    {
        while (!empty())
            dequeue();
    }

    Node *head; // front of queue pointer
    Node *tail; // end of list pointer
};

#endif