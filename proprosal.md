## Leading Question 
    Whether it be studying or working on assignments, Spotify always comes in clutch. Sometimes, it's hard to find music that's familiar to their tastes, but new at the same time. That is why we decided to create a graph connecthow closely related users are to each other in terms of their music taste. That way, users can find new music.
    
## Dataset Acquisition
    We plan to use the Spotify API in order to obtain our dataset. From this data, we will collect the artist, release year, and genre and place it within a CSV file..
    
## Data Format
    The source of our dataset will be from the Spotify API. We plan to make the dataset large enough for users to have a wide range of new music to see from other users/friends. We will use a subset of the data given from the Spotify API. This subset will be defined as information about the user, artist, release year, and genre.
    
## Data Correction
    Hypothetically, if we were to encounter a missing entry on the dataset (e.g. no data about the user, artist, release year, or genre), we will skip the that entry and not include it in our graph. If we encounter any data that's an outlier or values that are not physically possible (e.g. release years that are negative or logically impossible), then we won't include the that data from our dataset. This will help avoid any error when inserting new nodes onto our graph.

## Data Storage
    To store all the data we obtained from the Spotify API, we plan to use a connected, weighted graph. each node will represent a user, and each node will be connected through similar artists, genres, or release year (implement a priority system on which data is most important to compare (important to least important: genre, artist, release year). In order to connect each node, we'll use BFS traversal. This will help us avoid any Out of Memory Issues when our graph becomes bigger. Overall, our runtime for our dataset storage will be O(n + m) due to the BFS traversal. At worst, the total storage cost for our dataset will be O(n!).

## Algorithm 

## Timeline
    Week 1:
    Week 2:
    Week 3: