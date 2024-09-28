#include <cstddef>
#include <stdexcept>

#ifndef STACK_H
#define STACK_H

#define INIT_SIZE 20
#define SCALING_FACTOR 2
#define EMPTY 0

template <typename T>
class Stack
{
public:
    Stack() : top{}, currentSize{INIT_SIZE}, stack{new T[INIT_SIZE]} {}

    ~Stack() { delete[] stack; } // destructors must always be public

    void
    push(const T &item) // T is passed as reference
    {
        if (top == currentSize)
            resize();

        stack[top++] = item;
    }

    void pop()
    {
        if (empty())
            throw std::runtime_error("pop on an empty stack");

        --top;
    }

    T peek()
    {
        if (empty())
            throw std::runtime_error("peek on an empty stack");

        return stack[top - 1];
    }

    bool empty()
    {
        return top == EMPTY;
    }

private:
    int top;
    size_t currentSize;
    T *stack;

    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T *newStack{new T[currentSize]};

        for (size_t i = 0; i < top; ++i)
            newStack[i] = stack[i];

        delete[] stack;
        stack = newStack;
    }
};

#endif /* STACK_H */