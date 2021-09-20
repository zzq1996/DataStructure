#include <iostream>
#include "chapter5/BInaryTree.h"
#include "chapter3/SeqQueue.h"
#include "chapter7/Sort.h"

using namespace std;

int main() {

    Sort sort;
    int A[8]={49,38,65,97,76,13,27,49};
//    sort.InsertSort(A,8);//直接插入排序
//    cout<<"\n排序结果：";
//    for (int i = 0; i < 8; ++i) {
//        cout<<A[i]<<" ";
//    }

    int A1[9]={0,49,38,65,97,76,13,27,49};
    sort.InsertSort2(A1,8);//带哨兵的直接插入排序(待排序元素为8个)
    cout<<"\n排序结果：";
    for (int i = 0; i < 9; ++i) {
        cout<<A1[i]<<" ";
    }

    return 0;
}
