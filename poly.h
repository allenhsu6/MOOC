//
// Created by allenhsu on 2018/9/13.
//

#ifndef LEARNC_TEST_H
#define LEARNC_TEST_H


#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynomial; // 多项式本身就是一个指针
struct PolyNode{
    int coef;  // 系数
    int expon; // 指数
    Polynomial link;  // 指向下一个位置
};


Polynomial ReadPoly();

Polynomial Mult(Polynomial pNode, Polynomial pPolyNode);

void PrintPoly(Polynomial pNode);

Polynomial Add(Polynomial pNode, Polynomial pPolyNode);

void Attach(int c, int e, Polynomial *pRear);



#endif //LEARNC_TEST_H


