//
// Created by zhang zhiqiang on 2021/9/20.
//

#include "Search.h"
#include <cstdio>
#include "iostream"
using namespace std;

/*顺序查找,用于线性表
 * int A[8]={49,38,65,97,76,13,27,49};
 * */
int Search::Search_Seq(int *A, int n,int key) {
    int i=0;
    for (i = 0; i<n && A[i]!=key; ++i);
    return i==n ? -1:i;//查找失败，返回-1
}

/*带哨兵的顺序查找，A[0]为哨兵
 * int A[8]={49,38,65,97,76,13,27,49};
 * 数据从A[1]开始存放，从后往前查找，无需判断是否越界，效率更高
 * */
int Search::Search_Seq2(int *A, int n, int key) {
    A[0]=key;//0号位置存放待查找元素
    int i=0;
    for (i = n;  A[i]!=key ; --i) ;//从后往前查找
    return i;//查找失败，返回0
}

/*折半查找
 * 输入：int B[11]={7,10,13,16,19,29,32,33,37,41,43};
 * 输出：
 *      low:0,mid:5,high:10
        low:0,mid:2,high:4
        low:0,mid:0,high:1
        元素3位置：-1
 * */
int Search::Binary_Search(int *A, int n, int key) {
    int low=0,//头指针指向A[0]
        high=n-1,//尾指针指向A[n-1]
        mid=0;//中间位置

    while(low<=high){
        mid=(low+high)/2;//取中间位置
        cout<<"low:"<<low
            <<",mid:"<<mid
            <<",high:"<<high
            <<endl;

        if(A[mid]==key){
            return mid;

        }else if(A[mid]>key){//待查找元素小于中间位置元素
            high=mid-1;//从前半部分继续查找

        }else{//待查找元素大于中间位置元素
            low=mid+1;//从后半部分开始查找

        }
    }

    return -1;
}

