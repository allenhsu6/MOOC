#include <stdio.h>

#define Null -1    // 用来表示当前节点为空 这里一定要注意，宏定义
typedef char ElementType;
typedef int Tree;

struct TreeNode{
    ElementType Element;    // ABCD..的标识
    Tree Left; // 左位置
    Tree right;    // 有位置
}T1[10],T2[10];

Tree BuildTree(struct TreeNode T[]){
    int N, check[10];
    int  i, Root=Null; // N是总节点数
    char cl, cr;  // 根节点
    scanf("%d", &N);
    if(N){
        for ( i = 0; i < N; i++) {
            check[i] = 0;       // 初始化check数组
        }
        for ( i = 0; i < N; i++) {
            getchar();
            scanf("%c %c %c", &T[i].Element, &cl, &cr);    // 后面两个数有可能是“-”
            // 分别处理左右两侧
            if (cl != '-'){
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            } else
                T[i].Left = Null;
            if (cr != '-'){
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            } else
                T[i].right = Null;
        }

        for (i = 0; i < N; i++) {
            if (!check[i]) break;   //   当check[i]为0的时候，我们跳出循环
        }
        Root = i;   // N个中的第i个是root
    }
    return Root;
}

// 输入是两个根节点
int Isomorphic(Tree R1, Tree R2) {
    if ((R1 == Null) && (R2 == Null))      //如果为空树则是同构的
    return 1;
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null)))//如果一个为空一个不为空则不是同构的
    return 0;
    if ((T1[R1].Element) != (T2[R2].Element))//如果数据不同则不是同构的
        return 0;
    //如果左儿子都为空判断右儿子是否同构：主要看以上三个方面（1）右儿子是否都为空（2）是否一个有右儿子一个没有（3）右儿子数据是否相同
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null))
    return Isomorphic(T1[R1].right, T2[R2].right);
    /* 如果两棵树左儿子都不为空并且数据还是一样的，对左儿子进行递归*/
    if (((T1[R1].Left != Null) && (T2[R2].Left != Null)) && ((T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)))
    return (Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].right, T2[R2].right));
    /* 如果两棵树左儿子（一个空一个不空或者都不空）并且数据不一样，那么判断第一棵树的左（右）儿子是否跟第二棵树的右（左）儿子同构 */
    else
    return (Isomorphic(T1[R1].Left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].Left));
}

int main() {
    Tree R1, R2;     //首先建立两棵树，R1，R2为树的根节点
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2))   //Isomorphic函数判断是否同构
        printf("Yes\n");
    else printf("No\n");
    return 0;
}