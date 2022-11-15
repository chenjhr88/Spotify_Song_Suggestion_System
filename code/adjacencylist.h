#pragma once
#include <string>
#include <vector>

class Graph {
    struct Vertex {
        int vert_num;
        std::string song_name;

        //insert characteristics
        double dancabililty;
        double popularity;
        double energy;
    };

    struct Edge {
        double threshold;
        
        //common characteristic
    };

    public:
        void insertVertices();
        
    private:
        std::vector<Vertex> vertices;
        //index represents vertex number
        std::vector<Edge> edges;
        
};