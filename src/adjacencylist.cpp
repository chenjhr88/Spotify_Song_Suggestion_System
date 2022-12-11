#include "adjacencylist.h"

using namespace std;

/**
 * Graph constructor
 */
Graph::Graph() {}

//
//FUNCTIONS PERTAINING TO ADJACENCY LIST
//

/**
 * Builds an adjacency list from an adjacency matrix
 * @param adjacencyMatrix matrix to be built as a list
 */
void Graph::convertToAdjacencyList(vector<vector<int>> adjacencyMatrix) {
    adjacencyList.resize(adjacencyMatrix.size());
    for (size_t i = 0; i < adjacencyMatrix.size(); i++) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); j++) {
            if (adjacencyMatrix[i][j] == 1) {
                adjacencyList[i].push_back(j);
            }
        }
    }
}

/**
 * Returns the graph's adjacency list
 */
vector<vector<int>> Graph::getAdjacencyList() {
    return adjacencyList;
}

//
//FUNCTIONS PERTAINING TO THE HUE OF AN EDGE ON OUR GRAPH
//

/**
 * Changes the hue on the edge between two vertices (songs) based on the factor inputted by the user
 * The default hue along the edge for connected nodes is the averge factor (dancebility, acousticness, energy) value for the songs
 * For songs with no edge connecting them, the hue is zero, and this algorithm will not be called during the map build
 * Changes the hue for map<pair<string, string>, int> edges_to_hues_dance, edges_to_hues_acc, edges_to_hues_energy
 * @param song1 which is the first vertex accounted for
 * @param song2 which is the second vertex accounted for
 * @param factor which is inputted by the user (ie. dancebility, acousticness, energy)
 */
void Graph::changeHue(string song1, string song2, string factor) {

    if (factor == "dancebility") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_dance.find(looking_for); 
        if (it != edges_to_hues_dance.end()) {
            if ((abs(getDancebility(it->first.first)-getDancebility(it->first.second)) <= 0.01)) {
                it->second += 3.5;
            } else if ((abs(getDancebility(it->first.first)-getDancebility(it->first.second)) <= 0.05)) {
                it->second += 2;
            } else if ((abs(getDancebility(it->first.first)-getDancebility(it->first.second)) <= 0.15)) {
                it->second += 1;
            } else if ((abs(getDancebility(it->first.first)-getDancebility(it->first.second)) <= 0.1)) {
                it->second += .25;
            }
        }
    }

    if (factor == "acousticness") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_acc.find(looking_for); 
        if (it != edges_to_hues_acc.end()) {
            if ((abs(getAcousticness(it->first.first)-getAcousticness(it->first.second)) <= 0.01)) {
                it->second += 3.5;
            } else if ((abs(getAcousticness(it->first.first)-getAcousticness(it->first.second)) <= 0.05)) {
                it->second += 2;
            } else if ((abs(getAcousticness(it->first.first)-getAcousticness(it->first.second)) <= 0.15)) {
                it->second += 1;
            } else if ((abs(getAcousticness(it->first.first)-getAcousticness(it->first.second)) <= 0.1)) {
                it->second += .25;
            }
        }
    }

    if (factor == "energy") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_energy.find(looking_for); 
        if (it != edges_to_hues_energy.end()) {
            if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.01)) {
                it->second += 3.5;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.05)) {
                it->second += 2;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.15)) {
                it->second += 1;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.1)) {
                it->second += .25;
            }
        }
    }

}

/**
 * Returns the dancebility factor (double) for a song
 * @param song which is the song to output the factor for
 */
double Graph::getDancebility(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].dancebility;
        }
    }
    return 0;
}

/**
 * Returns the acousticness factor (double) for a song
 * @param song which is the song to output the factor for
 */
double Graph::getAcousticness(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].acousticness;
        }
    }
    return 0;
}

/**
 * Returns the energy factor (double) for a song
 * @param song which is the song to output the factor for
 */
double Graph::getEnergy(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].energy;
        }
    }
    return 0;
}

/**
 * Returns the map for the edges to hues of the edges on the graph pertaining to the dancebility factor of songs
 */
