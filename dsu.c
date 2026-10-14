#include "dsu.h"

#include <stdlib.h>

void dsu_init(DSU *dsu, int size) {
    dsu->parent = malloc(size * sizeof(*dsu->parent));
    dsu->rank = calloc(size, sizeof(*dsu->rank));

    dsu->size = size;

    for (int i = 0; i < size; i++) {
        dsu->parent[i] = i;
    }
}

int dsu_find(DSU *dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = dsu_find(dsu, dsu->parent[x]);
    }

    return dsu->parent[x];
}

void dsu_union(DSU *dsu, int a, int b) {
    a = dsu_find(dsu, a);
    b = dsu_find(dsu, b);

    if (a == b) return;

    // 가중치(rank) 기반 union
    if (dsu->rank[a] < dsu->rank[b]) {
        dsu->parent[a] = b;
    }
    else if (dsu->rank[a] > dsu->rank[b]) {
        dsu->parent[b] = a;
    }
    else {
        dsu->parent[b] = a;
        dsu->rank[a]++;
    }
}