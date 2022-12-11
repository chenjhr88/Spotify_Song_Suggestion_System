#include "remove_vertex.h"

/** 
 * deletes a specified vertex and any information related to that vertex based on the given vert_num
 * @param vert_num vertex number of the vertex that needs to be deleted
 */
void Graph::removeVertex(int vert_num) {
    //go through the adjacency list and each vertex's vector of edges
    //do the following:
    //going through each vertex's vector edges that's not v, if we we see the vertex num (aka if dest == v.vert_num) 
    // remove that edge
    //if the vertex is the vertex v, then we delete the edge in its edge vector and then erase the vertex itself

    //remove (vert_num, j)
    //remove all edges in the characteristic edge maps that involve the vert_num!
    for (size_t i = 0; i < vertices.size(); ++i) {
        removeEdgeDance(vert_num, i);
        removeEdgeDance(i, vert_num);

        removeEdgeAcc(vert_num, i);
        removeEdgeAcc(i, vert_num);

        removeEdgeEnergy(vert_num, i);
        removeEdgeEnergy(i, vert_num);
    }


    size_t i = 0;
    //used to update the adj matrix
    size_t l = 0;
    while (i < vertices.size()) {
        //std::cout << "now we at vertex " << vertices[i].vert_num << std::endl;
        /*std::cout << "edge size " << vertices[i].edges.size() << std::endl;
        for (size_t j = 0; j < vertices[i].edges.size(); ++j) {

            std::cout << "point to " << vertices[i].edges[j].dest << " at vertex " << vertices[i].vert_num << std::endl;
        }*/
        
        if (vert_num == vertices[i].vert_num) {
            size_t j = 0;
            size_t k = 0;
            while (j < vertices[i].edges.size()) {
                vertices[i].edges.erase(vertices[i].edges.begin() + j);
                adjacency_matrix[l][k] = 0;
                k++;
            }

            vertices.erase(vertices.begin() + i);
        }   else {
            size_t j = 0;
            while (j < vertices[i].edges.size()) {
                size_t k = 0;
                //std::cout << "edge " << vertices[i].edges[j].dest << std::endl;
                if (vertices[i].edges[j].dest == vert_num) {
                    //std::cout << "remove " << vertices[i].edges[j].dest << " at vertex " << vertices[i].vert_num << std::endl;
                    vertices[i].edges.erase(vertices[i].edges.begin() + j);
                    adjacency_matrix[l][k] = 0;
                }   else {
                    j++;
                }
                k++;
            }
            i++;
        }
        l++;
    }

    //the get functions for all_song, all_dance, all_acc, and all_energy should update the vectors accordingly
    //this function doesn't need to touch those variables
}

/** 
 * given two vertex numbers, finds if there is an edge in edges_to_hues_dance map. if there is, delete that edge
 * @param vert_num1 vertex number of the first vertex chosen
 * @param vert_num2 vertex number of the second vertex chosen
 */
void Graph::removeEdgeDance(int vert_num1, int vert_num2) {
    Vertex v1 = findVertex(vert_num1);
    Vertex v2 = findVertex(vert_num2);
    std::pair<std::string, std::string> edge_dance_key = std::make_pair(v1.song_name, v2.song_name);
    if (edges_to_hues_dance.find(edge_dance_key) == edges_to_hues_dance.end()) {
        std::cout << "This doesn't Exist!" << std::endl;
    }   else {
        //std::cout << "key: (" << edge_dance_key.first << ", " << edge_dance_key.second << "), value: " << std::endl;
        edges_to_hues_dance.erase(edge_dance_key);
    }
    
}

/** 
 * given two vertex numbers, finds if there is an edge in edges_to_hues_acc map. if there is, delete that edge
 * @param vert_num1 vertex number of the first vertex chosen
 * @param vert_num2 vertex number of the second vertex chosen
 */
void Graph::removeEdgeAcc(int vert_num1, int vert_num2) {
    Vertex v1 = findVertex(vert_num1);
    Vertex v2 = findVertex(vert_num2);
    std::pair<std::string, std::string> edge_acc_key = std::make_pair(v1.song_name, v2.song_name);
    if (edges_to_hues_acc.find(edge_acc_key) == edges_to_hues_acc.end()) {
        std::cout << "This doesn't Exist!" << std::endl;
    }   else {
        edges_to_hues_acc.erase(edge_acc_key);
    }
    
}


/** 
 * given two vertex numbers, finds if there is an edge in edges_to_hues_energy map. if there is, delete that edge
 * @param vert_num1 vertex number of the first vertex chosen
 * @param vert_num2 vertex number of the second vertex chosen
 */
void Graph::removeEdgeEnergy(int vert_num1, int vert_num2) {
    Vertex v1 = findVertex(vert_num1);
    Vertex v2 = findVertex(vert_num2);
    std::pair<std::string, std::string> edge_ener_key = std::make_pair(v1.song_name, v2.song_name);
    if (edges_to_hues_energy.find(edge_ener_key) == edges_to_hues_energy.end()) {
        std::cout << "This doesn't Exist!" << std::endl;
    }   else {
        edges_to_hues_energy.erase(edge_ener_key);
    }
    
}