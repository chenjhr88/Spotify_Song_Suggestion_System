#include <catch2/catch_test_macros.hpp>

//set compiler path to fix?
//lmao nevermind
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <time.h>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"
#include "remove_vertex.h"
#include "remove_vertex.hpp"
#include <utility>
//working on - jason


bool removeVertHelperTest(Graph g, int vert_num) {
    std::vector<Vertex> vertices = g.getVertices();
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i].vert_num == vert_num) {
            std::cout << "this vertex wasn't even removed" << std::endl;
            return false;
        }   else {
            for (size_t j = 0; j < vertices[i].edges.size(); ++j) {
                if (vertices[i].edges[j].dest == vert_num) {
                    std::cout << "the vert_num specificed was spotted in this vertice's edge list!" << std::endl;
                    std::cout << vertices[i].edges[j].dest << " at vertex " << vertices[i].vert_num << std::endl;
                    return false;
                }
            }
        }
    }
    std::cout << "vert_num " << vert_num << " doesn't exist!" << std::endl;
    return true;
}

void removeVertHelperCharateristicTest(Graph g, std::string characteristic) {

    if (characteristic == "dance") {
        std::cout << "------For dance!------" << std::endl;
        for (auto const&[key, value]: g.getEdgesToHuesDance()) {
            std::cout << "key: (" << key.first << ", " << key.second << "), value: " << value << std::endl;
        }
    }   else if (characteristic == "acc") {
        std::cout << "------For Acousticness!------" << std::endl;
        for (auto const&[key, value]: g.getEdgesToHuesAcc()) {
            std::cout << "key: (" << key.first << ", " << key.second << "), value: " << value << std::endl;
        }
    }   else {
        std::cout << "------For Energy!------" << std::endl;
        for (auto const&[key, value]: g.getEdgesToHuesEnergy()) {
            std::cout << "key: (" << key.first << ", " << key.second << "), value: " << value << std::endl;
        }
    }

}

void printAdjMatrix(Graph g) {
    std::vector<std::vector<int>> adj_matrix = g.getAdjacencyMatrix();
    for (size_t i = 0; i < adj_matrix.size(); ++i) {
        std::cout << "row " << i << ": ";
        for (size_t j = 0; j < adj_matrix[i].size(); ++j) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

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
    int num_n = g.BFSTraversal();

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
    
    g.setAdjacencyMatrix(g.getVertices().size());

    /*for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            
        }
    }*/
    g.insertEdge(1, 0);
    g.insertEdge(0, 1);

    int num_n = g.BFSTraversal();

    REQUIRE(num_n == 2);
}

TEST_CASE("BFS Test 3", "[valgrind][weight=1]")
{
    Graph g;
    for (int i = 0; i < 3; ++i) {
        std::string song_name = "song_name";
        std::vector<Edge> edges;
        Vertex v = {i, 0.5, 0.2, 0.3, song_name, "", edges};
        g.insertVertex(v);
    }
    
    g.setAdjacencyMatrix(g.getVertices().size());

    /*for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            
        }
    }*/
    g.insertEdge(1, 0);
    g.insertEdge(0, 1);

    int num_n = g.BFSTraversal();

    REQUIRE(num_n == 3);
}


TEST_CASE("Test Song Recommendation - song not found", "[recs]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
    string song = "song 5";
    string test = getSongRecommendation(g, song, "dancabililty");
    string expected = "song 5 was not found in the database. Please try another song title.";
    REQUIRE(test == expected);
}

TEST_CASE("Test Song Recommendation 2- song not found", "[recs]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
    string song = "song_1";
    string test = getSongRecommendation(g, song, "dancabililty");
    string expected = "song_1 was not found in the database. Please try another song title.";
    REQUIRE(test == expected);
}

TEST_CASE("Test Song Recommendation 3- song is found", "[recs]")
{
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
    string song = "song 4";
    string test = getSongRecommendation(g, song, "dancabililty");
    string expected = "song 4 was not found in the database. Please try another song title";
    REQUIRE(test != expected);
}


TEST_CASE("Test removeVertex for graph with NO edges", "[reVe1]" ) {
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
    g.setAdjacencyMatrix(g.getVertices().size());

    
    g.makeEdgeHueMapDance(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapEnergy(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapAcc(g.getAdjacencyMatrix().size());

    
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    printAdjMatrix(g);

    int to_remove = 1;
    std::cout << "remove vert 1" << std::endl;
    g.removeVertex(to_remove);
    
    
    REQUIRE(removeVertHelperTest(g, to_remove) == true);
    printAdjMatrix(g);
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    /*std::cout << "go for next dance helper" << std::endl;
    removeVertHelperDanceTest(g, "dance");*/
}


TEST_CASE("Test removeVertex for graph with edges", "[reVe2]") {
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
   
    std::cout << "insert Edges" << std::endl;
    g.setAdjacencyMatrix(g.getVertices().size());

    //insert the edges on the song
    for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            g.insertEdge(i, j);
        }
    }
    
    g.makeEdgeHueMapDance(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapEnergy(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapAcc(g.getAdjacencyMatrix().size());

    
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    printAdjMatrix(g);

    int to_remove = 0;
    std::cout << "remove vert 0" << std::endl;
    g.removeVertex(to_remove);
    
    
    REQUIRE(removeVertHelperTest(g, to_remove) == true);
    printAdjMatrix(g);
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    /*std::cout << "go for next dance helper" << std::endl;
    removeVertHelperDanceTest(g, "dance");*/
}

//test case given faulty vertex to remove, shouldn't remove anything
TEST_CASE("Test removeVertex for graph with edges w/ nonexistent vertex", "[reVe2]") {
    Graph g;
    g.insertVertices("../tests/test_insertVerticies_data.csv", "../tests/test_insertVerticies_writedata.csv");
   
    std::cout << "insert Edges" << std::endl;
    g.setAdjacencyMatrix(g.getVertices().size());

    //insert the edges on the song
    for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            g.insertEdge(i, j);
        }
    }
    
    g.makeEdgeHueMapDance(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapEnergy(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapAcc(g.getAdjacencyMatrix().size());

    
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    printAdjMatrix(g);

    int to_remove = 107;
    std::cout << "remove vert 107" << std::endl;
    g.removeVertex(to_remove);
    
    
    REQUIRE(removeVertHelperTest(g, to_remove) == false);
    printAdjMatrix(g);
    //removeVertHelperCharateristicTest(g, "acc");
    //removeVertHelperCharateristicTest(g, "energy");
    /*std::cout << "go for next dance helper" << std::endl;
    removeVertHelperDanceTest(g, "dance");*/
}