map<pair<string, string>, double> Graph::getEdgesToHuesDance() {
    return edges_to_hues_dance;
}

/**
 * Returns the map for the edges to hues of the edges on the graph pertaining to the acousticness factor of songs
 */
map<pair<string, string>, double> Graph::getEdgesToHuesAcc() {
    return edges_to_hues_acc;
}

/**
 * Returns the map for the edges to hues of the edges on the graph pertaining to the energy factor of songs
 */
map<pair<string, string>, double> Graph::getEdgesToHuesEnergy() {
    return edges_to_hues_energy;
}

/**
 * Creates a map between the edges to the hues of edges on graph pertaining to the dancebility factor of songs
 * The default hue is the average value of the dancebility factors of the two songs connected by an edge determined earlier
 * After the default hue is applied, we may change the hue accordingly to the changeHue formula
 * For two songs with no edge between them, the hue is 0
 * @param size of the adjacency matrix to map the songs accordingly
 */
void Graph::makeEdgeHueMapDance(int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_dance.insert({edge, (vertices.at(i).dancebility + vertices.at(j).dancebility)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "dancebility");
            } else {
                edges_to_hues_dance.insert({edge, 0});
            }
        }
    }
}

/**
 * Creates a map between the edges to the hues of edges on graph pertaining to the acousticness factor of songs
 * The default hue is the average value of the acousticness factors of the two songs connected by an edge determined earlier
 * After the default hue is applied, we may change the hue accordingly to the changeHue formula
 * For two songs with no edge between them, the hue is 0
 * @param size of the adjacency matrix to map the songs accordingly
 */
void Graph::makeEdgeHueMapAcc(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_acc.insert({edge, (vertices.at(i).acousticness + vertices.at(j).acousticness)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "acousticness");
            } else {
                edges_to_hues_acc.insert({edge, 0});
            }
        }
    }
}

/**
 * Creates a map between the edges to the hues of edges on graph pertaining to the energy factor of songs
 * The default hue is the average value of the energy factors of the two songs connected by an edge determined earlier
 * After the default hue is applied, we may change the hue accordingly to the changeHue formula
 * For two songs with no edge between them, the hue is 0
 * @param size of the adjacency matrix to map the songs accordingly
 */
void Graph::makeEdgeHueMapEnergy(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_energy.insert({edge, (vertices.at(i).energy + vertices.at(j).energy)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "energy");
            } else {
                edges_to_hues_energy.insert({edge, 0});
            }
        }
    }
}

/**
 * Determines if a vector contains an item of interest
 * @param my_vec vector to be searched
 * @param item_looking item of interest
 */
bool Graph::contains(std::vector<std::string> my_vec, std::string item_looking) {
    for (unsigned i = 0; i < my_vec.size(); i++) {
        if (my_vec.at(i) == item_looking) {
            return true;
        }
    }
    return false;
}

//
//FUNCTIONS TRANSLATING INPUTTED DATA INTO MEANINGFUL DATA STRUCTURES
//

/** 
 * Splits a string by a character and places into a std::vector<std::string> passed in by reference
 * @param str1 string to be split
 * @param sep char to define where string will be split
 * @param fields vector of where split strings will be placed
 * 
 * Function: SplitString
 * Author: CS225 Staff
 * Date: 2022
 * Original Code From: FA22 Release mp_schedule
 **/ 
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
    size_t numsections = 0;
    bool is_first = true;
    for (string line ; getline(ifs, line);) {
        std::vector<std::string> parse_line;
        SplitString(line, ',', parse_line);
        if (!is_first && numsections == parse_line.size()) {
            if (parse_line.at(19) != "") {
                ofs << num << "," << parse_line.at(0) << "," << parse_line.at(6) << "," << parse_line.at(19) << "," << parse_line.at(1)  <<  std::endl;
                num++;
            }
        } else {
            numsections = parse_line.size();
            is_first = false;
        }
    }
}

//
//FUNCTIONS FOR INSERTING ELEMENTS INTO THE GRAPH CORRECTLY
//

