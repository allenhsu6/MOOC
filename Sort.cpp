//
// Created by allenhsu on 2018/11/28.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int N;
int list[100000];

void Swap(int a, int b){
    int temp = list[a];
    list[a] = list[b];
    list[b] = temp;
}

void Print(int A[], int N){
    cout << A[0];
    for (int j = 1; j < N; ++j) {
        cout <<  " " << A[j];
    }
    cout << endl;
}

// 冒泡排序： 两个相邻的元素做比较
void Bubble_sort(){
    for (int i = N - 1; i > 0; --i) {
        int flag = 0;
        for (int j = 0; j < i; ++j) {
            if (list[j] > list[j + 1]) {
                Swap(j,j+1);
                flag = 1;
            }
        }
        if (!flag) break;
    }
}

// 一直保证前面的序列是递增的
void Insert_Sort(){
    for (int i = 1; i < N; ++i) {
        for (int j = i - 1; j >= 0 && list[j] > list[j + 1]; --j) {
            Swap(j, j + 1);
        }
    }
}

// 希尔排序 N 增量
void Shell_Sort(){
    vector<int> v;
    for (int j = 1; pow(2,j) < N; ++j){
        v.push_back(pow(2, j) - 1);
    }
    for (int size = v.size() - 1; size >= 0; --size) {
        int w = v[size];
        for (int i = w; i < N; i++) {
            for (int j = i - w; j >=0 && list[j] > list[j + w] ; j -= w) {
                Swap(j, j + w);
            }
        }
    }
}
// 选择排序
void Selection_Sort(){
    int i,j;
    for (j = 0; j < N; ++j) {
        int temp = j;
        for (i = j + 1; (i < N); ++i) {
            if (list[temp] > list[i]){
                temp = i;
            }
        }
        Swap(temp, j);
    }
}

// 堆排序

/**
 * 该函数实现的最大堆，是将最大的元素调至数组头，并不是由大到小的排序
 * @param A 要调整的数组
 * @param p 要调整的父节点
 * @param N 要调整子数组元素的个数
 */
void PercDown(int A[], int p, int N )
{   /* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
    int Parent, Child;
    int X;

    X = A[p]; /* 取出根结点存放的值 */
    for( Parent=p; (Parent*2+1)<N; Parent=Child ) {
        Child = Parent * 2 + 1;
        if( (Child!=N-1) && (A[Child]<A[Child+1]) )
            Child++;  /* Child指向左右子结点的较大者 */
        if( X >= A[Child] ) break; /* 找到了合适位置 */
        else  /* 下滤X */
            A[Parent] = A[Child];
    }
    A[Parent] = X;
}

void HeapSort(int A[], int N )
{ /* 堆排序 */
    int i;
    // 从下标最大的非叶子节点开始做调整
    // 这就是最大堆，满足自上而下的有序性...
    for ( i=N/2-1; i>=0; i-- )/* 建立最大堆 */{
        PercDown(A, i, N);
    }

    for ( i=N-1; i>0; i-- ) {
        /* 删除最大堆顶 */
        Swap( 0, i );
        PercDown( A, 0, i );
    }
}

// 归并排序
// 递归求解
void Merge(int A[], int temp[], int L, int R, int end){
    int Lend = R - 1;
    int t = L;
    int Num = end - L + 1;
    while (L <= Lend && R <= end){
        if (A[L] < A[R]) temp[t++] = A[L++];
        else temp[t++] = A[R++];
    }
    while (L <= Lend){
        temp[t++] = A[L++];
    }
    while (R <= end){
        temp[t++] = A[R++];
    }
    for (int i = 0; i < Num; ++i, end--) {
        A[end] = temp[end];
    }
}

void MSort(){

}

void MergeSort(int A[], int N){

}

// 非递归求解


int main(){
    cin >> N;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        cin >> list[i];
    }

    // Shell_Sort();
    // Selection_Sort();
    // HeapSort(list, N);

    Print(list, N);
    return 0;
}

