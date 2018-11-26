//
// Created by allenhsu on 2018/11/6.
//

#include <iostream>

using namespace std;

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


int getHeight(BinTree &root){
    if (root){
        return max(getHeight(root->Left),getHeight(root->Right)) + 1;
    }else
        return 0;
}

BinTree LL(BinTree &root){
    BinTree tree = root->Left;      // B
    root->Left = tree->Right;
    tree->Right = root;
    return tree;
}

BinTree LR(BinTree &root){
    BinTree tree1 = root->Left;  //B
    BinTree tree2 = tree1->Right; // C
    tree1->Right = tree2->Left;
    root->Left = tree2->Right;
    tree2->Right = root;
    tree2->Left = tree1;
    return tree2;
}

BinTree RL(BinTree &root){
    BinTree tree1 = root->Right;
    BinTree tree2 = tree1->Left;
    root->Right = tree2->Left;
    tree1->Left = tree2->Right;
    tree2->Right = tree1;
    tree2->Left = root;
    return tree2;
}

BinTree RR(BinTree &root){
    BinTree tree = root->Right;
    root->Right = tree->Left;
    tree->Left = root;
    return tree;
}


BinTree insertAVL(BinTree &root, ElementType X){
    if (!root){
        BinTree tree = new TNode;
        tree->Data = X;
        tree->Right = tree->Left = NULL;
        root = tree;
        return root;
    }
    if (X < root->Data){
        root->Left = insertAVL(root->Left, X);  // 插入左边
        if (getHeight(root->Left) - getHeight(root->Right) >= 2){
            if (X < root->Left->Data){
                root = LL(root);
            }else{
                root = LR(root);
            }
        }
    }else{
        root->Right = insertAVL(root->Right, X);
        if (getHeight(root->Left) - getHeight(root->Right) <= -2){
            if (X < root->Right->Data){
                root = RL(root);
            }else{
                root = RR(root);
            }
        }
    }
    return root;
}

int main(){
    int N = 0, i = 0, X;
    BinTree tree = NULL;
    cin >> N;
    if (0 < N < 21){
        for (; i < N; ++i) {
            cin >> X;
            insertAVL(tree, X);     // 传入的引用
        }
        cout << tree->Data;
    }
    return 0;
}