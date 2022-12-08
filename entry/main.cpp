#include <iostream>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"

int main() {
    Graph g;
    g.insertVertices("../data/genres_v2.csv", "../data/data.csv");
    cout << "vertices entered" << endl;
    vector<vector<string>> string_vertex = g.vertexToString();
    cout << "vertex to string made" <<endl;
    vector<vector<int>> adjmat = g.buildAdjacencyMatrix(string_vertex);
    cout << "adjmatrix made" <<endl;
    g.makeEdgeHueMapDance(adjmat);
    cout << "dance hue map made" <<endl;
    g.makeEdgeHueMapEnergy(adjmat);
    cout << "energy hue map made" <<endl;
    g.makeEdgeHueMapPop(adjmat);
    cout << "popularity hue map made" <<endl;

    bool continueasking = true;

    while (continueasking) {
        cout << "Enter the name of your favorite song and we will find a song recommendation for you!\nSong name: ";    
        string songTitle;
        getline(cin, songTitle);
        cout << "Enter the category of interest (dancabililty, popularity, energy)\nCategory: ";
        string cat;
        getline(cin, cat);
        cout << getSongRecommendation(g, songTitle, cat) << endl;
        cout << "Would you like to see recommendations for another song? (Y/N)" << endl;
        string response;
        getline(cin, response);
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response != "Y" && response != "YES") {
            continueasking = false;
        }
    }

    return 0;
}