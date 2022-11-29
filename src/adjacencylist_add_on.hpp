#include "adjacencylist.h"

//add to adjacencylist.hpp

/*Vertex Graph::getVertex(int i) {
    if (i >= 0 && i < vertices.size()) {
        return vertices.at(i);
    }
    std::cout << "i is too low or high!" << std::endl;
}

std::vector<Vertex> Graph::getVertices() {
    return vertices;
}

std::vector<Vertex> Graph::getAdjacents(Vertex v) {
    std::vector<Vertex> adjacents;
    for (size_t i = 0; i < v.edges.size(); ++i) {
        adjacents.push_back(v.edges.at(i).dest);
    }

    return adjacents;
}


//For Vertex
std::string Graph::getLabel(Vertex v) {
    return v.label;
}

void Graph::setLabel(Vertex& v, std::string label_str) {
    int curr_vertex_idx = v.vert_num;
    vertices.at(curr_vertex_idx).label = label_str;
}


//For Edges
std::string getLabel(Edge e) {
    return e.label;
}

void Graph::setLabel(Edge& e, std::string label_str) {
    e.label = label_str;
}

//for edges that are between two selected vertices
std::string Graph::getLabel(Vertex v, Vertex w) {
    bool w_in_v = false;

    std::string v_edge_label = "";
    for (size_t i = 0; i < v.edges.size(); ++i) {
        if (v.edges.at(i).dest.vert_num == w.vert_num) {
            w_in_v = true;
            v_edge_label = v.edges.at(i).label;
        }
    }
    if (!w_in_v) {
        std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
        return "ERROR0";
    }

    bool v_in_w = false;
    std::string w_edge_label = "";
    for (size_t i = 0; i < w.edges.size(); ++i) {
        if (w.edges.at(i).dest.vert_num == v.vert_num) {
            v_in_w = true;
            w_edge_label = w.edges.at(i).label;
        }
    }
    
    if (!v_in_w) {
        std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
        return "ERROR1";
    }

    if (v_edge_label == w_edge_label) {
        return v_edge_label;
    }   else {
        std::cout << "EDGE LABELS DON'T MATCH!" << std::endl;
        return "ERROR3";
    }

}
std::string Graph::setLabel(Vertex& v, Vertex& w, std::string label_str) {
    bool w_in_v = false;
    int v_edge_idx = -1;
    for (size_t i = 0; i < v.edges.size(); ++i) {
        if (v.edges.at(i).dest.vert_num == w.vert_num) {
            w_in_v = true;
            v_edge_idx = (int) i;
        }
    }
    if (!w_in_v) {
        std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
        return "ERROR0";
    }

    bool v_in_w = false;
    int w_edge_idx = -1;
    std::string w_edge_label = "";
    for (size_t i = 0; i < w.edges.size(); ++i) {
        if (w.edges.at(i).dest.vert_num == v.vert_num) {
            v_in_w = true;
            w_edge_idx = (int) i;
        }
    }

    if (!v_in_w) {
        std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
        return "ERROR1";
    }
    
    v.edges.at(v_edge_idx).label = label_str;
    w.edges.at(w_edge_idx).label = label_str;
}
*/