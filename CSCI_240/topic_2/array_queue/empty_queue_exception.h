#include <stdexcept>

#ifndef EMPTY_QUEUE_EXCEPTION_H
#define EMPTY_QUEUE_EXCEPTION_H

struct EmptyQueueException : public std::runtime_error
{
    EmptyQueueException(const std::string &msg) : std::runtime_error(msg) {}
    EmptyQueueException() : EmptyQueueException("operation on empty queue") {}
};

#endif