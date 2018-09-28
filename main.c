/**
 * 从这个函数中我们可以感受到c中编程的流程，编程就是体现一个解决问题的过程
 * 第一步，构建结构体，搭建框架，写出要用到的函数签名
 * 第二步，每个函数的程序框架，逐步填充
 */
#include "poly.h"

void Test(Polynomial *p, Polynomial p2){
    Polynomial pp;
    pp = (Polynomial)malloc(sizeof(Polynomial));
    pp->expon = 3;
    pp->coef = 2;
    pp->link = NULL;
    (*p)->link = pp;
    *p = pp;
    p2->link = pp;
    p2 = pp;
}

int main()
{
    Polynomial p, temp1, temp2;
    p = (Polynomial)malloc(sizeof(Polynomial));
    p->coef = 4;
    p->expon = 5;
    temp1 = p;
    temp2 = p;
    Test(&temp1, temp2); // 修改内容，我们要传地址； 修改地址，我们要传地址的地址！！！
    PrintPoly(temp1);
    PrintPoly(temp2);

    return 0;
}


    // 关于结构体怎么用指针取出对应位置的值

//    struct School{
//        char head1;
//        char head2;
//        float velocity;
//    };
//
//
//
//    struct School school = {0x55,0x33,123.345};
//    char *p = & school.head1;
//
//    printf("%c\n",*p);
//    printf("%c\n",*(++p));
//    printf("%f\n",*(float *)(p+3));  // 终于解决了！！！


//    printf("%c\n", *(++p));
//
//    printf("%c\n", *(++p));


    //  int name[10] = {12,3,4,5,6,3};
//    int *a = name;
//    for (int i = 0; i < 4; ++i) {
//        printf("%d\n", *(a++));   // 在数组中可以这样使用，但是出了结构体中就是非法的
//    }

