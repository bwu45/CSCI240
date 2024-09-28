#include <cstddef>

#include "container.h"
#ifndef STACK_H
#define STACK_H

#define INIT_SIZE 20
#define SCALING_FACTOR 2

class Stack : public Container
{
public:
    Stack();
    void push(int);
    void pop();
    int peek();

    void add(int);
    void remove();
    int get();
    bool empty();

private:
    int *stack;
    size_t currentSize;
    size_t top;

    void resize();
};

#endif /* STACK_H */