#include <stdexcept>

#include "stack.h"

#define EMPTY 0

Stack::Stack()
{
    currentSize = INIT_SIZE;
    stack = new int[currentSize]; // created in heap
    top = 0;
}

void Stack::push(int value)
{
    // if (top >= MAX_STACK_SIZE)
    // throw std::runtime_error("stack is full");
    if (top == currentSize)
        resize();
    stack[top++] = value;
}

void Stack::pop()
{
    if (empty())
        throw std::runtime_error("pop on an empty stack");
    --top;
}

int Stack::peek()
{
    if (empty())
        throw std::runtime_error("peek on an empty stack");
    return stack[top - 1];
}

bool Stack::empty()
{
    return top == EMPTY;
}

void Stack::add(int value)
{
    push(value);
}

void Stack::remove()
{
    pop();
}

int Stack::get()
{
    return peek();
}

void Stack::resize()
{
    int *newStack{};

    currentSize *= SCALING_FACTOR;
    newStack = new int[currentSize];

    for (size_t i = 0; i < top; ++i) // copy
        newStack[i] = stack[i];

    delete[] stack; // delete old array

    stack = newStack;
}