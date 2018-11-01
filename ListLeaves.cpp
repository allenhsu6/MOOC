//
// Created by allenhsu on 2018/10/30.
// 本质上是二叉树的层序遍历方法，之前讲过的是用队列实现
//
#include <iostream>
#include <queue>
using namespace std;

#define Null -1
#define MaxElement 10
typedef int Tree;
typedef int Element;
struct TreeNode {
    Element value;
    Tree Left;
    Tree Right;
};

struct TreeNode T1[MaxElement];
int N = 0;

// 构建树并返回根节点
Tree BuildTree(struct TreeNode T[]) {
    cin >> N;
    char left, right;
    int check[MaxElement], root = Null;
    

    for (int j = 0; j < N; ++j) {
        check[j] = 0;
    }

    for (int i = 0; i < N; ++i) {
        T[i].value = i;
        cin >> left >> right;
        if (left != '-') {
            T[i].Left = left - '0';
            check[T[i].Left] = 1;
        } else
            T[i].Left = Null;
        if (right != '-') {
            T[i].Right = right - '0';
            check[T[i].Right] = 1;
        } else
            T[i].Right = Null;
    }

    for (int k = 0; k < N; ++k) {
        if (check[k] == 0) {
            root = k;
        }
    }
    return root;
}

void findLeaves(Tree tree){
    if (tree == Null) return;
    queue<int> q;
    q.push(tree);
    int temp, flag = 1;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        if (T1[temp].Left == Null && T1[temp].Right == Null){
            if (flag){
                cout << temp;
                flag = 0;
            } else{
                cout << " "<< temp;
            }
        }
        if (T1[temp].Left != Null)
            q.push(T1[temp].Left);
        if (T1[temp].Right != Null)
            q.push(T1[temp].Right); 
    }
}

int main() {
    Tree tree;
    tree = BuildTree(T1);
    findLeaves(tree);
    return 0;
}