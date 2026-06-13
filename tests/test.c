#include <stdio.h>
#include <stdlib.h>
#include "../src/graph/graph.h"

int main() { //simple test of structures
	graph_undirected_t graph;
	graph_edge_t edges[3] = {
		{0,1,NULL}, {1,2,NULL}, {2,0,NULL}
	};
	get_graph_undirected(&graph, edges, 3, 3);
	destroy_graph_undirected(&graph);
	return 0;
}


