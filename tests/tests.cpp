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

TEST_CASE("BFS Test 1", "[valgrind][weight=1]")
{
    Graph g;
    for (int i = 0; i < 5; ++i) {
        std::string song_name = "song_name";
        std::vector<Edge> edges;
        Vertex v = {i, 0.5, 0.2, 0.3, song_name, "", edges};
        g.insertVertex(v);
    }
    int num_n = BFSTraversal(g);

    REQUIRE(num_n == 5);
}

TEST_CASE("BFS Test 2", "[valgrind][weight=1]")
{
    Graph g;
    for (int i = 0; i < 2; ++i) {
        std::string song_name = "song_name";
        std::vector<Edge> edges;
        Vertex v = {i, 0.5, 0.2, 0.3, song_name, "", edges};
        g.insertVertex(v);
    }

    g.insertEdge(0, 1);

    int num_n = BFSTraversal(g);

    REQUIRE(num_n == 2);
}

TEST_CASE("test4", "[valgrind][weight=4]")
{
    REQUIRE(1 == 1);
    //traversal
}

