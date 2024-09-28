#include "test.h"
#include "linked_queue.h"
#include "array_queue2.h"

#define SETUP Queue<int> *q = new LinkedQueue<int>
#define TEAR_DOWN delete q
#define TEST_VAL 12
#define TEST_COUNT 5

void testInitiallyEmpty();
void testNotEmptyAfterAdd();
void testFrontReturnsValue();
void testFrontOnEmptyQueueThrowsException();
void testEmptyAfterRemove();
void testRemoveOnEmptyQueueThrowsException();
void testFIFOBehavior();

int main(int argc, char const *argv[])
{
    testInitiallyEmpty();
    testNotEmptyAfterAdd();
    testFrontReturnsValue();
    testFrontOnEmptyQueueThrowsException();
    testEmptyAfterRemove();
    testRemoveOnEmptyQueueThrowsException();
    testFIFOBehavior();
    return 0;
}

void testInitiallyEmpty()
{
    SETUP;

    testTrue(q->empty(), "testInitiallyEmpty: test queue initially empty");

    TEAR_DOWN;
}

void testNotEmptyAfterAdd()
{
    SETUP;

    q->enqueue(TEST_VAL);
    testFalse(q->empty(), "testNotEmptyAfterAdd: test not empty after enqueue");

    TEAR_DOWN;
}

void testFrontReturnsValue()
{
    SETUP;

    q->enqueue(TEST_VAL);
    testTrue(q->front() == TEST_VAL, "testFrontReturnsValue: test front returns test value");

    TEAR_DOWN;
}

void testFrontOnEmptyQueueThrowsException()
{
    SETUP;

    try
    {
        q->front();
        testFail("testFrontOnEmptyQueueThrowsException: test empty queue throws exception on front operation");
    }
    catch (const EmptyQueueException &e)
    {
        testPass("testFrontOnEmptyQueueThrowsException: test empty queue throws exception on front operation");
    };

    TEAR_DOWN;
}

void testEmptyAfterRemove()
{
    SETUP;

    q->enqueue(TEST_VAL);
    q->dequeue();
    testTrue(q->empty(), "testEmptyAfterRemove: test dequeue on queue with 1 value is empty");

    TEAR_DOWN;
}

void testRemoveOnEmptyQueueThrowsException()
{
    SETUP;

    try
    {
        q->dequeue();
        testFail("testRemoveOnEmptyQueueThrowsException: test empty queue throws exception on dequeue");
    }
    catch (const EmptyQueueException &e)
    {
        testPass("testRemoveOnEmptyQueueThorwsException: test empty queue throws exception on dequeue");
    }

    TEAR_DOWN;
}

void testFIFOBehavior()
{
    SETUP;

    size_t i{};

    for (; i < TEST_COUNT; ++i)
    {
        q->enqueue(i);
    }

    i = 0;

    while (!q->empty())
    {
        if (q->front() != i++)
        {
            testFail("testFIFOBehavior: test first in first out");
            break;
        }
        else
        {
            q->dequeue();
        }
    }

    if (i == TEST_COUNT) testPass("testFIFOBehavior: test first in first out");
    TEAR_DOWN;
}
