// prof
#include <stdexcept>

#include "barrel.h"

#ifndef ARRAY_BARREL2
#define ARRAY_BARREL2

#define INITIAL_SIZE 32
#define SCALING_FACTOR 2

template <typename T>
class ArrayBarrel : public Barrel<T>
{
public:
    ArrayBarrel()
        : next{}, currentSize{INITIAL_SIZE}, array{new T[INITIAL_SIZE]} {}

    ~ArrayBarrel() { delete[] array; }

    void add(const T &item)
    {
        if (next == currentSize)
            resize();

        array[next++] = item;
    }

    T remove()
    {
        if (empty())
            throw std::runtime_error("remove on empty barrel");

        return array[--next];
    }

    void remove(const T &item)
    {
        size_t pos{find(item)};

        if (pos == next)
            return;

        array[pos] = array[--next];
    }

    bool contains(const T &item) const
    {
        return find(item) != next;
    }

    bool empty() const { return next == 0; }

    void clear() { next = 0; }

private:
    void resize()
    {
        T *newArray;

        currentSize *= SCALING_FACTOR;
        newArray = new T[currentSize];

        for (size_t i = 0; i < next; ++i)
            newArray[i] = array[i];

        delete[] array;

        array = newArray;
    }

    size_t find(const T &item) const
    {
        for (size_t i = 0; i < next; ++i)
            if (array[i] == item)
                return i;

        return next;
    }

    size_t currentSize;
    size_t next;
    T *array;
};

#endif