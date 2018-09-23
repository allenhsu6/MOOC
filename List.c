//
// Created by allenhsu on 2018/9/22.
//

#include "List.h"


/* 你的代码将被嵌在这里 */
List Read(){
    int n;
    scanf("%d",&n);
    List L=(struct Node *)malloc(sizeof(struct Node));
    L->Next=NULL;  // 这个必须设置为null 否则系统会分配一个地址，也就是传说中的野指针
    List ans=L;
    while (n--){
        if (L->Next==NULL){
            List temp=(struct Node *)malloc(sizeof(struct Node));
            temp->Next=NULL;
            scanf("%d",&temp->Data);
            L->Next=temp;
            L=L->Next;
        }
    }
    return ans;  // 这里返回的ans是有空头结点的
}
void Print( List L ){
    if (L->Next==NULL){
        printf("NULL\n");
        return;
    }
    List temp=L->Next;
    while (temp){
        printf("%d ",temp->Data);
        temp=temp->Next;
    }
    printf("\n");
}
List Merge( List L1, List L2 ){
    List L3=(struct Node *)malloc(sizeof(struct Node));
    List L=L3;  // 一个临时变量 也是带空头的
    List p=L1->Next; // p是L1的临时变量
    List q=L2->Next; // q是L2的临时变量
    while (p && q){
        if (p->Data < q->Data){
            L->Next=p;
            p=p->Next;
        }
        else{
            L->Next=q;
            q=q->Next;
        }
        L=L->Next;
    }
    L->Next=NULL;
    if (p) L->Next=p;
    if (q) L->Next=q;
    L1->Next=NULL;  // 合并之后还要断掉原来的链条
    L2->Next=NULL;
    return L3;
}