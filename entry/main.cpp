#include <iostream>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"

int main() {
    Graph g;
    g.insertVertices("../data/genres_v2.csv", "../data/data.csv");
    // vector<vector<int>> adjmat = g.buildAdjacencyMatrix(g.getVertices());
    // g.makeEdgeHueMapDance(adjmat);
    // g.makeEdgeHueMapEnergy(adjmat);
    // g.makeEdgeHueMapPop(adjmat);


    bool continueasking = true;

    while (continueasking) {
        cout << "Enter the name of your favorite song and we will find a song recommendation for you!\nSong name: ";    
        string songTitle;
        getline(cin, songTitle);
        cout << "Enter the category of interest (dancabililty, popularity, energy)\nCategory: ";
        string cat;
        getline(cin, cat);
        cout << getSongRecommendation(g, songTitle,cat) << endl;
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