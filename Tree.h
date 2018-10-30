//
// Created by allenhsu on 2018/9/19.
//

#ifndef LEARNC_TREE_H
#define LEARNC_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// 定义类型
typedef struct Tnode *Position;
typedef Position BinTree;
typedef int ElementType;


struct Tnode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


bool isEmpty(BinTree BT);   // 判断是否为空
void Traversal(BinTree BT); // 遍历二叉树，顺序访问节点
BinTree CreateBinTree();    // 创建二叉树

#endif //LEARNC_TREE_H


