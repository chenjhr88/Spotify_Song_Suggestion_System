#include <iostream>
#include "adjacencylist.cpp"
#include "bfs_traversal.hpp"

int main() {
    Graph g;
    g.insertVertices("../data/genres_v2.csv", "../data/data.csv");
    cout << "Enter the name of your favorite song and we will find another song recommendation for you!\nSong name: ";
    string songTitle;
    getline(cin, songTitle);
    cout << getSongRecommendation(g, songTitle) << endl;

    return 0;
}