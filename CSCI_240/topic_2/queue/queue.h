// queue interface

#ifndef QUEUE_H
#define QUEUE_H

// struct = public, class = private
template <typename T>
struct Queue
{
    // virtual ~Queue = default;         // alternative way to make a constructor 
    virtual ~Queue() {};                 // destructor never takes arguments, never a pure virtual
    virtual void enqueue(const T &) = 0; // adds to the back of the queue
    virtual void dequeue() = 0;          // removes the front of the queue
    virtual T front() const = 0;         // returns but does not remove front of queue
    virtual bool empty() const = 0;      // returns true if queue is empty but does not remove
};

#endif