#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "HashSetStr.hpp"

TEST_CASE("default const")
{
    HashSetStr set;
    REQUIRE(set.size() == 0);
}

TEST_CASE("insert")
{
    HashSetStr set;
    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("Java"));
    REQUIRE_FALSE(set.insert("C++"));
}

TEST_CASE("find")
{
    HashSetStr set;
    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("Java"));
    REQUIRE(set.insert("JavaScript"));

    REQUIRE(set.find("C++"));
    REQUIRE_FALSE(set.find("Kotlin"));
}

TEST_CASE("erase")
{
    HashSetStr set;

    REQUIRE(set.insert("C++"));
    REQUIRE(set.insert("Java"));
    REQUIRE(set.insert("JavaScript"));

    REQUIRE(set.erase("Java"));
    REQUIRE(set.size() == 2);
    REQUIRE_FALSE(set.erase("Kotlin"));
}