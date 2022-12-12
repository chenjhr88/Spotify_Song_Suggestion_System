# CS225 Final Project: S^4 (Spotify Song Suggestion System)

Group Members: Eisha Peyyeti, Hayden Kim, Justin Chen, Jason Kandula

To Note: 
- Factors = danceability, acousticness, or energy value
- Graph vertices = songs
- We had additional algorithms beyond this, however, this results document highlights just the primary algorithms we stated within the initial project proposal

Links:
- Dataset: https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify
- Mediaspace Recorded Presentation: https://mediaspace.illinois.edu/media/t/1_y47e7qhw

## Proposed Algorithms Output and Correctness
### Breadth First Search (BFS) Traversal Algorithm
- Runtime: 
    - O(n + m), where m is vertices and n is edges
- Output: The number of vertices traveled through (this helps us ensure that BFS is working)
- Summary:
    - Traverses through the graph
    - Label every edge and vertex in the graph as “UNEXPLORED”
    - Returns number of vertices traveled through
    - BFS helper function
        - Goes through the chosen vertex and every vertex that’s adjacent to that vertex.
        - Labels each vertex as “VISITED”
        - Labels each edge as “DISCOVERY” or “CROSS” accordingly
- Tests for Verification:
    - This algorithm was 100% correct and worked as intended/expected
    - We had test cases to verify this algorithm by ensuring that it traveled through the correct number of vertices within the graph without double counting vertices.
- Visualization:
    - ![BFSVisualization](/images/bfs.png)

### ChangeHue Algorithm
- Runtime: 
    - O(1) to change the hue of an edge
    - O(n) to iterate through and access the particular edge
- Output: no direct output of function (void function), but function changes value of hue on the designated map, as described below
- Summary:
    - Our graph exists of vertices (songs) connected by edges
    - Based on whether or not the songs are related by at least 1 factor (with a maximum difference of 0.1). 
    - We recognized that our algorithm should not just pick any song connected to the inputted song by an edge, but rather recommend a song based on how closely the factors of the two songs related to each other, whether the factor was danceability, acousticness, or energy. 
    - Already created individual maps (map<pair<string,string>, double) to map two songs connected by an edge (the pair) to the default hue of the edge connecting them (which was the average for the ‘factor’ of the songs).
        - Edges_to_hues_dance,
        - Edges_to_hues_acc
        - Edges_to_hues_energy
    - changeHue algorithm changes the hue on the edge between the two vertices (songs) based on how closely related the songs were for the factor inputted by the user
        - If the two songs differentiated by a maximum difference of 0.01 for the designated factor, a hue of 3.5 was added to the existing hue for the song pair in the map
        - Else if the two songs differentiated by a maximum difference of 0.05 for the designated factor, a hue of 2 was added to the existing hue for the song pair in the map
        - Else if the two songs differentiated by a maximum difference of 0.15 for the designated factor, a hue of 1 was added to the existing hue for the song pair in the map
        - Else if the two songs differentiated by a maximum difference of 0.1 for the designated factor, a hue of 0.25 was added to the existing hue for the song pair in the map.
        - Otherwise, the hue for the edge remained as is
- Tests for Verification:
    - This algorithm was 100% correct and worked as intended/expected
    - We had test cases to verify this algorithm. This test case ensured that our songRecommendation algorithm was recommending the correct song. In doing this, we were able to cross-verify that our changeHue algorithm was working correctly, as the songRecommendation algorithm should work to select the corresponding song with the largest weight/hue. Thus, we were able to verify it worked. In addition, throughout our development process, we utilized the console to print outputs and verify the hue for edges was changing correctly, and that the map from edges to hues for the respective factors was updating correctly as well.
- Visualization:
    - ![ChangeHue](/images/changehue.png)

### Remove Vertex Algorithm
- Runtime: 
    - O(1) to remove the node
- Output: no direct output of function (void function), but function will cause the vertex chosen to not appear in the Graph object that called that function. removeVertex will also remove any edges that relate with the chosen vertex num in the edges_to_hues_dance map, edges_to_hues_acc map, and edges_to_hues_energy map.
- Summary:
    - Takes in an inputted vertex number to then delete that vertex from the graph and its related edge factors
- Tests for Verification:
    - This algorithm was 100% correct and worked as intended/expected
    - Our test cases that helped to verify this algorithm checked to ensure that the requested vertex would be removed from the graph. It would then check to ensure that the program could still function correctly after the vertex and its related edges were removed.
- Visualization:
    - ![RemoveVertex](/images/removevert.png)

## Answer to Leading Question and Conclusions
- Our Answer to the Leading/Proposed Question:
    - We were successfully able to build a weighted, undirected graph of songs and factor relations. By doing so, we were successfully able to answer our proposal question to recommend songs from a dataset to users, based on a user inputted song and factor category from the dataset. This is all collectively accomplished through the usage of our main graph, as well as individual edge to hue maps for the respective factor categories.
        - ie. Our project, given a song A and energy A, recommends song B, which has an energy factor close to that of energy A
- Project Applications:
    - This project has real world implications as it can be used to help anyone discover new songs based on their favorite songs and their properties.
- Our Discoveries:
    - We discovered that we needed to be realistic about the number of songs we could use within the input dataset. We initially had around 40,000 songs within the initial dataset. This is an unrealistic number of songs we could use within an input dataset as an average Spotify playlist is about 100-200 songs long.
        - Building an x by x sized adjacency matrix for a large dataset is unrealistic for run time
- Future Development:
    - This program could be further improved by improving the efficiency of the algorithms by being able to process each of the 40,000+ songs in the initial dataset.