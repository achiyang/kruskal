#ifndef DSU_H
#define DSU_H

typedef struct DSU {
    int *parent;
    int *rank;
    int size;
} DSU;

void dsu_init(DSU *dsu, int size);

int dsu_find(DSU *dsu, int x);
void dsu_union(DSU *dsu, int a, int b);

#endif