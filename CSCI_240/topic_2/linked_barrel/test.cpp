#include "test.h"
#include "linked_barrel.h"

#define SETUP Barrel<int> *b = new LinkedBarrel<int>
#define TEARDOWN delete b

#define TEST_VAL 42
#define TEST_VALS \
    int vals[] { 42, 35 }

void testInitiallyEmpty();
void testNotEmptyAfterAdd();
void testEmptyAfterAddAndClear();
void testDoesNotContainInitially();
void testContainsValueAfterAdd();
void testRemovesValue();
void testEmptyAfterRemovingValue();
void testRemovesSpecificValue();
void testEmptyAfterRemovingSpecificItem();

int main(int argc, char const *argv[])
{
    testInitiallyEmpty();
    testNotEmptyAfterAdd();
    testEmptyAfterAddAndClear();
    testDoesNotContainInitially();
    testContainsValueAfterAdd();
    testRemovesValue();
    testEmptyAfterRemovingValue();
    testRemovesSpecificValue();
    testEmptyAfterRemovingSpecificItem();
    return 0;
}

void testInitiallyEmpty()
{
    SETUP;

    testTrue(b->empty(), "testInitiallyEmpty: test initial barrel is empty");

    TEARDOWN;
}

void testNotEmptyAfterAdd()
{
    SETUP;

    b->add(TEST_VAL);
    testFalse(b->empty(), "testNotEmptyAfterAdd: test barrel is not empty after add");

    TEARDOWN;
}

void testEmptyAfterAddAndClear()
{
    SETUP;

    b->add(TEST_VAL);
    b->clear();
    testTrue(b->empty(), "testEmptyAfterAddAndClear: test barrel is empty after add then clear");

    TEARDOWN;
}

void testDoesNotContainInitially()
{
    SETUP;

    testFalse(b->contains(TEST_VAL), "testDoesNotContainInitially: test barrel does not initially contain a value");

    TEARDOWN;
}

void testContainsValueAfterAdd()
{
    SETUP;

    b->add(TEST_VAL);
    testTrue(b->contains(TEST_VAL), "testContainsValueAfterAdd: test barrel contains a value after add");

    TEARDOWN;
}

void testRemovesValue()
{
    SETUP;

    b->add(TEST_VAL);
    testTrue(b->remove() == TEST_VAL, "testRemovesValue: test removes single value");

    TEARDOWN;
}

void testEmptyAfterRemovingValue()
{
    SETUP;

    b->add(TEST_VAL);
    b->remove();
    testTrue(b->empty(), "testEmptyAfterRemovingValue: test empty after removing last value");

    TEARDOWN;
}

void testRemovesSpecificValue()
{
    SETUP;
    TEST_VALS;

    b->add(vals[0]);
    b->add(vals[1]);
    testTrue(b->contains(vals[1]), "testRemovesSpecificValue: test target value is contained");
    b->remove(vals[1]);
    testFalse(b->contains(vals[1]), "testRemovesSpecificValue: test target value is not contained after remove");

    TEARDOWN;
}

void testEmptyAfterRemovingSpecificItem()
{
    SETUP;

    b->add(TEST_VAL);
    b->remove(TEST_VAL);
    testTrue(b->empty(), "testEmptyAfterRemovingSpecificItem: test empty after add then remove specific item");

    TEARDOWN;
}
