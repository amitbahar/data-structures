//
// Created by Amit on 6/13/2026.
//

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint32_t u;
    uint32_t v;
    void* edge_data;
} graph_edge_t;

typedef struct {
    void* internal_state;
} graph_undirected_t;

bool get_graph_undirected(graph_undirected_t* graph, graph_edge_t* edges, size_t num_edges, size_t num_vertices);
void destroy_graph_undirected(graph_undirected_t* graph);

#endif //DATA_STRUCTURES_GRAPH_H