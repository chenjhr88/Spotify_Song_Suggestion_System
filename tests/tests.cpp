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

TEST_CASE("Read From CSV Test", "[valgrind][weight=2][csv]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
    vector<Edge> edge;
    Vertex expected = {1,0.8,0,0.8, "song 1" , "", edge};

    REQUIRE(g.getVertices().size() == 3);
    REQUIRE(g.getVertex(0).song_name == expected.song_name);
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

/*
TEST_CASE("insertVertices", "[valgrind][weight=1]") {
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
*/

TEST_CASE("buildAdjMatrix_simple1", "[valgrind][weight=1]")
{
    Graph g;
    std::vector<std::vector<string>> test_inputted_vector = 
    {{ "cheese", "10"}, 
    { "dog", "20"}, 
    { "apple", "50"}, 
    { "horse", "99"}, 
    { "cat", "40"}, 
    { "weasel", "7"}, 
    { "brick", "34"},
    { "table", "20"}};
    std::vector<std::vector<int>> test = g.buildAdjacencyMatrix(test_inputted_vector);
    std::vector<std::vector<int>> expectedAdjMatrix = 
  { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0,
  0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
  0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 0, 0, 0, 0, 0 } };
    REQUIRE(test == expectedAdjMatrix);
    REQUIRE(test.size() == test_inputted_vector.size());
    
    //test adjacency matrix 1
}

TEST_CASE("buildAdjMatrix_simple2", "[valgrind][weight=1]")
{
    Graph g;
    std::vector<std::vector<string>> test_inputted_vector = 
    {{ "a", "11"}, 
    { "b", "22"}, 
    { "c", "56"}, 
    { "d", "24"}, 
    { "e", "21"}, 
    { "f", "25"}, 
    { "g", "14"},
    { "h", "24"}};
    std::vector<std::vector<int>> test2 = g.buildAdjacencyMatrix(test_inputted_vector);
    std::vector<std::vector<int>> expectedAdjMatrix2 = 
 { { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0,
  0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0,
  0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 1, 0, 0, 0, 0 } };
    REQUIRE(test2 == expectedAdjMatrix2);
    REQUIRE(test2.size() == test_inputted_vector.size());
    //test adjacency matrix 2
}

TEST_CASE("buildAdjMatrix_complex1", "[valgrind][weight=1]")
{
    REQUIRE(1 == 1);
    //test adjacency 3
}

TEST_CASE("Test Song Recommendation - song not found", "[recs]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");

    string test = getSongRecommendation(g, "song 5");
    string expected = "song 5 was not found in the database. Please try another song title.";
    REQUIRE(test == expected);
}


