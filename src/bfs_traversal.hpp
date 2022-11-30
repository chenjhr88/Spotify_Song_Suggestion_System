#include "bfs_traversal.h"

//Input: Graph g
//Output: labeling of the edges on G as Discovery and cross edges
int BFSTraversal(Graph g) {

    /* for each (Vertex v: g.vertices()):
            setLabel(v, UNEXPLORED)
        for each (Edge e: G.edges()):
            setLabel(e, UNEXPLORED)
        for each (Vertex v: G.vertices()): {
            if (getLabel(v) == UNEXPLORED)
                BFS(g, v)
        }
    */
    int num_nodes = 0;
    //set all vertices and edges to UNEXPLORED
    for (Vertex v: g.getVertices()) {
            g.setLabel(v, "UNEXPLORED");
            for (size_t i = 0; i < v.edges.size(); ++i) {
                g.setLabel(v.edges[i], "UNEXPLORED");
            }
    }
    for (Vertex v : g.getVertices()) {
            if (g.getLabel(v) == "UNEXPLORED") {
                helperBFS(g, v, num_nodes);
            }
    }

    return num_nodes;
   
}

void helperBFS(Graph g, Vertex v, int& num_nodes) {
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
   std::queue<Vertex> q;
   g.setLabel(v, "VISITED");
    num_nodes++;
   q.push(v);

   while (!q.empty()) {
        Vertex v_temp = q.front();
        
        q.pop();

        for (Vertex w : g.getAdjacents(v)) {

            if (g.getLabel(w) == "UNEXPLORED") {
                
                //find where edges in w and v where v has w and w has v
                //set the labels of those edges equal to "DISCOVERY"
                g.setLabel(v, w, "DISCOVERY");
                g.setLabel(w, "VISITED");
                num_nodes++;
                q.push(w);
            }   else if (g.getLabel(v, w) == "UNEXPLORED") {
                g.setLabel(v, w, "CROSS");
            }
            
        }
   }
}