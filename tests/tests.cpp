#include <catch2/catch_test_macros.hpp>

//set compiler path to fix?
//lmao nevermind
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include "adjacencylist.cpp
#include "bfs_traversal.hpp"
#include <utility>
//working on - jason

TEST_CASE("insertVertecies", "[valgrind][weight=1]") {
    std::vector<std::vector<string>> test_read = insertVertices("test_data.csv");
    std::vector<std::vector<string>> expected = 
    {{ "cheese", "10"}, 
    { "dog", "20"}, 
    { "apple", "50"}, 
    { "horse", "99"}, 
    { "cat", "40"}, 
    { "weasel", "7"}, 
    { "brick", "34"},
    { "table", "20"}};
    REQUIRE(test_read == expected);
}

TEST_CASE("buildAdjMatrix_simple1", "[valgrind][weight=1]")
{

    std::vector<std::vector<string>> test_inputted_vector = 
    {{ "cheese", "10"}, 
    { "dog", "20"}, 
    { "apple", "50"}, 
    { "horse", "99"}, 
    { "cat", "40"}, 
    { "weasel", "7"}, 
    { "brick", "34"},
    { "table", "20"}};
    std::vector<std::vector<int>> test = buildAdjacencyMatrix(test_inputted_vector);
    std::vector<std::vector<int>> expectedAdjMatrix = 
    {{}};
    REQUIRE(test == expectedAdjMatrix);
    REQUIRE(test.size() == test_inputted_vector.size());
    
    //test adjacency matrix 1
}

TEST_CASE("buildAdjMatrix_simple2", "[valgrind][weight=1]")
{
    REQUIRE("HELLO" == "HELLO");
    //test adjacency matrix 2
}

TEST_CASE("buildAdjMatrix_complex1", "[valgrind][weight=1]")
{
    REQUIRE("HELLO" == "HELLO");
    //test adjacency 3
}

TEST_CASE("test1", "[valgrind][weight=1]")
{
    REQUIRE("HELLO" == "HELLO");
    //traversal
}

