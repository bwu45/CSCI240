#include <iostream>

#include "test.h"
#include "list.h"
#include "linked_list.h"

#define SETUP \
    List<int> *list { new LinkedList<int> }
#define TEARDOWN delete list

#define TEST_VAL 5

void testInitiallyEmpty();
void testNotEmptyAfterAdd();
void testRemoveEmptyList();
void testRemove();

int main(int argc, char const *argv[])
{
    testInitiallyEmpty();
    testNotEmptyAfterAdd();
    testRemoveEmptyList();
    testRemove();

    return 0;
}

void testInitiallyEmpty()
{
    SETUP;

    testTrue(list->empty(), "testInitiallyEmpty: test new list is empty");

    TEARDOWN;
}

void testNotEmptyAfterAdd()
{
    SETUP;

    list->add(TEST_VAL);
    testFalse(list->empty(), "testNotEmptyAfterAdd: test list is not empty after add");

    TEARDOWN;
}

void testRemoveEmptyList()
{
    SETUP;

    try
    {
        list->remove();
        testFail("testRemoveEmptyList: test remove on empty list throws exception");
    }
    catch (std::runtime_error)
    {
        testPass("testRemoveEmptyList: test remove on empty list throws exception");
    }

    TEARDOWN;
}

void testRemove()
{
    SETUP;

    list->add(TEST_VAL);
    testTrue(list->remove() == TEST_VAL, "testRemove: test remove returns correct value");

    TEARDOWN;
}