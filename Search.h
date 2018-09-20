//
// Created by allenhsu on 2018/9/18.
//

#ifndef LEARNC_SEARCH_H
#define LEARNC_SEARCH_H

#include <stdio.h>
#include <stdlib.h>

struct Tuple{
    int Maxsum;
    int begin;
    int end;
};

int MaxSubseqSum1(int A[], int N);

struct Tuple MaxSubseqSum4( int List[], int N );


#endif //LEARNC_SEARCH_H
