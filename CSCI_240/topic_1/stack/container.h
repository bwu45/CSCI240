#ifndef CONTAINER_H
#define CONTAINER_H

// all functions will be pure virtual
struct Container
{
public:
    virtual void add(int) = 0;
    virtual void remove() = 0;
    virtual int get() = 0;
    virtual bool empty() = 0;

private:
};

#endif /* CONTAINER_H */