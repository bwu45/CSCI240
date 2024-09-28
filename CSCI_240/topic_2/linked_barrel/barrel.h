#ifndef BARREL_H
#define BARREL_H

/* !!! DO NOT ALTER THIS FILE !!! */

template <typename T>
struct Barrel
{
    /*
        This is a virtual Destructor. It is not pure virtual.
        You do not have to implement this in your derived class
    */
    virtual ~Barrel() {}

    virtual void add(const T &) = 0;
    virtual T remove() = 0;
    virtual void remove(const T &) = 0;
    virtual bool contains(const T &) const = 0; // the parameter is the item to be searched for
    virtual bool empty() const = 0;
    virtual void clear() = 0;
};

#endif /* BARREL_H */
