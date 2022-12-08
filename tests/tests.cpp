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

    REQUIRE(g.getVertices().size() == 5);
    REQUIRE(g.findVertex(0).song_name == expected.song_name);
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

// TEST_CASE("BFS Test 2", "[valgrind][weight=1]")
// {
//     Graph g;
//     for (int i = 0; i < 2; ++i) {
//         std::string song_name = "song_name";
//         std::vector<Edge> edges;
//         Vertex v = {i, 0.5, 0.2, 0.3, song_name, "", edges};
//         g.insertVertex(v);
//     }

//     g.insertEdge(0, 1);

//     int num_n = BFSTraversal(g);

//     REQUIRE(num_n == 2);
// }


TEST_CASE("Test Song Recommendation - song not found", "[recs]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");

    string test = getSongRecommendation(g, "song 5", "dancabililty");
    string expected = "song 5 was not found in the database. Please try another song title.";
    REQUIRE(test == expected);
}


