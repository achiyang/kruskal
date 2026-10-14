#include "edge_set.h"

#include <stdlib.h>

static int comp_edge(const void *a, const void *b) {
    const edge *ea = (const edge *)a;
    const edge *eb = (const edge *)b;

    return (ea->w > eb->w) - (ea->w < eb->w);
}

void edge_set_init(edge_set *E) {
    E->edges = NULL;
    E->size = 0;
    E->capacity = 0;
}

void edge_set_sort(edge_set *E) {
    qsort(E->edges, E->size, sizeof(*E->edges), comp_edge);
}

void edge_set_add(edge_set *E, edge e) {
    if (E->size == E->capacity) {
        E->capacity = E->capacity == 0
            ? 4
            : E->capacity * 2;

        E->edges = realloc(
            E->edges,
            E->capacity * sizeof(*E->edges)
        );
    }

    E->edges[E->size++] = e;
}