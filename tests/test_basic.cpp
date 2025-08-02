#include "doctest/doctest.h"
#include "src/DoublyLinkedList.h"

TEST_SUITE("DoublyLinkedList Basic Operations")
{

    TEST_CASE("Insert at head and tail")
    {
        DoublyLinkedList<int> list;

        SUBCASE("Insert at head")
        {
            list.insertAtHead(2);
            list.insertAtHead(1);
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 2);
        }

        SUBCASE("Insert at tail")
        {
            list.insertAtTail(1);
            list.insertAtTail(2);
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 2);
        }
    }

    TEST_CASE("Delete and reverse")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3); // [1, 2, 3]

        SUBCASE("Delete middle element")
        {
            list.deleteAt(1); // remove 2
            CHECK(list.size() == 2);
            CHECK(list.get(0) == 1);
            CHECK(list.get(1) == 3);
        }

        SUBCASE("Reverse list")
        {
            list.reverse(); // should become [3, 2, 1]
            CHECK(list.get(0) == 3);
            CHECK(list.get(2) == 1);
        }
    }
}

TEST_SUITE("DoublyLinkedList<Point> Operations")
{
    std::string pointToString(Point & p)
    {
        return "(" + std::to_string(int(p.getX())) + "," + std::to_string(int(p.getY())) + ")";
    }

    TEST_CASE("Insert and get Point")
    {
        DoublyLinkedList<Point> list;

        SUBCASE("Insert at head")
        {
            list.insertAtHead(Point(1, 2));
            list.insertAtHead(Point(3, 4));
            CHECK(list.size() == 2);
            CHECK(list.get(0) == Point(3, 4));
            CHECK(list.get(1) == Point(1, 2));
        }
    }

    TEST_CASE("To string of list<Point>")
    {
        DoublyLinkedList<Point> list;
        list.insertAtTail(Point(9, 0));
        list.insertAtTail(Point(8, 1));
        std::string str = list.toString(pointToString);
        CHECK(str == "[(9,0), (8,1)]");
    }
}
TEST_SUITE("DoublyLinkedList Additional Test Cases")
{
    std::string pointToString(Point &p)
    {
        return "(" + std::to_string(int(p.getX())) + "," + std::to_string(int(p.getY())) + ")";
    }

    TEST_CASE("Basic Insertion and Access")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(5);
        CHECK(list.get(0) == 5);

        list.insertAtTail(10);
        CHECK(list.get(1) == 10);
    }

    TEST_CASE("Multiple Insertions at Head")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 5; i++)
            list.insertAtHead(i); // 4,3,2,1,0

        CHECK(list.get(0) == 4);
        CHECK(list.get(4) == 0);
        CHECK(list.size() == 5);
    }

    TEST_CASE("Multiple Insertions at Tail")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 5; i++)
            list.insertAtTail(i); // 0,1,2,3,4

        CHECK(list.get(0) == 0);
        CHECK(list.get(4) == 4);
        CHECK(list.size() == 5);
    }

    TEST_CASE("Delete First Element")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.deleteAt(0);
        CHECK(list.get(0) == 2);
        CHECK(list.size() == 2);
    }

    TEST_CASE("Delete Last Element")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.deleteAt(2);
        CHECK(list.get(1) == 2);
        CHECK(list.size() == 2);
    }

    TEST_CASE("Reverse Even List")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.insertAtTail(4);
        list.reverse();
        CHECK(list.get(0) == 4);
        CHECK(list.get(3) == 1);
    }

    TEST_CASE("Reverse Odd List")
    {
        DoublyLinkedList<int> list;
        for (int i = 1; i <= 5; ++i)
            list.insertAtTail(i); // [1,2,3,4,5]

        list.reverse();
        CHECK(list.get(0) == 5);
        CHECK(list.get(4) == 1);
    }

    TEST_CASE("Insert and Delete All")
    {
        DoublyLinkedList<int> list;
        for (int i = 0; i < 10; ++i)
            list.insertAtTail(i);

        for (int i = 0; i < 10; ++i)
            list.deleteAt(0);

        CHECK(list.size() == 0);
    }

    TEST_CASE("Check Size Consistency")
    {
        DoublyLinkedList<int> list;
        CHECK(list.size() == 0);
        list.insertAtHead(10);
        CHECK(list.size() == 1);
        list.insertAtTail(20);
        CHECK(list.size() == 2);
        list.deleteAt(1);
        CHECK(list.size() == 1);
    }

    TEST_CASE("ToString with Points")
    {
        DoublyLinkedList<Point> list;
        list.insertAtTail(Point(0, 0));
        list.insertAtTail(Point(1, 1));
        list.insertAtTail(Point(2, 2));

        std::string expected = "[(0,0), (1,1), (2,2)]";
        std::string actual = list.toString(pointToString);
        CHECK(actual == expected);
    }

    TEST_CASE("Insert Points at Head")
    {
        DoublyLinkedList<Point> list;
        list.insertAtHead(Point(1, 1));
        list.insertAtHead(Point(2, 2));
        list.insertAtHead(Point(3, 3));

        CHECK(list.get(0) == Point(3, 3));
        CHECK(list.get(2) == Point(1, 1));
    }

    TEST_CASE("Delete Middle Point")
    {
        DoublyLinkedList<Point> list;
        list.insertAtTail(Point(1, 1));
        list.insertAtTail(Point(2, 2));
        list.insertAtTail(Point(3, 3));
        list.deleteAt(1);

        CHECK(list.get(1) == Point(3, 3));
    }

    TEST_CASE("Reverse Single Element List")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(99);
        list.reverse();
        CHECK(list.get(0) == 99);
    
    }

    TEST_CASE("Access Out of Bounds (Expect crash or exception if implemented)")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        CHECK_THROWS(list.get(5));
    }

    TEST_CASE("Insert at head and immediately delete")
    {
        DoublyLinkedList<int> list;
        list.insertAtHead(1);
        list.deleteAt(0);
        CHECK(list.size() == 0);
    }

    TEST_CASE("Insert at tail and immediately delete")
    {
        DoublyLinkedList<int> list;
        list.insertAtTail(1);
        list.deleteAt(0);
        CHECK(list.size() == 0);
    }

    TEST_CASE("ToString with empty list")
    {
        DoublyLinkedList<Point> list;
        std::string result = list.toString(pointToString);
        CHECK(result == "[]");
    }
}

// TODO add test case