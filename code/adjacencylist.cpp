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

}

void translateData(const std::string& datainput, const std::string& dataoutput) {
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