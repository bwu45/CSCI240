#include <stdexcept>

#include "list.h"

#ifndef ARRAY_LIST
#define ARRAY_LIST

#define INIT_SIZE 2
#define SCALING_FACTOR 2

template <typename T>
class ArrayList : public List<T>
{
public:
    ArrayList() : array{new T[INIT_SIZE]}, currentSize{INIT_SIZE}, head{-1}, tail{-1}, count{} {}

    ~ArrayList() { delete[] array; }

    void add(const T &item)
    {
        if (count >= currentSize)
            resize();

        array[++tail % currentSize] = item;

        if (head == -1)
            head = tail;

        ++count;
    }

    void insert(const T &item, size_t index)
    {
        if (index > currentSize)
            throw std::out_of_range("insert on out of range index");
        if (count >= currentSize)
            resize();

        for (int i = currentSize; i > index; --i)
            array[i] = array[i - 1];

        array[index] = item;
        ++count;
    }

    T remove(size_t index)
    {
        for (size_t i = index; i < currentSize - 1; ++i)
            array[i] = array[i + 1];

        --count;
    }

    T remove()
    {
        if (empty())
            throw std::out_of_range("remove on an empty array");

        T tmp = array[head];
        --count;

        head = ++head % currentSize;

        if (empty())
            head = tail = -1;

        return tmp;
    }

    void replace(const T &item, size_t index)
    {
        if (index > currentSize)
            throw std::out_of_range("replace on out of range index");
        array[index] = item;
    }

    T at(size_t index) const { return array[index]; }

    bool contains(const T &item) const { return find(item); }

    size_t size() const { return count; }

    bool empty() const { return count == 0; }

    void clear()
    {
        head = -1;
        tail = -1;
        count = 0;
    }

private:
    void resize()
    {
        T *tmp{new T[currentSize * SCALING_FACTOR]};

        for (size_t i = 0; i < count; ++i)
            tmp[i] = array[(head + i) % currentSize];

        currentSize *= SCALING_FACTOR;
        head = 0;
        tail = count - 1;

        delete[] array;
        array = tmp;
    }

    bool find(const T &item) const
    {
        for (size_t i = head; i < currentSize; ++i)
            if (array[i] == item)
                return true;

        return false;
    }

    T *array;
    size_t currentSize;
    size_t count;
    int head;
    int tail;
};

#endif /* LINKED_LIST */
