#include <stdexcept>

#include "queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define INIT_SIZE 2
#define SCALING_FACTOR 2

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : array{new T[INIT_SIZE]}, head{-1}, tail{-1}, currentSize{INIT_SIZE}, count{} {}

    ~ArrayQueue() { delete[] array; };

    void add(const T &item) override
    {
        if (count >= currentSize)
            resize();

        array[(++tail) % currentSize] = item;

        if (head == -1)
            head = tail;

        ++count;
    }

    T remove() override
    {
        if (empty())
        {
            head = tail = -1;
            throw std::runtime_error("remove on empty array queue");
        }

        T tmp = array[head];
        head = ++head % currentSize;

        --count;
        return tmp;
    }

    T peek() const override
    {
        if (empty())
            throw std::runtime_error("peek on an empty array queue");
        return array[head];
    }

    bool contains(const T &item) const override
    {
        for (size_t i = 0; i < count; ++i)
        {
            size_t j = (head + i) % currentSize;
            if (array[j] == item)
                return true;
        }
        return false;
    }

    bool empty() const override
    {
        return count == 0;
    }

    void clear() override
    {
        head = tail = -1;
        count = 0;
    }

private:
    void resize()
    {
        T *tmp = new T[currentSize * SCALING_FACTOR];

        for (size_t i = 0; i < count; ++i)
            tmp[i] = array[(head + i) % currentSize];

        head = 0;
        tail = count - 1;
        currentSize *= SCALING_FACTOR;
        delete[] array;
        array = tmp;
    }

    T *array;
    int head;
    int tail;
    size_t currentSize;
    size_t count;
};

#endif // !ARRAY_QUEUE_H