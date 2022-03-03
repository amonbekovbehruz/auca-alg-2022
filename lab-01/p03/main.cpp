#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "List.hpp"
TEST_CASE("List: default constructor")
{
    List<int> lst;

    REQUIRE(lst.size() == 0);
}

TEST_CASE("List: pushBack")
{
    List<int> lst;

    lst.pushBack(1);
    lst.pushBack(2);
    lst.pushBack(3);
    lst.pushBack(4);
    lst.pushBack(5);
    lst.pushBack(6);
    lst.pushBack(7);

    REQUIRE(lst.size() == 7);
    REQUIRE(lst.toStr() == "{1, 2, 3, 4, 5, 6, 7}");
    //REQUIRE(lst.toReverseStr() == "{1, 2, 3, 4, 5, 6, 7}");
}