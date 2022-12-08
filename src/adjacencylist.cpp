#include "adjacencylist.h"

using namespace std;

/**
 * Graph constructor
 */
Graph::Graph() {}

/**
 * Builds an adjacency list from and adjacency matrix
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

map<pair<string, string>, double> Graph::getEdgesToHuesDance() {
    return edges_to_hues_dance;
}

map<pair<string, string>, double> Graph::getEdgesToHuesPop() {
    return edges_to_hues_pop;
}

map<pair<string, string>, double> Graph::getEdgesToHuesEnergy() {
    return edges_to_hues_energy;
}


//the default hue is the avergage value of the two factors of the songs connected by an edge determined earlier (ie. average dancability for songs)
//after the default hue is applied, we may change the hue accordingly to the changeHue formula
//for no edge for songs, the hue is 0
void Graph::makeEdgeHueMapDance(int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_dance.insert({edge, (vertices.at(i).dancability + vertices.at(j).dancability)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "dancability");
            } else {
                edges_to_hues_dance.insert({edge, 0});
            }
        }
    }
}

void Graph::makeEdgeHueMapPop(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_pop.insert({edge, (vertices.at(i).popularity + vertices.at(j).popularity)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "pop");
            } else {
                edges_to_hues_pop.insert({edge, 0.5});
            }
        }
    }
}

void Graph::makeEdgeHueMapEnergy(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::pair<string,string> edge = std::make_pair(vertices.at(i).song_name, vertices.at(j).song_name);
            if (adjacency_matrix[i][j] == 1) {
                edges_to_hues_energy.insert({edge, (vertices.at(i).energy + vertices.at(j).energy)/2});
                changeHue(vertices.at(i).song_name, vertices.at(j).song_name, "energy");
            } else {
                edges_to_hues_energy.insert({edge, 0.5});
            }
        }
    }
}



//the default hue along the edge for connected nodes is the averge factor (dancability, popularity, energy) value for the songs
//for songs with no edge connecting them, the hue is zero, and this algorithm will not be called during the map build
//changes the hue for map<pair<string, string>, int> edges_to_hues_dance, edges_to_hues_pop, edges_to_hues_energy
//if two songs have a factor (dancability, popularity, energy) value within 0.05 of eachother, the edge hue increases by 2.5
//if two songs have a factor (dancability, popularity, energy) value within 0.1 of eachother, the edge hue increases by 2
//if two songs have a factor (dancability, popularity, energy) value within 0.2 of eachother, the edge hue increases by 1.5
//if two songs have a factor (dancability, popularity, energy) value within 0.25 of eachother, the edge hue increases by 1

void Graph::changeHue(string song1, string song2, string factor) {

    if (factor == "dancability") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_dance.find(looking_for); 
        if (it != edges_to_hues_dance.end()) {
            if ((abs(getDancability(it->first.first)-getDancability(it->first.second)) <= 0.05)) {
                it->second += 2.5;
            } else if ((abs(getDancability(it->first.first)-getDancability(it->first.second)) <= 0.1)) {
                it->second += 2;
            } else if ((abs(getDancability(it->first.first)-getDancability(it->first.second)) <= 0.2)) {
                it->second += 1.5;
            } else if ((abs(getDancability(it->first.first)-getDancability(it->first.second)) <= 0.25)) {
                it->second += 1;
            }
        }
    }

    if (factor == "popularity") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_pop.find(looking_for); 
        if (it != edges_to_hues_pop.end()) {
            if ((abs(getPopularity(it->first.first)-getPopularity(it->first.second)) <= 0.05)) {
                it->second += 2.5;
            } else if ((abs(getPopularity(it->first.first)-getPopularity(it->first.second)) <= 0.1)) {
                it->second += 2;
            } else if ((abs(getPopularity(it->first.first)-getPopularity(it->first.second)) <= 0.2)) {
                it->second += 1.5;
            } else if ((abs(getPopularity(it->first.first)-getPopularity(it->first.second)) <= 0.25)) {
                it->second += 1;
            }
        }
    }

    if (factor == "energy") {
        std::pair<string,string> looking_for = std::make_pair(song1, song2);
        std::map<pair<string, string>, double>::iterator it = edges_to_hues_energy.find(looking_for); 
        if (it != edges_to_hues_energy.end()) {
            if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.05)) {
                it->second += 2.5;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.1)) {
                it->second += 2;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.2)) {
                it->second += 1.5;
            } else if ((abs(getEnergy(it->first.first)-getEnergy(it->first.second)) <= 0.25)) {
                it->second += 1;
            }
        }
    }

}

double Graph::getDancability(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].dancability;
        }
    }
    return 0;
}

double Graph::getPopularity(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].popularity;
        }
    }
    return 0;
}

double Graph::getEnergy(string song) {
    for (unsigned i = 0; i < vertices.size(); i++) {
        if (vertices[i].song_name == song) {
            return vertices[i].energy;
        }
    }
    return 0;
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

/**
 * This function will insert vertices from the given file and input them into the graph's vector of vertices
 * @param string filename name of the file to be read and parsed for data
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
            // get the song name + characteristics (dancability, popularity, energy)
            // create the vertex struct
            Vertex to_insert = {std::stoi(insert.at(0)), std::stod(insert.at(1)), 0, std::stod(insert.at(2)), insert.at(3), "", edges};
            // add the vertex to the vertices vector if song title is not empty
            if (to_insert.song_name != "") {
                vertices.push_back(to_insert);    
            }
        }
    }
}

/** 
 * Splits a string by a character and places into a std::vector<std::string> passed in by reference
 * @param str1 string to be split
 * @param sep char to define where string will be split
 * @param fields vector of where split strings will be placed
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
    size_t numsections = 0;
    bool is_first = true;
    for (string line ; getline(ifs, line);) {
        std::vector<std::string> parse_line;
        SplitString(line, ',', parse_line);
        if (!is_first && numsections == parse_line.size()) {
            if (parse_line.at(19) != "") {
                ofs << num << "," << parse_line.at(0) << "," << 0 << "," << parse_line.at(19) << "," << parse_line.at(1)  <<  std::endl;
                num++;
            }
        } else {
            numsections = parse_line.size();
            is_first = false;
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

/**
 * Inserts edge between two vertices
 * The default edge should have a minimum difference of just 0.3. Change hue will specify the likeness further.
 * @param v1 vertex one to build an edge between v2
 * @param v2 vertex two to build an edge between v1
 */
