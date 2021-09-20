//
// Created by zhang zhiqiang on 2021/9/20.
//

#include "Search.h"

/*顺序查找,用于线性表
 * int A[8]={49,38,65,97,76,13,27,49};
 * */

int Search::Search_Seq(int *A, int n,int key) {
    int i=0;
    for (i = 0; i<n && A[i]!=key; ++i);
    return i==n ? -1:i;//查找失败，返回-1
}

/*带哨兵的顺序查找，A[0]为哨兵
 * 数据从A[1]开始存放，从后往前查找，无需判断是否越界，效率更高
 * */
int Search::Search_Seq2(int *A, int n, int key) {
    A[0]=key;//0号位置存放待查找元素
    int i=0;
    for (i = n;  A[i]!=key ; --i) ;//从后往前查找
    return i;//查找失败，返回0
}

