#ifndef EDGE_SET_H
#define EDGE_SET_H

typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_set {
    edge *edges;
    int size;
    int capacity;
} edge_set;

void edge_set_init(edge_set *E);
void edge_set_sort(edge_set *E);
void edge_set_add(edge_set *E, edge e);

#endif