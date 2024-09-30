#ifndef DEQUE_H
#define DEQUE_H

template <typename T>
struct Deque
{
    virtual ~Deque() {}
    virtual void addFront(const T &) = 0;
    virtual void addBack(const T &) = 0;
    virtual T removeFront() = 0;
    virtual T removeBack() = 0;
    virtual T peekFront() const = 0;
    virtual T peekBack() const = 0;
    virtual T contains(const T &) const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif // !DEQUE_H
