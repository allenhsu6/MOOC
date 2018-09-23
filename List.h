//
// Created by allenhsu on 2018/9/22.
//

#ifndef LEARNC_LIST_H
#define LEARNC_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );


#endif //LEARNC_LIST_H
