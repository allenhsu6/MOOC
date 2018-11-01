//
// Created by allenhsu on 2018/11/1.
// 相同的class名字是会互相引用的
// 从大到小的细分，main函数怎么写，小函数就怎么写
#include <iostream>


using namespace std;

typedef struct BinTree *Tree;
struct BinTree{
    int v;
    int flag;   // 判断是否访问
    Tree Left, Right;
};

/**
 * 根据输入序列构造树
 * @param N 序列长度 N>0
 * @return 根据序列构造的树
 */

Tree newNode(int v){
    // Tree tree;
    Tree tree = (Tree)malloc(sizeof(struct BinTree));
    tree->v = v;
    tree->Right = NULL;
    tree->Left = NULL;
    tree->flag = 0; // 这里还不清楚flag的用意
    return tree;
}


// 思考其中的重复模式，第一步是跳出递归的关键节点为null的时候，将V放进去即可
Tree insert(Tree tree, int V){
    if (!tree) tree = newNode(V);
    else{
        if (V > tree->v){
            tree->Right = insert(tree->Right, V);
        }else{
            tree->Left = insert(tree->Left, V);
        }
    }
    return tree;
}

Tree makeTree(int N){
    Tree T;
    int i, V;
    cin >> V;
    T = newNode(V); // 有了根
    for (i = 1; i < N; ++i) {
        cin >> V;
        T = insert(T,V);
    }
    return T;
}

// 判别单个序列值是否按顺序出现
// 传入的tree应该是root
int check(Tree tree, int V){
    if (tree->flag) {
        if (V < tree->v) return check(tree->Left, V);
        else if (V > tree->v) return check(tree->Right, V);
        else return 0;
    }
    else{
        if (V == tree->v){
            tree->flag = 1;
            return 1;
        }else return 0;
    }
}

// 判断序列是否为同一棵树
int Judge(Tree T, int N){
    int V, i, flag = 0; // flag 判断该序列是否读取完毕
    cin >> V;
    if (T->v != V){
        flag = 1;
    }else T->flag = 1;

    for (i = 1; i < N; ++i) {
        cin >> V;
        if ((!flag) && (!check(T, V))){
            flag = 1;
        }
    }
    if (flag) return 0;
    else return 1;
}
// 清除各个flag节点
void ResetT(Tree T){
    if(T->Left) ResetT(T->Left);
    if (T->Right) ResetT(T->Right);
    T->flag = 0;
}
// 释放空间，从下到上
void FreeTree(Tree T){
    if (T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    free(T);
}

int main(){
    int N,L,i;
    Tree T;
    cin >> N;
    while(N){
        cin >> L;
        T = makeTree(N);
        for (i = 0; i < L; i++) {
            if (Judge(T, N)) cout<< "Yes" << endl;
            else cout << "No" << endl;
            ResetT(T);
        }
        FreeTree(T);
        cin >> N;
    }
    return 0;
};