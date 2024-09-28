#include <stdexcept>

#include "barrel.h"

#ifndef ARRAY_BARREL_H
#define ARRAY_BARREL_H

#define INIT_SIZE 10
#define SCALING_FACTOR 2

template <typename T>
class ArrayBarrel : public Barrel<T>
{
public:
    ArrayBarrel() : last{}, currentSize{INIT_SIZE}, array{new T[INIT_SIZE]} {};

    ~ArrayBarrel()
    {
        delete[] array;
    }

    void add(const T &item)
    {
        if (last >= currentSize)
        {
            resize();
        }
        array[last++] = item;
    };

    T remove()
    {
        if (empty())
            throw std::runtime_error("remove: nothing in the barrel to remove");

        return array[--last];
    };

    void remove(const T &item)
    {
        if (empty())
            throw std::runtime_error("remove item on an empty barrel");

        for (int i = 0; i < last; ++i)
        {
            if (array[i] == item)
            {
                array[i] = array[last - 1]; //last is not actually the last index, but the one after
                --last;                     //should be [last - 1] to get the actual last index/value
            }
        }
    };

    bool contains(const T &item) const
    {
        for (int i = 0; i < last; ++i)
        {
            if (array[i] == item)
            {
                return true;
            }
        }
        return false;
    };

    bool empty() const
    {
        return last == 0; // null and 0 are the same, but last is an int so 0
    };

    void clear()
    {
        last = 0; /* no need to loop through the entire array, just set last = 0
                    and the rest goes away */
    };

private:
    size_t last;
    size_t currentSize;
    T *array;

    void resize()
    {
        currentSize += SCALING_FACTOR;
        T *newArray{new T[currentSize]};

        for (size_t i = 0; i < last; ++i)
            newArray[i] = array[i];

        delete[] array;
        array = newArray;
    }
};

#endif /* ARRAY_BARREL_H */