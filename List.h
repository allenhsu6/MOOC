//
// Created by allenhsu on 2018/9/20.
//

#ifndef LEARNC_LIST_H
#define LEARNC_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;  // 这里将ptrtonode定义成为一个指针结构体类型
// 为了更具有抽象的感觉，这里在定义的节点内部类型都是提前定义好
struct Node {
    ElementType Data;  // 内部元素信息
    PtrToNode   Next;  // 指向下一个
};
typedef PtrToNode List; // List 一个结构体指针类型


typedef int Number;

//
//typedef int ElementType;
//typedef struct Node *PtrToNode;
//
//struct Node{
//    ElementType Data;
//    PtrToNode Next;
//};
//


#endif //LEARNC_LIST_H
