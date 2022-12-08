#include <iostream>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"

int main() {
    Graph g;
    g.insertVertices("../data/genres_v2.csv", "../data/data.csv");

    //sets the adjacency matrix to all zeros
    g.setAdjacencyMatrix(g.getVertices().size());

    //insert the edges on the song
    for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            g.insertEdge(i, j);
        }
    }

    g.makeEdgeHueMapDance(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapEnergy(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapPop(g.getAdjacencyMatrix().size());

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