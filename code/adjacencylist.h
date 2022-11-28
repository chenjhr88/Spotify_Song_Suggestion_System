#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



class Graph {
    struct Edge {
        double threshold;
        
        //common characteristic
    };
    struct Vertex {
        int vert_num;
        std::string song_name;
        std::string label;

        std::vector<Edge> edges;
        //insert characteristics
        double dancabililty;
        double popularity;
        double energy;
    };



    public:
        std::vector<std::vector<int>> buildAdjacencyMatrix(std::vector<std::vector<std::string>> my_input);
        bool contains(std::vector<std::string> my_vec, std::string item_looking);
        void insertVertices();
        void translateData(const std::string& datainput, const std::string& dataoutput);

 
    private:
        std::vector<Vertex> vertices;
        //index represents vertex number
        std::vector<Edge> edges;
        
};