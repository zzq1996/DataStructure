//
// Created by zhang zhiqiang on 2021/9/20.
//

#ifndef DATASTRUCTURE_SEARCH_H
#define DATASTRUCTURE_SEARCH_H

class Search{
public:
    int Search_Seq(int A[],int n,int key);//顺序查找
    int Search_Seq2(int A[],int n,int key);//带哨兵的顺序查找，数据从A[1]开始存放
    int Binary_Search(int A[],int n,int key);//折半查找（仅适用于有序的顺序表）


};


#endif //DATASTRUCTURE_SEARCH_H
