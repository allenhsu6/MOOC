//
// Created by allenhsu on 2018/12/6.
//
/* 图的邻接矩阵表示法 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
#define ERROR -10
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;      /* 有向边<V1, V2> */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /* 顶点数 */
    int Ne;  /* 边数   */
    WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
    DataType Data[MaxVertexNum];      /* 存顶点的数据 */
    /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */


MGraph CreateGraph( int VertexNum )
{ /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = new(GNode); /* 建立图 */
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /* 初始化邻接矩阵 不存在的边用infinity表示*/
    /* 注意：这里默认顶点编号从0开始，到(Graph->Nv - 1) */
    for (V=0; V<Graph->Nv; V++)
        for (W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}

void InsertEdge( MGraph Graph, Edge E )
{
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv, i;

    cin >> Nv;   /* 读入顶点个数 */
    Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

    cin >> Graph->Ne;
    if ( Graph->Ne != 0 ) { /* 如果有边 */
        E = new(ENode); /* 建立边结点 */
        /* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
        for (i=0; i<Graph->Ne; i++) {
            cin >> E->V1 >> E->V2 >> E->Weight;
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge( Graph, E );
        }
    }
    return Graph;
}

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
    dist[S] = 0;
    Collection[S] = 1;
    while (1){
        V = FindMinDist(M, dist, Collection);
        if (V == 0) break;
        Collection[V] = 1; // 收录最小距离点

        for (W = 0; W < M->Nv; ++W) {
            if (Collection[W] == 0 && M->G[V][W] < INFINITY){
                if (M->G[V][W] < 0) return 0;  // 不处理负环
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

int main(){
    MGraph M = BuildGraph();
    int dist[MaxVertexNum];
    int path[MaxVertexNum];
    int x = Dijkstra(M, dist, path, 0);
    if (x){
        for (int i = 0; i < M->Nv; ++i) {
            cout << dist[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < M->Nv; ++i) {
            cout << path[i] << " ";
        }
    } else{
        cout << "输入错误" << endl;
    }
    return 0;
}