/**
 * inserts a vertex into the graph
 * @param v vertex to be inserted
 */
void Graph::insertVertex(Vertex v) {
    vertices.push_back(v);
}

/**
 * Inserts edge between two vertices
 * The default edge between two songs should have a minimum difference (for at least 1 factor) of just 0.1. Change hue will specify the likeness further.
 * @param v1 vertex one to build an edge between v2
 * @param v2 vertex two to build an edge between v1
 */
void Graph::insertEdge(int v1, int v2) {
    Edge e1 = {0, v2, ""};
    Edge e2 = {0, v1, ""};

    if ((abs(vertices.at(v1).dancebility-vertices.at(v2).dancebility) <= 0.1) || (abs(vertices.at(v1).energy-vertices.at(v2).energy) <= 0.1) || (abs(vertices.at(v1).acousticness-vertices.at(v2).acousticness) <= 0.1)) {
        vertices.at(v1).edges.push_back(e1);
        if (vertices.at(v1).song_name != vertices.at(v2).song_name) {
            adjacency_matrix[v1][v2] = 1;
        } else {
            adjacency_matrix[v1][v2] = 0;
        }
    } else {
        adjacency_matrix[v1][v2] = 0;
    }
}

/**
 * This function will insert vertices from the given file and input them into the graph's vector of vertices
 * @param filename name of the file to be read and parsed for data
 * @param filewrite name of the file for data to be written to
 * 
 */
void Graph::insertVertices(string filename, string filewrite) {
    // read csv file
    // ifstream to read file
    // split string by ',' or ' '
    // string to double (stod)
    translateData(filename, filewrite);
    ifstream ifs(filewrite);
    if (ifs.good()) {
        // read each line, each line represnts a vertex
        for (string line ; getline(ifs, line); ) {
            vector<string> insert;
            SplitString(line, ',', insert);
            std::vector<Edge> edges;
            // get the song name + characteristics (dancebility, acousticness, energy)
            // create the vertex struct
            Vertex to_insert = {std::stoi(insert.at(0)), std::stod(insert.at(1)), 0, std::stod(insert.at(2)), insert.at(3), "", edges};
            // add the vertex to the vertices vector if song title is not empty
            if (to_insert.song_name != "") {
                vertices.push_back(to_insert);    
            }
        }
    }
}


//
//FUNCTIONS FOR THE GRAPH ADJACENCY MATRIX
//

vector<vector<int>> Graph::getAdjacencyMatrix() {
    return adjacency_matrix;
}

void Graph::setAdjacencyMatrix(int size) {
    for(int i=0; i<size; i++){
        std::vector <int> temp;
        for (int j=0; j< size; j++){
            temp.push_back(0);
        }
        adjacency_matrix.push_back(temp);
    }
}


//
//FUNCTIONS FOR ACCESSING GRAPH PROPERTIES OF DATASET
//

/**
 * Returns vector of all song titles within the inputted dataset
 */
std::vector<string> Graph::getAllSongTitles(){
    all_songs.clear();
    for (size_t i = 0; i < vertices.size(); i++) {
        all_songs.push_back(vertices.at(i).song_name);
    }
    return all_songs;
}

/**
 * Returns vector of all song danacbility factor values (double) within the inputted dataset
 */
std::vector<double> Graph::getAllSongDance(){
    all_dance.clear();
    for (size_t i = 0; i < vertices.size(); i++) {
        all_dance.push_back(vertices.at(i).dancebility);
    }
    return all_dance;
}

/**
 * Returns vector of all song acousticness factor values (double) within the inputted dataset
 */
std::vector<double> Graph::getAllSongAcc(){
    all_acc.clear();
    for (size_t i = 0; i < vertices.size(); i++) {
        all_acc.push_back(vertices.at(i).acousticness);
    }
    return all_acc;
}

/**
 * Returns vector of all song energy factor values (double) within the inputted dataset
 */
std::vector<double> Graph::getAllSongEnergy(){
    all_energy.clear();
    for (size_t i = 0; i < vertices.size(); i++) {
        all_energy.push_back(vertices.at(i).energy);
    }
    return all_energy;
}


