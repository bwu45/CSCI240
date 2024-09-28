#include <iostream>

#include "linked_stack.h"
#include "test.h"
#define TEST_VAL 25

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
    LinkedStack<int> s;
    testTrue(s.empty(), "testInitialStackEmpty: test that initial stack is empty");
}

void testStackNotEmptyAfterPush()
{
    LinkedStack<int> s;
    s.push(TEST_VAL);
    testFalse(s.empty(), "testStackNotEmptyAfterPush: stack is not empty after push");
}

void testPeekOnNonEmptyStack()
{
    LinkedStack<int> s;
    s.push(TEST_VAL);
    testTrue(s.peek() == TEST_VAL, "testPeekOnNonEmptyStack: after push peek returns test value");
}

void testPopOnNonEmptyStack()
{
    LinkedStack<int> s;
    s.push(TEST_VAL);
    s.pop();
    testTrue(s.empty(), "testPopOnNonEmptyStack: test that popped stack is empty");
}

void testLIFOBehavior()
{
    LinkedStack<int> s;
    int count{20};

    for (size_t i{1}; i <= count; ++i) // stack 1 -> 10
        s.push(i);

    while (!s.empty()) // pop 10 -> 1
    {
        if (s.peek() != count)
        {
            testFail("testLIFOBehavior: last in first out");
            return;
        }

        testTrue(s.peek() == count, "testLIFOBehavior: last in first out"); // peek first
        s.pop();
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
    LinkedStack<int> s;

    try
    {
        s.pop();
        testFail("testExceptionForPopOnEmptyStack: test empty stack throws exception on a pop");
    }
    catch (std::runtime_error)
    {
        testPass("testExceptionForPopOnEmptyStack: test empty stack throws exception on a pop");
    }
}

void testExceptionForPeekOnEmptyStack()
{
    LinkedStack<int> s;

    try
    {
        s.peek();
        testFail("testExceptionForPeekOnEmptyStack: test on empty stack throws exception on peek");
    }
    catch (std::runtime_error)
    {
        testPass("testExceptionForPeekOnEmptyStack: test on empty stack throws exception on peek");
    }
}