//
// Created by allenhsu on 2018/11/26.
//
#include <iostream>
using namespace std;

typedef struct ThisNode *PThisNode;
struct ThisNode{
    int value;
    PThisNode next;
};

int visit[15] = {0};

// 你记住，我们的图已经建立起来，没必要再做修改
void DFS(int v){
    visit[v] = 1;   // 这就是来过这个点了

}

int main(){
    int M, N;  // M个点， N条边
    int a, b;
    cin >> M >> N;

    PThisNode graph[M];

    if (M > 0){
        for (int j = 0; j < M; ++j) {
            PThisNode node = new(ThisNode);
            node->next = nullptr;
            node->value = j;
            graph[j] = node;
        }
    }

    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        PThisNode node1 = new(ThisNode);
        node1->value = b;
        node1->next = graph[a]->next;
        graph[a]->next = node1;

        PThisNode node2 = new(ThisNode);
        node2->value = a;
        node2->next = graph[b]->next;
        graph[b]->next = node2;
    }

    return 0;
}