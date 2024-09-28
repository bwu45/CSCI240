// who:
// what: Test Linked List
// why:  List ADT
// when:

#include <iostream>

#include "test.h"
#include "list.h"
#include "array_list.h"
#include "linked_list.h"

#define SETUP List<int> *q = new LinkedList<int>
#define TEAR_DOWN delete q
#define TEST_VAL 12
#define TEST_COUNT 4

void testInitiallyEmpty();
void testNotEmptyAfterAdding();
void testContainsAfterAddAndRemove();
void testAddsCorrectValue();
void testRemoveFromFront();
void testEmptyAfterRemove();
void testRemoveOnSpecificIndex();
void testAtFunctionReturnsCorrectIndex();
void testSizeFunctionReturnsSizeOfArray();
void testClearFunction();
void testInsertOnEmptyListException();
void testReplaceOnEmptyListException();
void testReplaceOnEmptyListException();
void testAtOnEmptyListException();

int main(int argc, char const *argv[])
{
    testInitiallyEmpty();
    testNotEmptyAfterAdding();
    testContainsAfterAddAndRemove();
    testAddsCorrectValue();
    testRemoveFromFront();
    testEmptyAfterRemove();
    testRemoveOnSpecificIndex();
    testAtFunctionReturnsCorrectIndex();
    testSizeFunctionReturnsSizeOfArray();
    testClearFunction();
    testInsertOnEmptyListException();
    testReplaceOnEmptyListException();
    testAtOnEmptyListException();

    return 0;
}

void testInitiallyEmpty()
{
    SETUP;

    testTrue(q->empty(), "testInitiallyEmpty: test list empty at start");

    TEAR_DOWN;
}

void testNotEmptyAfterAdding()
{
    SETUP;

    q->add(TEST_VAL);
    testFalse(q->empty(), "testNotEmptyAfterAdding: test if array not empty after adding");

    TEAR_DOWN;
}

void testContainsAfterAddAndRemove()
{
    SETUP;

    q->add(TEST_VAL);
    testTrue(q->contains(TEST_VAL), "testContainsAfterAddAndRemove: test contains TEST_VAL after adding");
    q->remove(0);
    testFalse(q->contains(TEST_VAL), "testContainsAfterAddAndRemove: test does not contain TEST_VAL after remove");

    TEAR_DOWN;
}

void testAddsCorrectValue()
{
    SETUP;

    q->add(TEST_VAL);
    testTrue(q->contains(TEST_VAL), "testAddsCorrectValue: test adds correct value into array");

    TEAR_DOWN;
}

void testRemoveFromFront()
{
    SETUP;

    q->add(TEST_VAL);
    q->add(TEST_VAL + 10);
    q->add(TEST_VAL + 20);
    q->remove();
    testFalse(q->contains(TEST_VAL), "testRemoveFromFront: test if remove from the front");

    TEAR_DOWN;
}

void testEmptyAfterRemove()
{
    SETUP;

    q->add(TEST_VAL);
    q->remove();
    testTrue(q->empty(), "testEmptyAfterRemove: test array empty after removing");

    TEAR_DOWN;
}

void testRemoveOnSpecificIndex()
{
    SETUP;

    q->add(TEST_VAL);
    q->add(TEST_VAL + 1);
    q->add(TEST_VAL + 2);
    q->remove(1);
    testFalse(q->contains(TEST_VAL + 1), "testRemoveOnSpecificIndex: test remove on specific index");

    TEAR_DOWN;
}

void testAtFunctionReturnsCorrectIndex()
{
    SETUP;

    q->add(TEST_VAL);
    q->add(TEST_VAL + 10);
    q->add(TEST_VAL + 20);
    testTrue(q->at(1) == TEST_VAL + 10, "testAtFunctionReturnsCorrectIndex: test at function's return index");

    TEAR_DOWN;
}

void testSizeFunctionReturnsSizeOfArray()
{
    SETUP;

    q->add(TEST_VAL);
    q->add(TEST_VAL);
    q->add(TEST_VAL);
    testTrue(q->size() == 3, "testSizeFunctionReturnsSizeOfArray: test size returns correct size");
    TEAR_DOWN;
}

void testClearFunction()
{
    SETUP;

    q->add(TEST_VAL);
    q->add(TEST_VAL);
    q->add(TEST_VAL);
    testFalse(q->empty(), "testClearFunction: test if array is not empty first");
    q->clear();
    testTrue(q->empty(), "testClearFunction: test clear function on array");

    TEAR_DOWN;
}

void testInsertOnEmptyListException()
{
    SETUP;

    try
    {
        q->insert(TEST_VAL, 1);
        testFail("testInsertOnEmptyListException: test inserting into empty list throws exception");
    }
    catch (std::out_of_range &e)
    {
        testPass("testInsertOnEmptyListException: test inserting into empty list throws exception");
    }

    TEAR_DOWN;
}

void testReplaceOnEmptyListException()
{
    SETUP;

    try
    {
        q->replace(TEST_VAL, 1);
        testFail("testReplaceOnEmptyListException: test replace onto empty list throws exception");
    }
    catch (std::out_of_range &e)
    {
        testPass("testReplaceOnEmptyListException: test replace onto empty list throws exception");
    }

    TEAR_DOWN;
}

void testAtOnEmptyListException()
{
    SETUP;

    try
    {
        q->at(0);
        testFail("testAtOnEmptyListException: test at index on empty list throws exception");
    }
    catch (std::out_of_range &e)
    {
        testPass("testAtOnEmptyListException: test at index on empty list throws exception");
    }

    TEAR_DOWN;
}