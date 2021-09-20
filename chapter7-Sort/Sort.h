//
// Created by zhang zhiqiang on 2021/9/11.
//

#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H

class Sort{

public:
    /*插入排序
     * ————每次将一个待排序的元素插入到已排好序的子序列中，直到全部元素插入完成*/
    void InsertSort(int A[],int n);//直接插入排序（不带哨兵）
    void InsertSort2(int A[],int n);//直接插入排序（带哨兵A[0]),数据从A[1]开始存放
    void BinaryInsertSort(int A[],int n);//折半插入排序,A[0]为暂存单元
    void ShellSort(int A[],int n);//希尔排序，A[0]为暂存单元

    /*交换排序
     * ————根据序列中两个元素关键字的比较结果来交换这两个元素在序列中的位置*/
    void BubbleSort(int A[],int n);//冒泡排序
    void QuickSort(int A[],int low,int high);//快速排序

    /*选择排序
     * ————每一趟在待排序元素中选取关键字最小（最大）的元素加入有序子序列*/
    void SelectSort(int A[],int n);//快速选择排序
    void HeapSort(int A[],int len);//堆排序

    /*归并排序*/


};



#endif //DATASTRUCTURE_SORT_H