void Graph::insertEdge(int v1, int v2) {
    Edge e1 = {0, v2, ""};
    Edge e2 = {0, v1, ""};

    if ((abs(vertices.at(v1).dancability-vertices.at(v2).dancability) <= 0.3) && (abs(vertices.at(v1).energy-vertices.at(v2).energy) <= 0.3) && (abs(vertices.at(v1).popularity-vertices.at(v2).popularity) <= 0.3)) {
        vertices.at(v1).edges.push_back(e1);
        vertices.at(v2).edges.push_back(e2);
        if (vertices.at(v1).song_name != vertices.at(v2).song_name) {
            adjacency_matrix[v1][v2] = 1;
            adjacency_matrix[v2][v1] = 1;
        } else {
            adjacency_matrix[v1][v2] = 0;
            adjacency_matrix[v2][v1] = 0;
        }
    } else {
        adjacency_matrix[v1][v2] = 0;
        adjacency_matrix[v2][v1] = 0;
    }

    // std::cout << vertices.at(v1).edges.at(0).dest << std::endl;
}

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
//FUNCTIONS FOR ACCESSING GRAPH VERTICES AND EDGES
//

/**
 * Returns vector of vertices within the graph
 */
std::vector<Vertex> Graph::getVertices() {
    return vertices;
}

std::vector<string> Graph::getAllSongTitles(){
    for (size_t i = 0; i < vertices.size(); i++) {
        all_songs.push_back(vertices.at(i).song_name);
    }
    return all_songs;
}

std::vector<double> Graph::getAllSongDance(){
    for (size_t i = 0; i < vertices.size(); i++) {
        all_dance.push_back(vertices.at(i).dancability);
    }
    return all_dance;
}

std::vector<double> Graph::getAllSongPop(){
    for (size_t i = 0; i < vertices.size(); i++) {
        all_pop.push_back(vertices.at(i).popularity);
    }
    return all_pop;
}

std::vector<double> Graph::getAllSongEnergy(){
    for (size_t i = 0; i < vertices.size(); i++) {
        all_energy.push_back(vertices.at(i).energy);
    }
    return all_energy;
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
    // std::cout << "at " << v.vert_num << " There are " << v.edges.size() << " edges" << std::endl;
    for (size_t i = 0; i < v.edges.size(); ++i) {
        Vertex v1 = findVertex(v.edges.at(i).dest);
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
    int curr_vertex_idx = v.vert_num;
    vertices.at(curr_vertex_idx).label = label_str;
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
        // std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
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
        // std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
        return "ERROR1";
    }

    if (v_edge_label == w_edge_label) {
        return v_edge_label;
    }   else {
        // std::cout << "EDGE LABELS DON'T MATCH!" << std::endl;
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
        // std::cout << "vertex v doesn't connect to vertex w!" << std::endl;
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
        // std::cout << "vertex w doesn't connect to vertex v!" << std::endl;
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
string getSongRecommendation(Graph& g, const string& songTitle, const string& category) {
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
        return songTitle + " was not found in the database. Please try another song title.";
    }
    
    // runs when songTitle is found within the database
    string out = songTitle + " found within the database. Pulling up a song recommendation.\n";

    map<pair<string, string>, double> mapofinterest;
    if (category == "dancability")
        mapofinterest = g.getEdgesToHuesDance();
    else if (category == "popularity")
        mapofinterest = g.getEdgesToHuesPop();
    else if (category == "energy")
        mapofinterest = g.getEdgesToHuesEnergy();
    else
        return category + " is not a valid category";
    
    string bestsong = "";
    int strength = -1;
    vector<string> all_songs = g.getAllSongTitles();
    for (size_t i = 0; i < all_songs.size(); i++) {
        std::pair<string, string> new_pair(songTitle, all_songs.at(i));
        for (auto itr = mapofinterest.begin(); itr != mapofinterest.end(); ++itr) {
            if (new_pair.first == itr->first.first && new_pair.second != itr->first.second && strength < itr->second) {
                strength = itr->second;
                bestsong = itr->first.second;
            }
        }
    }
    return out + "Your song recommendation for " + songTitle + " under the " + category + " is: " + bestsong + "\n";
}

vector<vector<string>> Graph::vertexToString() {
    vector<vector<string>> out;
    out.resize(vertices.size());
    for (size_t vert_num = 0; vert_num < vertices.size(); vert_num++) {
        out[vert_num].push_back(to_string(vertices[vert_num].vert_num));
        out[vert_num].push_back(to_string(vertices[vert_num].dancability));
        out[vert_num].push_back(to_string(vertices[vert_num].popularity));
        out[vert_num].push_back(to_string(vertices[vert_num].energy));
        out[vert_num].push_back(vertices[vert_num].song_name);
        out[vert_num].push_back(vertices[vert_num].label);
    }
    return out;
}