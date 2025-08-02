#include "doctest/doctest.h"
#include "src/DoublyLinkedList.h"

TEST_SUITE("DoublyLinkedList Iterator")
{
    TEST_CASE("Iteration over DoublyLinkedList")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(10);
        list.insertAtTail(20);
        list.insertAtTail(30);

        int expected[] = {10, 20, 30};

        SUBCASE("Forward iteration using Iterator")
        {
            int idx = 0;
            for (auto it = list.begin(); it != list.end(); ++it)
            {
                CHECK(*it == expected[idx++]);
            }
            CHECK(idx == 3);
        }

        SUBCASE("Range-based for iteration")
        {
            int idx = 0;
            for (int x : list)
            {
                CHECK(x == expected[idx++]);
            }
            CHECK(idx == 3);
        }
    }

    TEST_CASE("Iterator on empty list")
    {
        DoublyLinkedList<int> list;
        CHECK(list.begin() == list.end());
    }

    TEST_CASE("Iterator increment")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        auto it = list.begin();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(it == list.end());
    }

    TEST_CASE("Iterator with insertAtHead")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(1);
        list.insertAtHead(2);
        list.insertAtHead(3);

        int expected[] = {3, 2, 1};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
    }

    TEST_CASE("Iterator on reversed list")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.reverse();

        int expected[] = {3, 2, 1};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
    }

    TEST_CASE("Multiple iterators independent")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        auto it1 = list.begin();
        auto it2 = list.begin();
        ++it1;
        CHECK(*it1 == 2);
        CHECK(*it2 == 1);
    }

    TEST_CASE("Const iterator behavior")
    {
        const DoublyLinkedList<int> list = []{
            DoublyLinkedList<int> l;
            l.insertAtTail(5);
            l.insertAtTail(10);
            return l;
        }();

        int sum = 0;
        for (const auto& x : list)
        {
            sum += x;
        }
        CHECK(sum == 15);
    }

    TEST_CASE("Iterator dereferencing")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(100);
        auto it = list.begin();
        CHECK(*it == 100);
    }

    TEST_CASE("Modifying values through iterator")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);

        for (auto& x : list)
        {
            x *= 10;
        }

        int expected[] = {10, 20};
        int idx = 0;
        for (int x : list)
        {
            CHECK(x == expected[idx++]);
        }
    }

    TEST_CASE("Reverse then iterate")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 5; i++) list.insertAtTail(i);
        list.reverse();
        int expected[] = {4, 3, 2, 1, 0};
        int idx = 0;
        for (int x : list) CHECK(x == expected[idx++]);
    }

    TEST_CASE("Iterator on list with one item")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(999);
        auto it = list.begin();
        CHECK(*it == 999);
        ++it;
        CHECK(it == list.end());
    }

    TEST_CASE("Erase node through manual iteration")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.deleteAt(1);
        int expected[] = {1, 3};
        int idx = 0;
        for (int x : list) CHECK(x == expected[idx++]);
    }

    TEST_CASE("Iterator on long list")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 100; ++i)
            list.insertAtTail(i);
        int i = 0;
        for (int x : list)
            CHECK(x == i++);
    }

    TEST_CASE("Iterator stability after multiple inserts")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 10; i++)
            list.insertAtHead(i);
        int i = 9;
        for (int x : list)
            CHECK(x == i--);
    }

    TEST_CASE("Iterator on list with negative numbers")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(-1);
        list.insertAtTail(-2);
        list.insertAtTail(-3);
        int expected[] = {-1, -2, -3};
        int idx = 0;
        for (int x : list)
            CHECK(x == expected[idx++]);
    }

    TEST_CASE("Iterator on interleaved insert head/tail")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(1);
        list.insertAtTail(2);
        list.insertAtHead(3);
        list.insertAtTail(4);
        int expected[] = {3, 1, 2, 4};
        int idx = 0;
        for (int x : list)
            CHECK(x == expected[idx++]);
    }
}
