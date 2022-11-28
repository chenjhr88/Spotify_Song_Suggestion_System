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
    
    std::string label;
    Vertex dest;
    //common characteristic
};

class Graph {


    public:
        void insertVertices();

        //getting vertex, vertices, and the adjacent vertices of selected vertex
        Vertex getVertex(int i);
        std::vector<Vertex> getVertices();
        std::vector<Vertex> getAdjacents(Vertex v);

        std::string getLabel(Vertex v);
        void setLabel(Vertex& v, std::string label_str);
        std::string getLabel(Edge e);
        void setLabel(Edge& e, std::string label_str);

        std::string getLabel(Vertex v, Vertex w);
        std::string setLabel(Vertex& v, Vertex& w, std::string label_str);

    private:
        std::vector<Vertex> vertices;
        //index represents vertex number
        std::vector<Edge> edges;
        
};