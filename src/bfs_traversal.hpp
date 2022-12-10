#include "bfs_traversal.h"
#include "adjacencylist.h"

//Input: Graph g
//Output: labeling of the edges on G as Discovery and cross edges
int Graph::BFSTraversal() {
    // std::cout << "BFS START!" << std::endl;
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
    for (size_t i = 0; i < vertices.size(); ++i) {
            //gotta call the index to actually change the labels?
            setLabel(vertices[i], "UNEXPLORED");
            for (size_t j = 0; j < vertices[i].edges.size(); ++j) {
                vertices[i].edges[j].label = "UNEXPLORED";
                //setLabel(v.edges[i], "UNEXPLORED");
            }
    }

    /*for (Vertex v: vertices) {
            std::cout << "vert " << v.vert_num << ": " << v.label << std::endl;
            for (size_t i = 0; i < v.edges.size(); ++i) {
                std::cout << "edge " << v.edges[i].dest << ": " << v.edges[i].label << std::endl;
            }
    }*/


    for (size_t i = 0 ; i < vertices.size(); ++i) {
            if (getLabel(vertices[i]) == "UNEXPLORED") {
                //std::cout << "at vert " << vertices[i].vert_num << std::endl;
                helperBFS(vertices[i], num_nodes);
            }
    }

    return num_nodes;
   
}

void Graph::helperBFS(Vertex v, int& num_nodes) {
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
   setLabel(v, "VISITED");
    num_nodes++;
   q.push(v);

   while (!q.empty()) {
        Vertex v_temp = q.front();
        q.pop();
        std::vector<Vertex> v1 = getAdjacents(v_temp);
        /*for (size_t i = 0 ; i < v1.size(); ++i) {
            std::cout << "ASD " << v1[i].vert_num << std::endl;
        }*/
        for (Vertex w : v1) {
            //std::cout << "connects to " << w.vert_num << std::endl;
            if (getLabel(w) == "UNEXPLORED") {
                //std::cout << "oh yeah hurry to the unexplored land" << std::endl;
                //find where edges in w and v where v has w and w has v
                //set the labels of those edges equal to "DISCOVERY"
                setLabel(v_temp, w, "DISCOVERY");
                setLabel(w, "VISITED");
                num_nodes++;
                q.push(w);
            }   else if (getLabel(v_temp, w) == "UNEXPLORED") {
                //std::cout << "we see CROSS EDGE " << std::endl;
                setLabel(v_temp, w, "CROSS");
            }
            
            /*for (Vertex v: vertices) {
                std::cout << "vert " << v.vert_num << ": " << v.label << std::endl;
                for (size_t i = 0; i < v.edges.size(); ++i) {
                    std::cout << "edge " << v.edges[i].dest << ": " << v.edges[i].label << std::endl;
                }
            }*/
        }
   }
}