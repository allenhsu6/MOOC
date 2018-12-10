//
// Created by allenhsu on 2018/11/27.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MaxVertexNum 10000

typedef struct LNode *PNode;
struct LNode{
    int value;
    PNode next;
};

int N, E; // 点数和边数
vector<PNode > v;
int visited[MaxVertexNum] = {0};

void CreateGraph();

void InitVisited();

int BFS(int i);

int main(){
    cin >> N >> E;
    int count = 0;
    CreateGraph();
    for (int i = 0; i < N; ++i) {
        InitVisited();
        count = BFS(i);
        printf("%d: %.2f%%\n",i,count*100.0/N);
    }
    return 0;
}

int BFS(int i) {
    int count = 0;
    int level = 0;
    PNode last = v[i];
    queue<PNode> q;
    q.push(v[i]);
    PNode temp, tail;
    visited[i] = 1;
    count ++;

    while (!q.empty()){
        temp = q.front();
        q.pop();

        for (PNode node = v[temp->value]->next;  node ; node = node->next) {
            if (visited[node->value] == 0){
                visited[node->value] = 1;
                count ++;
                q.push(v[node->value]);
            }
            tail = q.back();
        }

        if (temp == last){
            level ++;
            last = tail;
        }
        if (level == 6) break;
    }
    return count;
}

void InitVisited() {
    for (int i = 0; i < N; ++i) {
        visited[i] = 0;
    }
}

void CreateGraph() {
    int v1,v2;
    for (int i = 0; i < N; ++i) {
        PNode node = new(LNode);
        node->value = i;
        node->next = nullptr;
        v.push_back(node);
    }
    for (int j = 0; j < E; ++j) {
        cin >> v1 >> v2;
        PNode node = new(LNode);
        node->value = v2;
        node->next = v[v1]->next;
        v[v1]->next = node;

        PNode node1 = new(LNode);
        node1->value = v1;
        node1->next = v[v2]->next;
        v[v2]->next = node1;
    }
}