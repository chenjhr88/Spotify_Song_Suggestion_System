#include "bfs_traversal.h"
#include "adjacencylist.h"


/** 
 * Goes through the entire graph through BFS traversal, 
 * returns the number of vertices traversed (should be the total number of vertices in the graph)
 */
/* for each (Vertex v: g.vertices()):
        setLabel(v, UNEXPLORED)
    for each (Edge e: G.edges()):
        setLabel(e, UNEXPLORED)
    for each (Vertex v: G.vertices()): {
        if (getLabel(v) == UNEXPLORED)
            BFS(g, v)
    }
*/
int Graph::BFSTraversal() {
    int num_nodes = 0;
    //set all vertices and edges to UNEXPLORED
    for (size_t i = 0; i < vertices.size(); ++i) {
            setLabel(vertices[i], "UNEXPLORED");
            for (size_t j = 0; j < vertices[i].edges.size(); ++j) {
                vertices[i].edges[j].label = "UNEXPLORED";
            }
    }

    //go through each vertex that has the label "UNEXPLORED"
    for (size_t i = 0 ; i < vertices.size(); ++i) {
            if (getLabel(vertices[i]) == "UNEXPLORED") {
                helperBFS(vertices[i], num_nodes);
            }
    }

    return num_nodes;
   
}


/** 
 *  helper function for BFS traversal
 *  helps BFS traversal function go through the selected vertex's adjacent vertices
 *  @param v selected Vertex
 *  @param num_nodes int that counts the number of nodes we traverse through
 */
/*
    queue q
    setLabel(v, VISITED)
    q.enqueue(v)

    while(!q.empty()) {
        v = q.dequeue()
        for each (Vertex w: g.adjacent(v)) {
            if (getLabel(w) == UNEXPLORED) {
                setLabel(v, w, DISCOVERY)
                setLabel(w, VISITED)
                q.enqueue(w)
            }   else if (getLabel(v, w) == UNEXPLORED) {
                setLabel(v, w, CROSS)
            }
        }
    }
*/
void Graph::helperBFS(Vertex v, int& num_nodes) {

    std::queue<Vertex> q;
    setLabel(v, "VISITED");
    num_nodes++;
    q.push(v);

    while (!q.empty()) {
        Vertex v_temp = q.front();
        q.pop();
        std::vector<Vertex> v1 = getAdjacents(v_temp);
        //go through all vertices adjacent to v_temp
        for (Vertex w : v1) {

            if (getLabel(w) == "UNEXPLORED") {
                //find where edges in w and v where v has w and w has v
                //set the labels of those edges equal to "DISCOVERY"
                setLabel(v_temp, w, "DISCOVERY");
                setLabel(w, "VISITED");
                num_nodes++;
                q.push(w);
            }   else if (getLabel(v_temp, w) == "UNEXPLORED") {

                setLabel(v_temp, w, "CROSS");
            }
            
        }
    }
}