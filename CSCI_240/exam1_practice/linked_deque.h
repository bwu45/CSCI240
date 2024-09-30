#include <stdexcept>

#include "deque.h"

#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

template <typename T>
class LinkedDeque : public Deque<T>
{
public:
    LinkedDeque() : head{}, tail{} {}

    ~Deque() override {}

    void addFront(const T &item) override
    {
        Node *newNode = new Node{item, head, nullptr};

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }

        head->back = newNode;
        newNode->next = head;
        head = newNode;
    }

    void addBack(const T &item) override
    {
        Node *newNode = new Node{item, nullptr, tail};

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }

        tail->next = newNode;
        newNode->back = tail;
        tail = newNode;
    }

    T removeFront() override
    {
        if (empty())
            throw std::runtime_error("removeFront on empty linked deque");

        Node *tmp = head;
        T item;

        head = head->next;
        item = tmp->item;

        if (head == nullptr)
            tail = nullptr;

        delete tmp;

        return item;
    }

    T removeBack() override
    {
        if (empty())
            throw std::runtime_error("removeBack on empty linked deque");

        Node *tmp = tail;
        T item = tmp->item;

        tail = tail->back;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        delete tmp;

        return item;
    }

    T peekFront() const override
    {
        if (empty())
            throw std::runtime_error("peekFront on empty linked deque");

        return head->item;
    }

    T peekBack() const override
    {
        if (empty())
            throw std::runtime_error("peekBack on empty linked deque");

        return tail->item;
    }

    T contains(const T &item) const override
    {
        // walk the list
        Node *tmp = head;
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
            removeFront();
    }

private:
    struct Node
    {
        T item;
        Node *next;
        Node *back;
    };

    Node *head;
    Node *tail;
};

#endif // !LINKED_DEQUE_H
