#include "adjacencylist.h"

void Graph::insertVertices() {
    //read csv file
    //  ifstream to read file
    //  split string by ',' or ' '
    //  string to int (stoi)
    translateData("genres_v2.csv", "data.csv");
    std::ifstream ifs("data.csv");
    std::string to_input = "";
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
    std::ifstream ifs(datainput);
    std::ofstream ofs(dataoutput);

    int num = 0;
    bool skip = true;
    std::string to_input = "";
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