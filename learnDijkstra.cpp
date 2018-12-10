// 如果仅在该函数中应用的参数，我们需要将之封装
// Created by allenhsu on 2018/12/6.
//

#include "MGraph.cpp"

Vertex FindMinDist(MGraph M, int dist[], int collection[]);

int Dijkstra(MGraph M, int dist[], int path[], Vertex S){
    int Collection[MaxVertexNum];
    Vertex V, W;
    for (V = 0; V < M->Nv; V++) {
        dist[V] = M->G[S][V];
        if (dist[V] < INFINITY){
            path[V] = S;
        } else{
            path[V] = -1;
        }
        Collection[V] = 0;
    }
    Collection[S] = 1;
    while (1){
        V = FindMinDist(M, dist, Collection);
        if (V == 0) break;
        Collection[V] = 1; // 收录最小距离点

        for (W = 0; W < M->Nv; ++W) {
            if (Collection[W] == 0 && M->G[V][W] < INFINITY){
                if (M->G[V][W] < 0) return 0;
                if (dist[V] + M->G[V][W] < dist[W]){
                    dist[W] = dist[V] + M->G[V][W];
                    path[W] = V;
                }
            }

        }
    }
    return 1;
}
// 返回未被收录顶点中的距离最小的点
Vertex FindMinDist(MGraph M, int dist[], int collection[]) {
    Vertex MinV = 0;
    int MinDist = INFINITY;
    for (int i = 0; i < M->Nv; ++i) {
        if (collection[i] == 0 && dist[i] < MinDist){
            MinV = i;
            MinDist = dist[i];
        }
    }
    if (MinDist < INFINITY)
        return MinV;
    else return 0;
}