//
//FUNCTIONS FOR ACCESSING GRAPH VERTICES AND EDGES
//

/**
 * Returns vector of vertices within the graph
 */
std::vector<Vertex> Graph::getVertices() {
    return vertices;
}

/**
 * Get the vertex
 * @param vert_num index of requested vertex within the verticies list
 */
Vertex Graph::findVertex(int vert_num) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i).vert_num == vert_num) {
            return vertices.at(i);
        }
    }

    return vertices.at(0);
}

/**
 * Return a list of adjacent vertices to a requested vertex
 * @param v vertex that will return its adjacent nodes
 */
std::vector<Vertex> Graph::getAdjacents(Vertex v) {
    std::vector<Vertex> adjacents;
    //std::cout << "at " << v.vert_num << " There are " << v.edges.size() << " edges" << std::endl;
    size_t v_idx = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i).vert_num == v.vert_num) {
            v_idx = i;
        }
    }

    for (size_t i = 0; i < vertices[v_idx].edges.size(); ++i) {
        Vertex v1 = findVertex(vertices[v_idx].edges.at(i).dest);
        adjacents.push_back(v1);
    }

    return adjacents;
}

/**
 * Return the label of a vertex
 * @param v vertex of interest
 */
std::string Graph::getLabel(Vertex v) {
    return v.label;
}

/**
 * Set the label of a vertex of interest
 * @param v vertex that we will change the label of
 * @param label_str label to be given to vector
 */
void Graph::setLabel(Vertex& v, std::string label_str) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i].vert_num == v.vert_num) {
            vertices[i].label = label_str;
        }
    }
    
}

/**
 * Retrieves the label of an edge of interest
 * @param e edge to get label of
 */
std::string getLabel(Edge e) {
    return e.label;
}

/**
 * Set the label of an edge of interest
 * @param e edge that we will change the label of
 * @param label_str label to be given to vector
 */
void Graph::setLabel(Edge& e, std::string label_str) {
    e.label = label_str;
}

/**
 * Find an edge between two verticies and return its label
 * @param v vertex 1 of edge
 * @param w vertex 2 of edge
 */
std::string Graph::getLabel(Vertex v, Vertex w) {
    // std::cout << "get the Label between " << v.vert_num << " and " << w.vert_num << std::endl;

    size_t v_idx = 0;
    size_t w_idx = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i).vert_num == v.vert_num) {
            v_idx = i;
        }

        if (vertices.at(i).vert_num == w.vert_num) {
            w_idx = i;
        }
    }

    bool w_in_v = false;
    std::string v_edge_label = "";
    for (size_t i = 0; i < vertices[v_idx].edges.size(); ++i) {
        Vertex dest_vert = findVertex(vertices[v_idx].edges.at(i).dest);
        /*std::cout << "vert v: " << vertices[v_idx].vert_num << " to " << vertices[v_idx].edges.at(i).dest << std::endl;
        std::cout << "edges v is labelled " << vertices[v_idx].edges.at(i).label << std::endl;*/
        if (dest_vert.vert_num == w.vert_num) {
            w_in_v = true;
            v_edge_label = vertices[v_idx].edges.at(i).label;
        }
    }
    if (!w_in_v) {
        std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
        return "ERROR0";
    }

    bool v_in_w = false;
    std::string w_edge_label = "";
    for (size_t i = 0; i < vertices[w_idx].edges.size(); ++i) {
        Vertex dest_vert = findVertex(vertices[w_idx].edges.at(i).dest);
        //std::cout << "vert w: " << vertices[w_idx].vert_num << " to " << vertices[w_idx].edges.at(i).dest << std::endl;
        //std::cout << "edges w is labelled " << vertices[w_idx].edges.at(i).label << std::endl;
        if (dest_vert.vert_num == v.vert_num) {
            v_in_w = true;
            w_edge_label = vertices[w_idx].edges.at(i).label;
        }
    }
    
    if (!v_in_w) {
        std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
        return "ERROR1";
    }

    if (v_edge_label == w_edge_label) {
        return v_edge_label;
    }   else {
        //std::cout << "vertex v " << v.vert_num << " vertex w " << w.vert_num << std::endl;
        //std::cout << "v e : " << v_edge_label << ", w e: " << w_edge_label << std::endl;
        std::cout << "EDGE LABELS DON'T MATCH!" << std::endl;
        return "ERROR3";
    }

}

