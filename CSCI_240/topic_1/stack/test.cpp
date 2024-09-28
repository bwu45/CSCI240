#include <iostream>

#include "stack.h"
#include "test.h"
#define TEST_VALUE 25

void testInitialStackEmpty();
void testStackNotEmptyAfterPush();
void testPeekOnNonEmptyStack();
void testPopOnNonEmptyStack();
void testLIFOBehavior();
// void testExceptionForPushOnFullStack();
void testExceptionForPopOnEmptyStack();
void testExceptionForPeekOnEmptyStack();

int main(int argc, char const *argv[])
{
    testInitialStackEmpty();
    testStackNotEmptyAfterPush();
    testPeekOnNonEmptyStack();
    testPopOnNonEmptyStack();
    testLIFOBehavior();
    // testExceptionForPushOnFullStack();
    testExceptionForPopOnEmptyStack();
    testExceptionForPeekOnEmptyStack();
    return 0;
}

void testInitialStackEmpty()
{
    Container *c{new Stack};
    testTrue(c->empty(), "testInitialStackEmpty: test that initial stack is empty");
}

void testStackNotEmptyAfterPush()
{
    Container *c{new Stack};
    c->add(TEST_VAL);
    testFalse(c->empty(), "testStackNotEmptyAfterPush: stack is not empty after push");
}

void testPeekOnNonEmptyStack()
{
    Container *c{new Stack};
    c->add(TEST_VAL);
    testTrue(c->get() == TEST_VAL, "testPeekOnNonEmptyStack: after push peek returns test value");
}

void testPopOnNonEmptyStack()
{
    Container *c{new Stack};
    c->add(TEST_VAL);
    c->remove();
    testTrue(c->empty(), "testPopOnNonEmptyStack: test that popped stack is empty");
}

void testLIFOBehavior()
{
    Container *c{new Stack};
    int count{INIT_SIZE};

    for (size_t i{1}; i <= count; ++i) // stack 1 -> 10
        c->add(i);

    while (!c->empty()) // pop 10 -> 1
    {
        if (c->get() != count)
        {
            testFail("testLIFOBehavior: last in first out");
            return;
        }

        testTrue(c->get() == count, "testLIFOBehavior: last in first out"); // peek first
        c->remove();
        --count;
    }

    testPass("testLIFOBehavior: last in first out");
}

// void testExceptionForPushOnFullStack()
// {
//     Stack stack;

//     for (int i{0}; i < MAX_STACK_SIZE; ++i)
//         stack.push(i);

//     try
//     {
//         stack.push(TEST_VAL);
//         testFail("testExceptionForPushOnFullStack: test full stack throws exception on a push");
//     }
//     catch (std::runtime_error)
//     {
//         testPass("testExceptionForPushOnFullStack: test full stack throws exception on a push");
//     }
// }

void testExceptionForPopOnEmptyStack()
{
    Container *c{new Stack};

    try
    {
        c->remove();
        testFail("testExceptionForPopOnEmptyStack: test empty stack throws exception on a pop");
    }
    catch (std::runtime_error)
    {
        testPass("testExceptionForPopOnEmptyStack: test empty stack throws exception on a pop");
    }
}

void testExceptionForPeekOnEmptyStack()
{
    Container *c{new Stack};

    try
    {
        c->get();
        testFail("testExceptionForPeekOnEmptyStack: test on empty stack throws exception on peek");
    }
    catch (std::runtime_error)
    {
        testPass("testExceptionForPeekOnEmptyStack: test on empty stack throws exception on peek");
    }
}