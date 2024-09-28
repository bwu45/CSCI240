#include <stdexcept>

#include "list.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : count{}, head{}, tail{} {}

    ~LinkedList() { clear(); }

    void add(const T &item)
    {
        Node *newNode = new Node{item, nullptr};

        if (empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }

    void insert(const T &item, size_t index)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("index out of range");

        Node *insertNode = new Node{item, nullptr};

        if (index == 0)
        {
            add(item);
        }
        else
        {
            Node *current = head;
            for (size_t i = 0; i < index - 1; ++i)
            {
                current = current->next; // move the node down the list
            }
            insertNode->next = current->next; // current node points to next node
            current->next = insertNode;       // previous node points to current node

            if (insertNode->next == nullptr)
                tail = insertNode;
        }
        ++count;
    }

    T remove(size_t index)
    {
        Node *removalNode;
        T item;

        if (index == 0)
        {
            removalNode = head;
            item = removalNode->item;
            head = head->next;

            if (empty())
                tail = nullptr;
        }
        else
        {
            Node *current = head;
            for (size_t i = 0; i < index - 1; ++i)
            {
                current = current->next;
            }

            removalNode = current->next;
            item = removalNode->item;
            current->next = removalNode->next;

            if (current->next == nullptr)
                tail = current;
        }

        delete removalNode;
        --count;
        return item;
    }

    T remove()
    {
        Node *tmp{head};
        T item = tmp->item;
        head = head->next;

        delete tmp;

        if (empty())
            tail = nullptr;

        --count;
        return item;
    }

    void replace(const T &item, size_t index)
    {
        if (empty() || index < 0 || index > count)
            throw std::out_of_range("replace out of range");

        Node *replaceNode = head;

        for (size_t i = 0; i < index; ++i)
        {
            replaceNode = replaceNode->next;
        }

        replaceNode->item = item;
    }

    T at(size_t index) const
    {
        if (empty() || index < 0 || index > count)
            throw std::out_of_range("index out of range");

        Node *current = head;

        for (size_t i = 0; i < index; ++i)
        {
            current = current->next;
        }

        return current->item;
    }

    bool contains(const T &item) const
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->item == item)
                return true;
            else
                current = current->next;
        }

        return false;
    }

    size_t size() const { return count; }

    bool empty() const { return head == nullptr; }

    void clear()
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

    size_t count;
    Node *head;
    Node *tail;
};

#endif
