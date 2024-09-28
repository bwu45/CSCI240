#include <stdexcept>

#include "queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define INIT_SIZE 4

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : first{}, last{}, currentSize{INIT_SIZE}, count{}, array{new T[INIT_SIZE]} {}

    ~ArrayQueue() { delete[] array; }

    void enqueue(const T &item)
    {
        if (count == currentSize)
            resize();

        array[last] = item; // set new item to the next available space
        last = (++last) % currentSize;
        count++;
    }

    void dequeue()
    {
        if (empty())
            throw std::runtime_error("nothing in the queue");

        first = (++first) % currentSize;
        count--;
    }

    T front() const
    {
        if (empty())
            throw std::runtime_error("nothing in the queue");

        return array[first];
    }

    bool empty() const
    {
        return count == 0;
    }

private:
    size_t first;
    size_t last;
    size_t currentSize;
    size_t count;
    T *array;

    void resize()
    {
        T *newArray;
        currentSize += INIT_SIZE;
        newArray = new T[currentSize];

        for (size_t i = 0; i < count; ++i)
            newArray[i] = array[(first + i) % currentSize];

        first = 0;
        last = count;
        delete[] array;
        array = newArray;
    }
};

#endif
