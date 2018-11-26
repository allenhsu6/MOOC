//
// Created by allenhsu on 2018/11/8.
// 可以i/2的根本原因是二叉堆是一个完全二叉树
// 完全二叉树用数组存储，非常方便，我们删除的时候就删除根节点，然后把最尾巴的放在根节点
//
#include <iostream>

void create();

void insert();

using namespace std;
int MinHeap[1001], size;  //如果可以使用vector更好

int main(){
    int N = 0, M = 0, X = 0;
    cin >> N >> M;
    create();
    for (int i = 0; i < N; ++i) {
        insert();
    }
    for (int j = 0; j < M; ++j) {
        cin >> X;
        for (int i = X; i > 1 ; i = i/2) {
            cout << MinHeap[i] << " ";
        }
        cout << MinHeap[1] << endl;
    }
    return 0;
}

void insert() {
    int X = 0;
    size++;
    cin >> X;
    MinHeap[size] = X;
    for (int i = size; MinHeap[i/2] > MinHeap[i]; i = i/2) {
        MinHeap[i] = MinHeap[i/2];
        MinHeap[i/2] = X;
    }
}

// 创建堆
void create() {
    MinHeap[0] = -10001;
    size = 0;   // 返回当前堆的大小
}