//
// Created by allenhsu on 2018/9/17.
//

#include "Student.h"


struct Student* Create(){
    iCount = 0;
    pHead = NULL; // 初始化
    struct Student *pEnd, *pNew;
    pEnd = pNew = (struct Student*)malloc(sizeof(struct Student));
    // 给新的节点赋值 直接输入到对应节点
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
            pHead = pNew;  // 头的目的是返回一个list指针，方便调用
        }else{
            pNew->pNext = NULL;
            pEnd->pNext = pNew; // end指针往后移动
            pEnd = pEnd->pNext;
        }
        // 再一次初始化
        pNew = (struct Student*)malloc(sizeof(struct Student));
        scanf("%s",&pNew->cName);
        scanf("%d",&pNew->iNumber);
    }
    free(pNew);  // 很严谨，将最后申请的地址再还回去
    return pHead;

}

// 这里之前加入temp， 只是为了防止破坏head，但是作用域仅限于该函数  函数里面传入的这个pHead，跟全局定义的pHead毫无瓜葛
// 所以我这个函数，就算不传入参数也可以实现打印操作
void Print(struct Student* pHead){
    printf("---this List has %d members:---\n",iCount);
    while (pHead != NULL){
        printf("%s\n", pHead->cName);
        printf("%d\n", pHead->iNumber);
        printf("\n");
        pHead = pHead->pNext;
    }
}

struct Student* Insert(){


}

