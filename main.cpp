#include <iostream>
#include "chapter5/BInaryTree.h"
#include "chapter3/SeqQueue.h"
#include "chapter7/Sort.h"
#include "chapter8/Search.h"

using namespace std;

int main() {

    Sort sort;
    int A[8]={49,38,65,97,76,13,27,49};
    int B[11]={7,10,13,16,19,29,32,33,37,41,43};//有序表
    int A1[9]={0,49,38,65,97,76,13,27,49};

    int H[9]={-1,53,17,78,9,45,65,87,32};//初始建堆序列



//    sort.InsertSort(A,8);//直接插入排序
//    cout<<"\n排序结果：";
//    for (int i = 0; i < 8; ++i) {
//        cout<<A[i]<<" ";
//    }

//    sort.InsertSort2(A1,8);//带哨兵的直接插入排序(待排序元素为8个(数组元素-1))
//    cout<<"\n排序结果：";
//    for (int i = 0; i < 9; ++i) {
//        cout<<A1[i]<<" ";
//    }

    sort.HeapSort(H,8);
    cout<<"\n排序结果：";
    for (int i = 0; i < 9; ++i) {
        cout<<H[i]<<" ";
    }

//    Search search;
//    int i=search.Binary_Search(B,11,3);
//    cout<<"元素3位置："<<i;



    return 0;
}
