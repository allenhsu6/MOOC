//
// Created by allenhsu on 2018/9/14.
//

#ifndef LEARNC_BINARYSEARCH_H
#define LEARNC_BINARYSEARCH_H

#include <stdlib.h>
#include <stdio.h>

struct Lnode{
    int Element[10];
    int length;
};

int BinarySearch(struct Lnode *list, int K);

#endif //LEARNC_BINARYSEARCH_H
