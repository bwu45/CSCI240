#include <stdexcept>

#include "barrel.h"

#ifndef LINKED_BARREL_H
#define LINKED_BARREL_H

template <typename T>
class LinkedBarrel : public Barrel<T>
{
public:
    LinkedBarrel() : head{} {}
    ~LinkedBarrel() { clear(); };

    void add(const T &item) { head = new Node{item, head}; }

    T remove()
    {
        if (empty())
            throw std::runtime_error("remove on empty barrel");

        return removeFirst();
    }

    void remove(const T &item)
    {
        Node *result{find(item, head)};
        if (result == nullptr)
            return;

        result->item = head->item;
        
        removeFirst();
    }

    // walking the list
    bool contains(const T &item) const
    {
        // return find(item);
        // recursive
        return find(item, head) != nullptr;
    }

    bool empty() const { return head == nullptr; };

    void clear()
    {
        Node *tmp{};
        while (!empty())
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }

private:
    struct Node
    {
        T item;
        Node *next;
    };

    T removeFirst()
    {
        Node *tmp{head};
        T item{head->item};

        head = head->next;
        delete tmp;

        return item;
    }

    // find(const T &item, Node* node) const
    // {
    //     Node *tmp{head};
    //     while (tmp != nullptr)
    //     {
    //         if (tmp->item == item)
    //             return true;
    //         tmp = tmp->next;
    //     }
    //     return false;
    // }

    // recursive
    Node *find(const T &item, Node *node) const
    {
        if (node == nullptr)
            return nullptr;
        if (node->item == item)
            return node;
        return find(item, node->next);
    }

    Node *head;
};

#endif