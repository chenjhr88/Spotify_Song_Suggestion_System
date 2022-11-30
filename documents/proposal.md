## Leading Question 
    Whether it be studying or working on assignments, Spotify always comes in clutch. Sometimes, it's hard to find music that's familiar to their tastes, but new at the same time. That is why we decided to create a graph connect how closely related songs are to each other in terms of qualities such as danceability, energy, popularity, genre and more for each song. With this, are we able to give suggestion(s) of songs to listen to, based on the liking for one song and what other songs share qualities with that song. We plan to use this Spotify dataset called "Datasets of Songs in Spotify": https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify in order to obtain our the data on the songs and qualities of songs (danceability, energy, popularity, genre and more) to produce a graph with vertices (song) which are connected through qualities such as danceability, energy, popularity, or more
    
## Dataset Acquisition
    We plan to use this Spotify dataset: https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify in order to obtain our the data for our graph. From this data, we will collect the songs, danceability, energy, popularity, genre and more for each song, in the form of a CSV, which will make it more straightforwrd to parse.
    
## Data Format
    The source of our dataset will be from the Spotify CSV: https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify. This subset will be defined as information about the user, artist, release year, and genre. We will collect the songs, danceability, energy, popularity, genre and more for each song. Each song will be defined as a vertex in our graph.
    
## Data Correction
    Hypothetically, if we were to encounter a missing entry on the dataset (e.g. no data about the user, artist, release year, or genre), we will skip the that entry and not include it in our graph. If we encounter any data that's an outlier or values that are not physically possible (e.g. release years that are negative or logically impossible), then we won't include the that data from our dataset. This will help avoid any error when inserting new vertices onto our graph.

## Data Storage
    To store all the data from the CSV, we plan to use a connected, weighted graph. The connected, weighted graph will in the form of an adjacency list. Each vertex will represent a song, and vertices will be connected through qualities such as danceability, energy, popularity, or more. To connect each vertex, the nodes that pass a certain threshold that we will decide for our chosen quality, will be connected to each other. 
    
    Using the adjacency list, our the total storage cost will be O(n + m), where n is the number of vertices and m is the number of edges. At worst, the total storage cost for our dataset will be O(n + m!) (n is number of vertices and m is number of edges).
    
    To visualize how strongly connected vertices are, we will have a changeHue() algorithm, which will change the color of the vertex connection based on how close the values of the qualities are. For example, if two vertices have a danceability factor of 90, they will be connected with a dark red line. If one vertex has a factor of 20, while the other is 90, the vertex will be a lighter red color. Our final algorithm will be a removeVertex() algorithm, which removes the vertex with the highest value of a specfied characteristic. The remove vertex algorithm should update all connections and colors accordingly. All of these algorithms will help us avoid any Out of Memory Issues when our graph becomes bigger. 

## Algorithm 
    Function Inputs
        We expect to input the data we obtained from the the Spotify CSV attached here: https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify. We will have to translate the data recieved from Spotify into a graph by creating Graph Vertices (which are songs) and connecting them to other vertices based on qualities like danceability, energy, popularity, genre and more for each song. The more common the qualities are for two vertices, the darker of a color hue is shared in the vertices connecting line.
        The expected input for the BFS traversal should be the starting vertex. This will help begin the BFS traversal, and we will be able to go through all the vertices.
        The input should be the edge itself between two vertices. Doing this would allow us to obtain the edge between the two vertices that we want to compare. Getting this edge would also help us determine what hue the edge should be, based on the relationship of the specificed characteristic between the two vertices of the edge.
        The removeVertex algorithm will input a starting vertex. This starting vertices will help us give the algorithm a place to start. It will allow algorithm will go through all the vertices in the graph from that starting vertex to find the highest value for the specified characteristic. 
    
    Function Outputs
        We shouldn't have an expected output of our BFS traversal algorithm. However, if we have time, the expected output would be the finished graph as a PNG. We would store our graph through an adjacency list, where each vertex would be a song and the edges would hold the quality (ie. danceability, energy, popularity, genre and more for each song). As of now, we can print out the vertices and edges through our adjacency list to display our graph. However, if possible, we want to find some way of having a clean display/visual of our graph in the form of a PNG output.
        The output of this algorithm should be the graph, but the hue of the edge will change. 
        The output should of the algorithm should be the graph itself, but the vertex with the highest value of the specified characteristic is removed. 
    
    Function Efficiency
        For BFS traversal, going through the graph will take about O(n + m), where n is the number of vertices and m is the number of edges. This is due to the BFS traversal we will be using in our algorithm to travel through the graph of songs. Adding vertices will take O(1), since we're using an adjacency list. Adding edges will be O(1), since we're using an adjacency list.
        For our changeHue algorithm, the runtime for this algorithm will be about O(1). This is due to us being about the access the vertices that create the selected edge through our adjacency list. These vertices will help us find what hue the edge should be.
        For our removeVertex algorithm, the runtime would be about O(n + m), where n is the number of vertices and m is the number of edges. This is due to our removeVertex algorithm having to ultilize BFS traversal in order to go through all the verticess in the graph. After going through all the vertices in the graph, we should then find the vertex with the highest value of the specified characteristic. Once we get that vertex, we then remove it, which should take about O(1). Hence, our overall runtime for the removeVertex algorithm will be O(n + m)

## Timeline
    Week 0 (10/30 - 11/5): Finish Proposal
    Week 1 (11/6 - 11/12): Produce README.md for git repo (github organziation and how to run project). Acquire and format data. Begin producing tests for algorithms. Begin working on BFS traversal algorithm.
    Week 2 (11/13 - 11/19): **Mid Project Check-in** - Have BFS traversal of our graph completed. 
    Week 3 (11/20 - 11/26): Develop recommendation algorithm based on weights between the vertices.
    Week 4 (11/27 - 12/2): continue to develop recommendation algorithm based on weights between the vertices.
    Week 5 (12/3 - 12/8): Finish rest of algorithms. Complete results.md write up.