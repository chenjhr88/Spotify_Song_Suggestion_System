# CS225 Final Project: $S^{4}$ (Spotify Song Suggestion System)
<p align="center">
  <a href="#project-summary">Project Summary</a> •
  <a href="#running-instructions">Running Instructions</a> •
  <a href="#repo-structure">Repo Structure</a>
</p>

## Project Summary

Our proposed final project is to recommend new songs for people based on a user inputted song and relationship category.

## Running Instructions

### Code

Code files can be found in the `src/` directory and the main method can be found within the `maim/` directory. To run the code:

To build and run the code (make sure you are in and running the Docker container):
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make`
5. `./main [dataset]` which is "../data/genres_v2.csv" in our case
6. Enter song title you wish to find a song recommendation for
7. After given a recommendation, you have the opportunity to input another song or quit the program

### Test Cases
Test files can be found in the `tests/` directory and the main method can be found within the `maim/` directory. To run the code:

To build and make the tests (make sure you are in and running the Docker container):
1. `mkdir build`
2. `cd build`
3. `cmake ..`
4. `make test`
5. `./test`
6. Enter song title you wish to find a song recommendation for
7. After given a recommendation, you have the opportunity to input another song or quit the program


## Github Organization 

### Data

Our test data was taken using Spotify API and translated into a CSV file, stored as a .csv file in the `data/` directory.
https://www.kaggle.com/datasets/mrmorj/dataset-of-songs-in-spotify

### Tests

Test files can be found under the `tests/` directory.

### Documents

Our signed contract, development log, project report, etc. can be found in the `documents/` directory.

### Feedback

All feedback from our project mentor can be found in the `feedback/` directory.

### Code
All code written for our project can be found in the `src/` directory.

### Presentation Deliverables
- Results Markdown File: https://github.com/chenjhr88/cs225_final_proj/blob/documents/results.md
- Presentation Video: https://mediaspace.illinois.edu/media/t/1_y47e7qhw