/**
 * Set the label of an edge between v and w
 * @param v vertex one of edge label to be set
 * @param w vertex two of edge label to be set
 * @param label_str label to be given to the edge
 */
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

    size_t v_idx = 0;
    size_t w_idx = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices.at(i).vert_num == v.vert_num) {
            v_idx = i;
        }

        if (vertices.at(i).vert_num == w.vert_num) {
            w_idx = i;
        }
    }
    
    vertices[v_idx].edges.at(v_edge_idx).label = label_str;
    vertices[w_idx].edges.at(w_edge_idx).label = label_str;
    //std::cout << "v " << vertices[v_idx].vert_num << " at: " << vertices[v_idx].edges.at(v_edge_idx).label << std::endl;
    //std::cout << "w " << vertices[w_idx].vert_num << " at: " << vertices[w_idx].edges.at(w_edge_idx).label << std::endl;
}


//
//FUNCTION FOR RECOMMENDING A SONG BASED ON THE MAP/GRAPH STRUCTURE
//

/**
 * prints out a song recommendation based off of the inputed graph and song title
 * @param g Graph of all vertices and edges to generate a song recommendation
 * @param songTitle Title of song that will generate song recommendations based on closeness on the graph
 */
string getSongRecommendation(Graph& g, string& songTitle, const string& category) {
    // create new song_vertex and set its vert_num to -1 for update comparisons
    Vertex song_vertex;
    song_vertex.vert_num = -1;
    // set song to upper case for comparison
    string songUpper = songTitle;
    transform(songUpper.begin(), songUpper.end(), songUpper.begin(), ::toupper);
    vector<Vertex> vertices = g.getVertices();
    // update song_vertex to hold onto the vector that has the same song title as the inputted song
    for (size_t i = 0; i < vertices.size(); i++) {
        string tmp = vertices[i].song_name;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
        // compare upper case song titles to see if they are the same
        // if they are the same, set song_vertex to the current vertex
        if (tmp == songUpper) {
            song_vertex = vertices[i];
        }
    }
    // checks to see if song_vertex was updated. If the song title was not found within the list of vertices, the function will return and print a message
    if (song_vertex.vert_num == -1) {
        cout<<""<<endl;
        return songTitle + " was not found in the database. Please try another song title.";
    }
    
    // runs when songTitle is found within the database
    songTitle = song_vertex.song_name;
    cout<<""<<endl;
    cout << songTitle + " found within the database. Pulling up a song recommendation." << endl;

    map<pair<string, string>, double> mapofinterest;
    if (category == "dancebility")
        mapofinterest = g.getEdgesToHuesDance();
    else if (category == "acousticness")
        mapofinterest = g.getEdgesToHuesAcc();
    else if (category == "energy")
        mapofinterest = g.getEdgesToHuesEnergy();
    else
        return category + " is not a valid category";
    
    string bestsong = "";
    int strength = -1;
    vector<string> all_songs = g.getAllSongTitles();
    for (size_t i = 0; i < all_songs.size(); i++) {
        if (songTitle != all_songs.at(i)) {
            for (auto itr = mapofinterest.begin(); itr != mapofinterest.end(); ++itr) {
                if (songTitle == itr->first.first && all_songs.at(i) == itr->first.second && strength < itr->second) {
                    strength = itr->second;
                    bestsong = itr->first.second;
                    break;
                }
            }
        }
    }
    if (bestsong == "") {
        cout<<""<<endl;
        return "We could not find any related songs to you requested song. Please try another song title and category combination.";
    }
    cout<<""<<endl;
    return "Your song recommendation for \"" + songTitle + "\" under the \'" + category + "\' category is: \"" + bestsong + "\"\n";
}