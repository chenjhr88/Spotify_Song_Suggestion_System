#include <catch2/catch_test_macros.hpp>

//set compiler path to fix?
//lmao nevermind
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"
#include <utility>
//working on - jason

TEST_CASE("test1", "[valgrind][weight=1]")
{
    //std::vector<std::vector<string>> test_inputted_vector = 
    //buildAdjacencyMatrix = 
    REQUIRE(1 == 1);
    //test adjacency matrix 1
}

TEST_CASE("test2", "[valgrind][weight=2]")
{
    REQUIRE(2 == 2);
    //test adjacency matrix 2
}

TEST_CASE("test3", "[valgrind][weight=3]")
{
    REQUIRE(2 == 2);
    //test adjacency 3
}

TEST_CASE("test4", "[valgrind][weight=4]")
{
    REQUIRE(1 == 1);
    //traversal
}

