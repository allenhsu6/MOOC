/**
 * 从这个函数中我们可以感受到c中编程的流程，编程就是体现一个解决问题的过程
 * 第一步，构建结构体，搭建框架，写出要用到的函数签名
 * 第二步，每个函数的程序框架，逐步填充
 */

#include "poly.h"
#include <string.h>
#include "Student.h"
#include "Search.h"
#include "BinarySearch.h"




int main(){
    int n, num[100];
    scanf("%d", &n);
    for(int i=0; i<n; ++i)	scanf("%d", &num[i]);

    struct Tuple a;
    a = MaxSubseqSum4(num,n);
    printf("%d %d %d", a.Maxsum, a.begin, a.end);


    return 0;

}