//
// Created by allenhsu on 2018/9/17.
//

#include <stdlib.h>
#include <stdio.h>

struct Student {
    char cName[20];  // 名字
    int iNumber;     // 学号
    struct Student *pNext;
};



int iCount;// 计算总数
struct Student *pHead; // 定义一个学生头

struct Student* Create();
void Print(struct Student* pTemp);
struct Student* Insert(struct Student* pHead);
struct Student* Delete(struct Student* pHead, int iIndex);


struct Student* Create(){
    iCount = 0;
    pHead = NULL; // 初始化
    struct Student *pEnd, *pNew;
    pEnd = pNew = (struct Student*)malloc(sizeof(struct Student));
    // 给新的节点赋值 直接输入到对应节点
    printf("输入列表数据，以0结尾\n");
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
//void Print(struct Student* pHead){
//    printf("---this List has %d members:---\n",iCount);
//    while (pHead != NULL){
//        printf("%s\n", pHead->cName);
//        printf("%d\n", pHead->iNumber);
//        printf("\n");
//        pHead = pHead->pNext;
//    }
//}

struct Student* Insert(struct Student* pHead){
    printf("插入列表到队头\n");

    struct Student* pNew = (struct Student*)malloc(sizeof(struct Student));
    scanf("%s",&pNew->cName);
    scanf("%d",&pNew->iNumber);

    pNew->pNext = pHead;
    pHead = pNew;
    iCount++;
    return pHead;
}


/**
 * 考虑边界 如果删除的是头尾节点该怎样做？ 尾巴不用考虑，因为队尾都是null没关系
 * @param pHead  列表头
 * @param iIndex  要删除的对应下标位置
 * @return
 */
struct Student* Delete(struct Student* pHead, int iIndex){

    struct Student *Temp, *pre; // 一个要删除的节点，一个是前一个节点
    pre = pHead;
    Temp = pHead;

    if (iIndex == 1){
        pHead = pHead->pNext;

    }else{
        for (int i = 2; i < iIndex; ++i) {
            pre = Temp;
            Temp = Temp->pNext;
        }
        pre->pNext = Temp->pNext;
    }

    free(pHead);
    iCount--;
    return pHead;

}

//struct Student* Merge( struct Student* pHead1, struct Student* pHead2 ){
//    struct Student *temp1, *temp2, *pNew;
//    temp1 = pHead1;
//    temp2 = pHead2;
//    while (temp1){
//        int a = temp1->iNumber;
//        pNew = (struct Student*)malloc(sizeof(struct Student));
//        pNew->iNumber = a;
//
//        while (temp2){
//            if(a < temp2->iNumber){    // L1中当前元素在L2中的状态
//                if(temp2 == pHead2){  // 如果L1中元素在L2的队首的情况
//
//                    pNew->pNext = pHead2;
//                    pHead2 = pNew;
//                } else{
//
//                }
//            } else{
//                temp2 = temp2->pNext;
//            }
//        }
//      temp1 = temp1->pNext;
//  }
//    return  NULL;
//}
