//
// Created by allenhsu on 2018/9/14.
//

#include "BinarySearch.h"

/**
 *
 * @param list 要查找的队列
 * @param K 要查找的数
 * @return  找到数字的在数组中的下标
 */
int BinarySearch(struct Lnode *list, int K){
    int left, right, mid; // 元素初始化
    left = 1;
    right = list->length;
    while (right >= left){
        mid = (right + left)/2;
        if (K > list->Element[mid-1]) left = mid+1;
        else if (K < list->Element[mid-1]) right = mid-1;
        else return mid;
    }
    return 0;
}