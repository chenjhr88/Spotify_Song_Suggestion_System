#pragma once
#include <iostream>
#include <string>
#include <vector>

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

struct Edge {
    double threshold;
    
    //common characteristic
};

class Graph {


    public:
        void insertVertices();

        
    private:
        std::vector<Vertex> vertices;
        //index represents vertex number
        std::vector<Edge> edges;
        
};