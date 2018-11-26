// 邻接表生成的图

#include <iostream>
using namespace std;

#define MaxVertexNum 100
typedef int Vertex; // 顶点数值
typedef int WeightType;

// 边
typedef struct ENode *PtrENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrENode Edge;

// 邻节点
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;        // 节点值
    PtrToAdjVNode Next; // 指向下一个的节点
};

// 头节点类型
typedef struct VNode{
    int Value; // 头结点的value
    PtrToAdjVNode First; // 第一个邻节点
}AdjList[MaxVertexNum];

// 图
typedef struct GNode *PtrtoLGraph;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrtoLGraph LGraph;

LGraph CreateGraph(int N){
    LGraph graph = new(GNode);
    graph->Nv = N;
    graph->Ne = 0;
    for (int i = 0; i < N; ++i) {
        graph->G[i].First = nullptr;
    }
    return graph;
}

void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode;
    NewNode = new(AdjVNode);

    /* 插入边 <V1, V2> */
    /* 为V2建立新的邻接点 */
    NewNode->AdjV = E->V2;
    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->G[E->V1].First;
    Graph->G[E->V1].First = NewNode;

    /* 若是无向图，还要插入边 <V2, V1> */
    /* 为V1建立新的邻接点 */
    NewNode = new(AdjVNode);
    NewNode->AdjV = E->V1;
    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].First;
    Graph->G[E->V2].First = NewNode;
}
// 从输入中建立图
void BuildGraph(){
    int N, D;
    int a, b;
    cin >> N >> D;
    LGraph LGraph = CreateGraph(N);

    if (D > 0){
        Edge edge = new(ENode);
        for (int i = 0; i < D; ++i) {
            cin >> a >> b;
            edge->V1 = a;
            edge->V2 = b;
            InsertEdge(LGraph, edge);
        }
    }
}

// 深度优先的便利方法DFS

void visit(Vertex V){
    cout << "正在访问节点：" << V << endl;
}

void DFS(LGraph graph, Vertex V, void visit(Vertex V)){
    int isvisit[graph->Nv];
    visit(V);
    isvisit[V] = 1;

    for (PtrToAdjVNode W = graph->G[V].First; W ; W = W->Next) {
        if (isvisit[W->AdjV] != 1){
            DFS(graph, W->AdjV, visit);
        }
    }

}