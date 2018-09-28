//
// Created by allenhsu on 2018/9/13.
//


// 下面第一个是结构体名字 第二个是 列表结构的指针


#include "poly.h"

int Compare(int a, int b){
    if (a>b) return 1;
    else if (a < b) return -1;
    else return 0;
}


// 两个多项式相加
Polynomial Add(Polynomial p1, Polynomial p2) {
    Polynomial P, front, temp;
    int sum;
    P = (Polynomial)malloc(sizeof(struct PolyNode)); // P是这个空节点
    front = P; // 用front做头 最后返回front
    while (p1 && p2){
        switch (Compare(p1->expon, p2->expon)){
            case 1:
                Attach(p1->coef, p1->expon, &P); // P本来就是个指针，这里传入的是指针的指针
                p1 = p1->link;
                break;
            case -1:
                Attach(p2->coef, p2->expon, &P);// P头在这个函数中已经做了移动
                p2 = p2->link;
                break;
            case 0:
                sum = p1->coef + p2->coef;
                if (sum) Attach(sum, p1->expon, &P);
                p1 = p1->link;
                p2 = p2->link;
                break;
        }
    }
    for (; p1 ; p1 = p1->link) {
        Attach(p1->coef, p1->expon, &P);
    }
    for (; p2; p2 = p2->link) {
        Attach(p2->coef, p2->expon, &P);
    }
    P->link = NULL;
    temp = front;
    front = front->link;
    free(temp);
    return front;  // 空头已经释放
}


void PrintPoly(Polynomial P) {
    int flag = 0;
    while (P){
        if (!flag){
            flag = 1;
        } else printf(" ");
        printf("%d %d",P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

Polynomial Mult(Polynomial p1, Polynomial p2) {
    Polynomial t1, t2, P, Rear, t;
    int c, e;
    if (!p1 || !p2) return NULL;
    // 第一种方法，乘法运算转换为加法运算, P1的每一项与p2做乘
//    t1 = p1; t2 = p2;
//    P = (Polynomial)malloc(sizeof(struct PolyNode));
//    Rear = P;
//    while (t2){
//        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
//        t2 = t2->link;
//    }

    // 第二种方法，逐项插入
    t1 = p1; t2 = p2;
    P = (Polynomial)malloc(sizeof(struct PolyNode)); // P是这个空节点
    Rear = P;
    // 初始化结果项P
    while (t2){
        e = t1->expon + t2->expon;
        c = t1->coef * t2->coef;
        if (!c){
            e = 0;
        }
        Attach(c, e, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1){
        t2 = p2; Rear = P; // Rear又回到P头
        while (t2){
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            // 这里要将新生成的p项插入到原有序列中
            while (Rear->link && Rear->link->expon > e){
                Rear = Rear->link;
            }
            // 这里还要考虑如果两项相加之后，系数为零，那么要删除该项
            if (Rear->link && Rear->link->expon == e){
                if (Rear->link->coef + c){
                    Rear->link->coef += c;
                } else{
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else{
                Polynomial P;
                P = (Polynomial)malloc(sizeof(struct PolyNode)); // 申请节点
                P->coef=c;  // 对节点赋值
                P->expon=e;
                P->link = Rear->link;
                Rear->link = P;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    // 最后结果的处理

    t2 = P;
    P = P->link;
    free(t2);

    return P;
}
/**
 * 这个attach最后两步很有味道，指针的指针，值得思考
 * 我终于明白为什么要做指针的指针操作，因为我们要改动指针，必须传入指针的地址，否则即使你给指针赋值也没用
 * @param c 多项式的系数
 * @param e 多项式的级数
 * @param pRear  把由c,e两项构成的多项式接在Rear后面
 */
void Attach(int c, int e, Polynomial *pRear){
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode)); // 申请节点
    P->coef=c;  // 对节点赋值
    P->expon=e;
    P->link=NULL;

    (*pRear)->link = P; // 把新申请的P插到Rear后面
    *pRear = P;  // *pRear就是个结构体指针， 这样才能真正的做更改，就是说在attach中，已经把传入的指针指向做了更改
}

/**
 * 解决怎么读多项式，首先要考虑怎么输入，输入什么，格式是什么
 * @return 读入的多项式链表
 */
Polynomial ReadPoly() {
    Polynomial P, Rear, t;
    int c, e, N;
    scanf("%d",&N);
    P = (Polynomial)malloc(sizeof(struct PolyNode)); // 创建链表头的空节点
    P->link = NULL;
    Rear = P;
    while (N--){
        scanf("%d %d", &c, &e);
        if (!c){
            e = 0;
        }
        Attach(c,e,&Rear);
    }
    t = P; P = P->link; free(t); // 删除掉空节点
    return P;
}