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
Graph::Graph() {}

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
    return adjacency_matrix;
}


bool Graph::contains(std::vector<std::string> my_vec, std::string item_looking) {
    for (unsigned i = 0; i < my_vec.size(); i++) {
        if (my_vec.at(i) == item_looking) {
            return true;
        }
    }
    return false;
}

/**
 * This function will insert vertices from the given file and input them into the graph's vector of vertices
 * @param string filename name of the file to be read and parsed for data
 */
void Graph::insertVertices(string filename, string filewrite) {
    // read csv file
    // ifstream to read file
    // split string by ',' or ' '
    // string to int (stoi)
    // read each line, each line represnts a vertex
    // get the song name + characteristics (dancability, popularity, energy)
    // create the vertex struct
    // add the vertex to the vertices vector
    translateData(filename, filewrite);
    ifstream ifs(filewrite);
    if (ifs.good()) {
        for (string line ; getline(ifs, line); ) {
            vector<string> insert;
            for(int i = 0; i < (int) insert.size(); i++) {
                cout << insert.at(i) << endl;
            }
            SplitString(line, ',', insert);
            std::vector<Edge> edges;
            Vertex to_insert = {std::stoi(insert.at(0)), (double) std::stoi(insert.at(1)), 0, (double) std::stoi(insert.at(2)), insert.at(3), "", edges};
            if (to_insert.song_name != "") {
                vertices.push_back(to_insert);    
            }
        }
    }
    

}

/** 
 * Splits a string by a character and places into a std::vector<std::string> passed in by reference
 * @param std::string str1 string to be split
 * @param char sep char to define where string will be split
 * @param std::vector<std::string> fields vector of where split strings will be placed
 */ 
void Graph::SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
}

/** 
 * Given a data input file and data output file, this function will read and parse needed data from the input file into the data output file
 * @param dataintput name of file to be read
 * @param dataoutput name of file to be written
 */
void Graph::translateData(const std::string& datainput, const std::string& dataoutput) {
    std::ifstream ifs{datainput};
    std::ofstream ofs{dataoutput};
    int num = 0;
    bool skip = true;
    for (string line ; getline(ifs, line);) {
        if (!skip) {
            std::vector<std::string> parse_line;
            SplitString(line, ',', parse_line);
            if (parse_line.at(parse_line.size() - 3) != "") {
                ofs << num << "," << parse_line.at(0) << "," << 0 << "," << parse_line.at(parse_line.size() - 3) << "," << parse_line.at(1)  <<  std::endl;
                num++;
            }
        } else {
            skip = false;
        }
    }
}

/**
 * inserts a vertex into the graph
 * @param v vertex to be inserted
 */
void Graph::insertVertex(Vertex v) {
    vertices.push_back(v);
}

void Graph::insertEdge(int v1, int v2) {
    Edge e1 = {0, v2, ""};
    Edge e2 = {0, v1, ""};

    vertices.at(v1).edges.push_back(e1);
    vertices.at(v2).edges.push_back(e2);

    std::cout << vertices.at(v1).edges.at(0).dest << std::endl;
}

//
//FUNCTIONS FOR ACCESSING GRAPH VERTICES AND EDGES
//

//Get the vertex
Vertex Graph::getVertex(int i) {
    if (i >= 0 && i < (int) vertices.size()) {
        return vertices.at(i);
    }
    std::cout << "i is too low or high!" << std::endl;
    return Vertex();
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
    std::cout << "at " << v.vert_num << "There are " << v.edges.size() << " edges" << std::endl;
    for (size_t i = 0; i < v.edges.size(); ++i) {
        Vertex v1 = findVertex(v.edges.at(i).dest);
        adjacents.push_back(v1);
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
    std::cout << "get the Label between " << v.vert_num << " and " << w.vert_num << std::endl;
    bool w_in_v = false;

    std::string v_edge_label = "";
    for (size_t i = 0; i < v.edges.size(); ++i) {
        Vertex dest_vert = findVertex(v.edges.at(i).dest);
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
        Vertex dest_vert = findVertex(w.edges.at(i).dest);
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

void Graph::setLabel(Vertex& v, Vertex& w, std::string label_str) {
    bool w_in_v = false;
    int v_edge_idx = -1;
    for (size_t i = 0; i < v.edges.size(); ++i) {
        Vertex dest_vert = findVertex(v.edges.at(i).dest);
        if (dest_vert.vert_num == w.vert_num) {
            w_in_v = true;
            v_edge_idx = (int) i;
        }
    }
    if (!w_in_v) {
        std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
        return;
    }

    bool v_in_w = false;
    int w_edge_idx = -1;
    std::string w_edge_label = "";
    for (size_t i = 0; i < w.edges.size(); ++i) {
        Vertex dest_vert = findVertex(w.edges.at(i).dest);
        if (dest_vert.vert_num == v.vert_num) {
            v_in_w = true;
            w_edge_idx = (int) i;
        }
    }

    if (!v_in_w) {
        std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
        return;
    }
    
    v.edges.at(v_edge_idx).label = label_str;
    w.edges.at(w_edge_idx).label = label_str;

}

/**
 * prints out a song recommendation based off of the inputed graph and song title
 * @param g Graph of all vertices and edges to generate a song recommendation
 * @param songTitle Title of song that will generate song recommendations based on closeness on the graph
 */
string getSongRecommendation(Graph g, string songTitle) {
    Vertex song_vertex;
    song_vertex.vert_num = -1;
    string songUpper = songTitle;
    transform(songUpper.begin(), songUpper.end(), songUpper.begin(), ::toupper);
    vector<Vertex> vertices = g.getVertices();

    // update song_vertex to hold onto the vector that has the same song title as the inputted song
    for (size_t i = 0; i < vertices.size(); i++) {
        string tmp = vertices[i].song_name;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        if (tmp == songUpper) {
            song_vertex = vertices[i];
        }
    }
    // checks to see if song_vertex was updated. If the song title was not found within the list of vertices, the function will return and print a message
    if (song_vertex.vert_num == -1) {
        return songTitle + " was not found in the database. Please try another song title.";
    }
    string out = songTitle + " found within the database. Pulling up a song recommendation.";
    return out;
}