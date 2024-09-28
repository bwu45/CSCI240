#include "queue.h"
#include "empty_queue_exception.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define INIT_SIZE 4
#define SCALING_FACTOR 2

template <typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue()
        : array{new T[INIT_SIZE]}, currentSize{INIT_SIZE}, head{-1}, tail{-1}, count{} {}

    ~ArrayQueue() { delete[] array; }

    void enqueue(const T &item)
    {
        if (count >= currentSize)
            resize();

        array[++tail % currentSize] = item;

        if (head == -1)
            head = tail;

        ++count;
    }

    void dequeue()
    {
        if (empty())
            EmptyQueueException("dequeue on an empty queue");

        --count;

        if (empty())
            head = tail = -1;
        else
            head = ++head % currentSize;
    }

    T front() const
    {
        if (empty())
            EmptyQueueException("front on an empty queue");

        return array[head];
    }

    bool empty() const { return count == 0; }

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

    T *array;
    size_t currentSize;
    int head; // front of the queue
    int tail; // back of the queue
    size_t count;
};

#endif