#include <stdexcept>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template <typename T>
class LinkedList : public List<T>
{
public:
    LinkedList() : count{}, head{}, tail{} {}

    ~LinkedList() { clear(); }

    void add(const T &item) override
    {
        tail = (empty() ? head = tail : tail->next) = new Node{item, nullptr};

        ++count;
    }

    void insert(const T &, size_t) override {}

    T remove(size_t pos) override
    {
        T item;
        Node *it{findNodeBefore(pos)};
        Node *remNode;

        if (it == nullptr)
            return remove();

        remNode = it->next;

        if (remNode == tail)
            tail = it;

        it->next = remNode->next;

        item = remNode->item;

        delete remNode;

        --count;

        return item;
        ;
    }

    T remove() override
    {
        T item;
        Node *tmp{head};

        if (empty())
            throw std::runtime_error("remove on empty list");

        item = head->item;
        head = head->next;

        delete tmp;

        --count;

        if (empty())
            tail = nullptr;

        return item;
    }

    void replace(const T &item, size_t pos)
    {
        findNodeAt(pos)->item = item;
    }

    T at(size_t pos) const override
    {
        return findNodeAt(pos)->item;
    }

    //linear search O(n) 
    bool contains(const T &item) const override
    {
        Node *it = head;

        while (it != nullptr)
        {
            if (it->item == item)
                return true;

            it = it->next;
        }

        return false;
    }

    size_t size() const override { return count; }

    bool empty() const override { return count == 0; } // ask about this

    void clear()
    {
        Node *tmp;

        while (head != nullptr)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }

        tail = nullptr;
        count = 0;
    }

private:
    struct Node // data transfer object or plain old java object
    {
        T item;
        Node *next;
    };

    Node *findNodeBefore(size_t pos) const
    {
        Node *it{head};

        if (pos < 1 || pos > count)
            throw std::out_of_range("invalid position on remove");

        while (pos-- > 2)
        {
            it = it->next;
        }

        return it;
    }

    Node *findNodeAt(size_t pos) const
    {
        if (pos == 1)
            return head;
        if (pos == count)
            return tail;
        return findNodeBefore(pos)->next;
    }

    size_t count;
    Node *head;
    Node *tail;
};

#endif