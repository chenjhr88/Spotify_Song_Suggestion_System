#include "adjacencylist.h"

using namespace std;

//inputted_vector should be formatted as
//{{ "SongName A", "Danceability 90", "Danceability 20"}, \
// { "SongName B", "Danceability 20"}, \
// { "SongName C", "Danceability 50"}, \
// { "SongName D", "Danceability 99", "Danceability 1"}, \
// { "SongName E", "Danceability 40", "Danceability 50"}, \
// { "SongName F", "Danceability 7"}, \
// { "SongName G", "Danceability 34"}, \
// { "SongName H", "Danceability 20"}};

std::vector<std::vector<int>> Graph::buildAdjacencyMatrix(std::vector<std::vector<string>> inputted_vector) {
    vector<vector<int>> adjacency_matrix;

    //initialize a 2d adjacency matrix of all 0s
    for(unsigned i=0; i<inputted_vector.size(); i++){
        std::vector <int> temp;
        for (unsigned j=0; j<inputted_vector.size(); j++){
            temp.push_back(0);
        }
        adjacency_matrix.push_back(temp);
    }

    //fill adjacency matrix based on overlapping factor values
    for (unsigned row = 0; row < inputted_vector.size(); row++) {
        for (unsigned col = 0; col < inputted_vector[row].size(); col++) {
            std::string curr_song = inputted_vector[row][col];
            for (unsigned factor = 0; factor < inputted_vector.size(); factor++) {
                if (contains(inputted_vector.at(factor), curr_song) == true && factor != row) {
                    adjacency_matrix[row][factor] = 1;
                }
            }
        }
    }
}


bool Graph::contains(std::vector<std::string> my_vec, std::string item_looking) {
    for (unsigned i = 0; i < my_vec.size(); i++) {
        if (my_vec.at(i) == item_looking) {
            return true;
        }
    }
    return false;
}

void Graph::insertVertices() {
    //read csv file
    //  ifstream to read file
    //  split string by ',' or ' '
    //  string to int (stoi)
    translateData("genres_v2.csv", "data.csv");
    std::ifstream ifs{"data.csv"};

    while (ifs >> to_input) {
        std::vector<std::string> parse_line = to_input.split(",");
        struct Vertex insert = {parse_line.at(0), parse_line.at(1), stod(parse_line.at(2)), stod(parse_line.at(3)), stod(parse_line.at(4))};

        vertices.push_back(insert);
    }
    //read each line, each line represnts a vertex
    //get the song name + characteristics (dancability, popularity, energy)
    //create the vertex struct
    //add the vertex to the vertices vector
    std::cout << "finish insertion" << std::endl;

}

void Graph::translateData(const std::string& datainput, const std::string& dataoutput) {
    std::ifstream ifs{datainput};
    std::ofstream ofs{dataoutput};
    int num = 0;
    bool skip = true;
    while (ifs >> to_input) {
        if (!skip) {
            std::vector<std::string> parse_line = to_input.split(",");
            ofs << num << "," << parse_line.at(parse_line.size() - 1) << "," << parse_line.at(0) << "," << 12 << "," << parse_line.at(1) << std::endl;
            num++;
        } else {
            skip = false;
        }
    }
}


//
//FUNCTIONS FOR ACCESSING GRAPH VERTICES AND EDGES
//

//Get the vertex
Vertex Graph::getVertex(int i) {
    if (i >= 0 && i < vertices.size()) {
        return vertices.at(i);
    }
    std::cout << "i is too low or high!" << std::endl;
}

std::vector<Vertex> Graph::getVertices() {
    return vertices;
}

Vertex Graph::findVertex(int vert_num) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i).vert_num == vert_num) {
            return vertices.at(i);
        }
    }

    return vertices.at(0);
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
        Vertex dest_vert = g.findVertex(v.edges.at(i).dest);
        if (dest_vert.vert_num == w.vert_num) {
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
        Vertex dest_vert = g.findVertex(w.edges.at(i).dest);
        if (dest_vert.vert_num == v.vert_num) {
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
        Vertex dest_vert = g.findVertex(v.edges.at(i).dest);
        if (dest_vert.vert_num == w.vert_num) {
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
        Vertex dest_vert = g.findVertex(w.edges.at(i).dest);
        if (dest_vert.vert_num == v.vert_num) {
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