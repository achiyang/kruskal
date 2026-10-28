#include <stdio.h>
#include <stdlib.h>

#include "edge_set.h"
#include "dsu.h"

const int input_graph[9][9] = {
    {  0,  4,  0,  0,  0,  0,  0,  8,  0 },
    {  4,  0,  8,  0,  0,  0,  0, 11,  0 },
    {  0,  8,  0,  7,  0,  4,  0,  0,  2 },
    {  0,  0,  7,  0,  9, 14,  0,  0,  0 },
    {  0,  0,  0,  9,  0, 10,  0,  0,  0 },
    {  0,  0,  4, 14, 10,  0,  2,  0,  0 },
    {  0,  0,  0,  0,  0,  2,  0,  1,  6 },
    {  8, 11,  0,  0,  0,  0,  1,  0,  7 },
    {  0,  0,  2,  0,  0,  0,  6,  7,  0 }
};

/*
edge_set kruskal_MST(edge_set E, int n) {
    sort(E);

    edge_set MST_E = {};

    for (i = 0; i < n; i++) init_set(i); // n개의 집합(트리)을 생성

    while (MST_E의 간선 수 < n-1) {
        (u, v) = E의 최소 가중치 간선;
        E = E - {(u, v)};

        if (find(u) ≠ find(v)) // u와 v가 다른 집합(트리) 원소
        {
            MST_E = MST_E ∪ {(u, v)};
            union(u, v);        // 두 집합(트리)을 합병
        }
    }

    return MST_E;
}
*/
edge_set kruskal_MST(edge_set E, int n) {
    edge_set_sort(&E);

    edge_set MST_E;
    edge_set_init(&MST_E);

    DSU dsu;
    dsu_init(&dsu, n);

    for (int i = 0; (i < E.size) && (MST_E.size < n - 1); i++) {
        edge e = E.edges[i];

        if (dsu_find(&dsu, e.u) != dsu_find(&dsu, e.v)) {
            edge_set_add(&MST_E, e);
            dsu_union(&dsu, e.u, e.v);
        }
    }

    return MST_E;
}

int main() {
    edge_set E;
    edge_set_init(&E);
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            int weight = input_graph[i][j];
            if (weight) {
                edge e = { .u = i, .v = j, .w = weight };
                edge_set_add(&E, e);
            }
        }
    }

    edge_set MST_E = kruskal_MST(E, 9);
}