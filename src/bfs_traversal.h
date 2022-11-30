#pragma once
#include "adjacencylist.h"
#include <queue>


int BFSTraversal(Graph g);

void helperBFS(Graph g, Vertex v, int& num_nodes);