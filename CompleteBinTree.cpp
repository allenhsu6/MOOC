#include <iostream>
#include <algorithm>
using namespace std;

#define MaxSize 1005
int sortNum[MaxSize] = {0};         //
int CBTreeNode[MaxSize] = {0};      //
int countNum = 0;

void CreatCBTree(int root,int N)
{
    if(root > N)
        return;
    int left = root * 2;
    int right = root * 2 + 1;
    CreatCBTree(left,N);        //中序遍历LGR从小到大 小的先
    // 这一步是关键，将中序遍历的值（输入序列递增），放在对应CBT的下标为root的值中，下标root 是完全二叉树的中序遍历生成的
    CBTreeNode[root] = sortNum[countNum++];
    CreatCBTree(right,N);
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> sortNum[i];

    sort(sortNum,sortNum + N);//按从小到大排序; 输入首尾地址

    CreatCBTree(1,N);
    // 输出CBTree 从1开始输出
    for(int i = 1; i <= N; i++) {
        if(i != N)
            printf("%d ",CBTreeNode[i]);
        else
            printf("%d",CBTreeNode[i]);
    }
    return 0;
}