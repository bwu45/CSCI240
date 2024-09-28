#ifndef BUCKET_H
#define BUCKET_H

template <typename T>
struct Bucket
{
    virtual ~Bucket() {}
    virtual void add(const T &) = 0;            // add anywhere you like
    virtual T remove() = 0;                             // remove from anywhere you like
    virtual void remove(const T &) = 0;         // remove specific item
    virtual bool contains(const T &) const = 0; // true or false if it contains the item
    virtual bool empty() const = 0;             // check if bucket is empty
    virtual void clear() = 0;                   // clear bucket of all data
};

#endif