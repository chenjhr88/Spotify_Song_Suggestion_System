#include <iostream>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"

int main() {
    Graph g;
    g.insertVertices("../data/genres_v2.csv", "../data/data.csv");

    cout<<"Song data acquired..."<<endl;
    cout<<""<<endl;
    //sets the adjacency matrix to all zeros
    g.setAdjacencyMatrix(g.getVertices().size());

    //insert the edges on the song
    cout<<"Creating map of your songs & song factors... please wait while we map your songs"<<endl;
    cout<<""<<endl;
    for (unsigned i = 0; i < g.getVertices().size(); i++) {
        for (unsigned j = 0; j < g.getVertices().size(); j++) {
            g.insertEdge(i, j);
        }
    }

    //creates individual maps for factors
    g.makeEdgeHueMapDance(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapEnergy(g.getAdjacencyMatrix().size());
    g.makeEdgeHueMapAcc(g.getAdjacencyMatrix().size());

    bool continueasking = true;

    //beginning user interation
    while (continueasking) {
        cout << "Enter the name of your favorite song and we will find a song recommendation for you!\n\nSong name: ";
        string songTitle;
        getline(cin, songTitle);
        cout << "\nEnter the category of interest (dancebility, acousticness, energy)\n\nCategory: ";
        string cat;
        getline(cin, cat);
        cout << getSongRecommendation(g, songTitle, cat) << endl;
        cout<<""<<endl;
        cout << "Would you like to see recommendations for another song? (Y/N)" << endl;
        cout<<""<<endl;
        string response;
        getline(cin, response);
        transform(response.begin(), response.end(), response.begin(), ::toupper);
        if (response != "Y" && response != "YES") {
            continueasking = false;
        }
    }

    return 0;
}