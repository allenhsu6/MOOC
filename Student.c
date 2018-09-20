//
// Created by allenhsu on 2018/9/17.
//

#include "Student.h"
#include <stdlib.h>
#include <stdio.h>

struct Student* Create(){
    iCount = 0;
    struct Student *pHead = NULL;
    struct Student *pEnd, *pNew;
    pEnd = pNew = (struct Student*)malloc(sizeof(struct Student));
    // 给新的节点赋值
    scanf("%s",&pNew->cName);
    scanf("%d",&pNew->iNumber);

    // 确保了对应的赋值
    while (pNew->iNumber != 0){
        iCount++;
        // 这个是第一个新节点
        if (iCount == 1){
            pNew->pNext = pHead; //把next置空
            // 头和尾巴都是New节点
            pEnd = pNew;
            pHead = pNew;
        }else{
            pNew->pNext = NULL;
            pEnd->pNext = pNew;
            pEnd = pEnd->pNext;
        }
        // 再一次初始化
        pNew = (struct Student*)malloc(sizeof(struct Student));
        scanf("%s",&pNew->cName);
        scanf("%d",&pNew->iNumber);
    }
    free(pNew);
    return pHead;

}
void Print(struct Student* pHead){
    struct Student *pTemp;
    pTemp = pHead;
    while (pHead != NULL){
        printf("%s\n", pTemp->cName);
        printf("%d\n", pTemp->iNumber);
        printf("\n");
        pTemp = pTemp->pNext;
    }
}


