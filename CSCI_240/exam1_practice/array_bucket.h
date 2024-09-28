#include <stdexcept>

#include "bucket.h"

#ifndef ARRAY_BUCKET_H
#define ARRAY_BUCKET_H

#define INIT_SIZE 5
#define SCALING_FACTOR 2

template <typename T>
class ArrayBucket : public Bucket<T>
{
public:
    ArrayBucket() : array{new T[INIT_SIZE]}, currentSize{INIT_SIZE}, last{} {}

    ~ArrayBucket() { delete[] array; }

    void add(const T &item)
    {
        if (last == currentSize)
            resize();

        array[last++] = item;
    }

    T remove()
    {
        if (empty())
            throw std::runtime_error("remove on empty array bucket");

        return array[--last];
    }

    void remove(const T &item)
    {
        if (empty())
            throw std::runtime_error("remove on empty array bucket");

        for (size_t i = 0; i < last; ++i)
        {
            if (array[i] == item)
            {
                size_t tmp = array[last - 1];
                array[i] = array[last - 1];
                last--;
            }
        }
    }

    bool contains(const T &item) const
    {
        return find(item) != last;
    }

    bool empty() const
    {
        return last == 0;
    }

    void clear()
    {
        last = 0;
    }

private:
    void resize()
    {
        T *tmp{new T[currentSize * SCALING_FACTOR]};
        for (size_t i = 0; i < last; ++i)
            tmp[i] = array[i];

        currentSize *= SCALING_FACTOR;
        delete[] array;
        array = tmp;
    }

    size_t find(const T &item) const
    {
        for (size_t i = 0; i < last; ++i)
            if (array[i] == item)
                return i;

        return last;
    }

    T *array;
    size_t currentSize;
    size_t last;
};

#endif // !ARRAY_BUCKET_H
