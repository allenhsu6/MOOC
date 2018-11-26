//
// Created by allenhsu on 2018/11/6.
// 二叉搜索树的操作集

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;   // 指针
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

/**
 *  函数Insert将X插入二叉搜索树BST并返回结果树的根结点指针；
    函数Delete将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针；
    函数Find在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针；
    函数FindMin返回二叉搜索树BST中最小元结点的指针；
    函数FindMax返回二叉搜索树BST中最大元结点的指针。
 */

Position Find( BinTree BST, ElementType X ){
    if (BST == NULL) return NULL;
    if (BST->Data == X) return BST;
    if (X > BST->Data) return Find(BST->Right, X);
    if (X < BST->Data) return Find(BST->Left, X);
}
Position FindMin( BinTree BST ){
    if(BST){
        while (BST->Left){
            BST = BST->Left;
        }
    }
    return BST;
}
Position FindMax( BinTree BST ){
    if(BST){
        while (BST->Right){
            BST = BST->Right;
        }
    }
    return BST;
}
BinTree Insert( BinTree BST, ElementType X ){
    if (BST == NULL){
       BST = (BinTree)malloc(sizeof(struct TNode)); // 问题在这里，分配的时候，一定注意sizeof的是结构体，不是指针
       BST->Left = NULL;
       BST->Right =NULL;
       BST->Data = X;
        return BST;
    }
    if(X > BST->Data){
        BST->Right = Insert(BST->Right, X);
    }
    if (X < BST->Data){
        BST->Left = Insert(BST->Left, X);
    }
    return BST;


}
BinTree Delete( BinTree BST, ElementType X ){
    Position Tmp;  // 需要一个temp做记录，记录上个节点
    if (!BST) printf("Not Found\n");
    else{
        // 第一种情况
        if (X < BST->Data){
            BST->Left = Delete(BST->Left, X);
        }
        else if (X > BST->Data){
            BST->Right = Delete(BST->Right, X);
        }
        else{
            if (BST->Right && BST->Left){
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }else{
                Tmp = BST;
                if (!BST->Left){    // 右孩子或者为空
                    BST = BST->Right;
                }
                else if (!BST->Right){
                    BST = BST->Left;
                }
                free(Tmp);
            }
        }
    }
    return BST;

}




int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

void PreorderTraversal( BinTree BT ){
    if (BT){
        printf("%d ",BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}
void InorderTraversal( BinTree BT ){
    if (BT){
        InorderTraversal( BT->Left );
        printf("%d ",BT->Data);
        InorderTraversal( BT->Right );
    }
}
