//
// Created by Amit on 6/13/2026.
//

#include "graph.h"
#include <stdlib.h>


bool get_graph_undirected(graph_undirected_t* graph,
                                         graph_edge_t* edges,
                                         size_t num_edges,
                                         size_t num_vertices) {
    if (graph == NULL || edges == NULL || num_vertices == 0) {
        return false;
    }
    size_t num_bits = num_vertices*num_vertices;
    size_t num_bytes = (num_bits + 7) >> 3;
    uint8_t* internal_state = (uint8_t*)calloc(num_bytes, sizeof(uint8_t));
    if (internal_state == NULL) {
        return false;
    }
    for (size_t i = 0; i < num_edges; i++) {
        uint32_t u = edges[i].u;
        uint32_t v = edges[i].v;
        if (num_bits <= u || num_bits <= v) {
            free(internal_state);
            return false;
        }
        size_t bit_index_uv = u * num_vertices + v;
        internal_state[bit_index_uv >> 3] |= (1 << (bit_index_uv & 7));
        if (u != v) {
            size_t bit_index_vu = v * num_vertices + u;
            internal_state[bit_index_vu >> 3] |= (1 << (bit_index_vu & 7));
        }
    }
    graph->internal_state = internal_state;
    return true;
}

void destroy_graph_undirected(graph_undirected_t* graph) {
    if (graph == NULL || graph->internal_state == NULL) {return;}
    free(graph->internal_state);
}
