//
// Created by allenhsu on 2018/11/24.
// 邻接矩生成的图
//
#include <iostream>
using namespace std;
#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex; // 顶点
typedef int WeightType;

typedef struct ENode *PtrtoENode;
struct ENode{
    Vertex U, V;
    WeightType Weight;
};
typedef PtrtoENode Edge;

typedef struct GNode *PtrtoGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    // 有时候这里还会出现顶点数据
};
typedef PtrtoGNode MGraph;

MGraph CreateGraph(int VertexNum){
    MGraph mGraph = new(GNode);
    mGraph->Nv = VertexNum;
    mGraph->Ne = 0;
    for (int i = 0; i < VertexNum; ++i) {
        for (int j = 0; j < VertexNum; ++j) {
            mGraph->G[i][j] = INFINITY;
        }
    }
    return mGraph;
}

// 真正目的是改变G中0、1
void InsertEdge( MGraph graph,Edge edge){
    graph->G[edge->U][edge->V] = 1;
    // 无向图的话是双向的
    graph->G[edge->V][edge->U] = 1;
}

void BuildGraph(){
    int N, D;
    int a, b;
    cin >> N >> D;
    MGraph mGraph = CreateGraph(N);
    mGraph->Ne = D;
    if (D > 0){
        Edge edge = new(ENode);
        for (int i = 0; i < D; ++i) {
            cin >> a >> b;
            edge->U = a;
            edge->V = b;
            InsertEdge(mGraph, edge);
        }
    }
}
