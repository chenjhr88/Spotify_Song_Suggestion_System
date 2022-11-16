#include "bfs_traversal.h"

//Input: Graph g
//Output: labeling of the edges on G as Discovery and cross edges
void BFSTraversal(Graph g) {
    /* for each (Vertex v: g.vertices()):
            setLabel(v, UNEXPLORED)
        for each (Edge e: G.edges()):
            setLabel(e, UNEXPLORED)
        for each (Vertex v: G.vertices()): {
            if (getLabel(v) == UNEXPLORED)
                BFS(g, v)
        }

    */
}

void helperBFS(Graph g, Vertex v) {
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
}