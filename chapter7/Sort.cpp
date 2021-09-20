//
// Created by zhang zhiqiang on 2021/9/11.
//

#include <iostream>
#include "Sort.h"
#include "cstdio"
using namespace std;


/*直接插入排序（仅适用于顺序表、链表）
 * —————每次将一个待排序的记录按其关键字大小插入到前面已排好序的子序列中
 * ————依次将A[1]～A[n]插入到前面已排好序的子序列中
 * 输入记录：int A[8]={49,38,65,97,76,13,27,49};
 *          sort.InsertSort(A,8);
 * 排序结果：
    第1趟：38 49 65 97 76 13 27 49————将第二个元素38插入到前面已排好序的子序列中
    第2趟：38 49 65 97 76 13 27 49————将第三个元素65插入到前面已排好序的子序列中
    第3趟：38 49 65 97 76 13 27 49————将第四个元素97插入到前面已排好序的子序列中
    第4趟：38 49 65 76 97 13 27 49————将第五个元素76插入到前面已排好序的子序列中
    第5趟：13 38 49 65 76 97 27 49————将第六个元素13插入到前面已排好序的子序列中
    第6趟：13 27 38 49 65 76 97 49————将第七个元素27插入到前面已排好序的子序列中
    第7趟：13 27 38 49 49 65 76 97————将第八个元素49插入到前面已排好序的子序列中
    排序结果：13 27 38 49 49 65 76 97
 *
 * */
void Sort::InsertSort(int A[],int n) {
    int i=0,
        j=0,
        temp=0;
    for (i = 1; i < n; i++) {

        if(A[i]<A[i-1]){ //如果A[i]的关键字小于前驱
            temp=A[i]; //用temp暂时保存A[i]

            for (j = i-1; j >= 0 && A[j]>temp; --j) {  //检查前面所有已排好序的元素
                A[j+1]=A[j]; //所有大于temp的元素都往后挪
            }

            A[j+1]=temp;  //复制到插入位置
        }

        cout<<"\n第"<<i<<"趟：";
        for (int i = 0; i < n; ++i) {
            cout<<A[i]<<" ";
        }

    }

}

/*带哨兵的直接插入排序
 * ————依次将A[2]～A[n]插入到前面已排好序的子序列中，A[0]作为哨兵，不存放元素
 * 输入记录：int A1[9]={0,49,38,65,97,76,13,27,49};
 *          sort.InsertSort2(A1,8);
 * 排序结果：
        第1趟：38 38 49 65 97 76 13 27
        第2趟：38 38 49 65 97 76 13 27
        第3趟：38 38 49 65 97 76 13 27
        第4趟：76 38 49 65 76 97 13 27
        第5趟：13 13 38 49 65 76 97 27
        第6趟：27 13 27 38 49 65 76 97
        第7趟：49 13 27 38 49 49 65 76
        排序结果：49 13 27 38 49 49 65 76 97
 *
 * */

void Sort::InsertSort2(int A[], int n) {//n为待排序元素个数
    int i=0,
        j=0;
    for (i = 2; i <= n; i++) { //依次将A[2]~A[n]插入到前面已排序序列

        if(A[i]<A[i-1]){ //若A[i]关键码小于其前驱，将A[i]插入有序表
            A[0]=A[i];  //复制为哨兵，A[0]不存放元素

            for (j = i-1; A[0] < A[j]; --j) {  //从后往前查找待插入位置
                A[j+1]=A[j];  //往后挪位
            }
            A[j+1]=A[0];  //复制到插入位置
        }

        cout<<"\n第"<<i-1<<"趟：";
        for (int i = 0; i < n; ++i) {
            cout<<A[i]<<" ";
        }
    }
}

/* 折半插入排序（仅适用于顺序表）
 * ————先用折半查找得到应该插入的位置，再移动元素（A[0]暂存待插入元素）
 * 输入：int A1[9]={0,49,38,65,97,76,13,27,49};
 *      sort.BinaryInsertSort(A1,8);
 * 输出：
 *      第1趟：38 38 49 65 97 76 13 27 49
        第2趟：65 38 49 65 97 76 13 27 49
        第3趟：97 38 49 65 97 76 13 27 49
        第4趟：76 38 49 65 76 97 13 27 49
        第5趟：13 13 38 49 65 76 97 27 49
        第6趟：27 13 27 38 49 65 76 97 49
        第7趟：49 13 27 38 49 49 65 76 97
        排序结果：13 27 38 49 49 65 76 97
 * */
void Sort::BinaryInsertSort(int *A, int n) {
    int i=0,
        j=0,
        low=0,
        high=0,
        mid=0;

    for (i = 2; i <= n; ++i) { //依次将A[1]~A[n-1]插入到前面的已排序序列
        A[0]=A[i]; //将A[i]暂存到A[0]
        low=1;
        high=i-1; //设置折半查找范围

        while(low<=high){ //折半查找（默认递增有序)

            mid=(low+high)/2;//取中间点

            if(A[mid]>A[0]){ //查找左半子表
                high=mid-1;

            }else{ //查找右半子表
                low=mid+1;
            }
        }


        for (j = i-1; j>=high+1 ; --j) {
            A[j+1]=A[j]; //统一后移元素，空出插入位置high+1
        }

        A[high+1]=A[0]; //插入

        cout<<"\n第"<<i-1<<"趟：";
        for (int i = 0; i <= n; ++i) {
            cout<<A[i]<<" ";
        }
    }

}

/* 希尔排序（仅适用于顺序表）A[0]为暂存单元
 * ————先将排序表分割成若干子表，对各个子表分别进行直接插入排序
 * 输入：int A1[9]={0,49,38,65,97,76,13,27,49};
 *      sort.ShellInsertSort(A1,8);
 * 输出：
 *      d=4时：49 49 13 27 49 76 38 65 97
        d=2时：65 27 13 49 38 65 49 76 97
        d=1时：49 13 27 38 49 49 65 76 97
        排序结果：13 27 38 49 49 65 76 97
 * */
void Sort::ShellSort(int *A, int n) {
    int d=0,
        i=0,
        j=0;
    for (d = n/2; d >= 1 ; d = d/2) { //步长（增量）变化

        for (i = d+1; i <= n; ++i) {

            if(A[i]<A[i-d]){ //需将A[i]插入有序增量子表
                A[0]=A[i];//暂存A[i]

                for (j = i-d; j>0 && A[0]<A[j] ; j-=d) {
                    A[j+d]=A[j]; //记录后移，查找插入的位置
                }

                A[j+d]=A[0]; //插入
            }
        }
        cout<<"\nd="<<d<<"时：";
        for (int i = 0; i <= n; ++i) {
            cout<<A[i]<<" ";
        }
    }
}

/* 冒泡排序
 * ——————基于交换的排序，元素比较次数=排序中的逆序个数
 * 输入：
 *      int A[8]={49,38,65,97,76,13,27,49};
 *      sort.BubbleSort(A,8);
 * 输出：
 *      第1趟：13 49 38 65 97 76 27 49
        第2趟：13 27 49 38 65 97 76 49
        第3趟：13 27 38 49 49 65 97 76
        第4趟：13 27 38 49 49 65 76 97
        排序结果：13 27 38 49 49 65 76 97
 * */
void Sort::BubbleSort(int *A, int n) {
    int temp;

    for (int i = 0; i < n-1; ++i) {
        bool flag= false;//表示本趟冒泡是否发生交换的标志

        for (int j=n-1 ; j>i ; --j) {//一趟冒泡过程

            if(A[j-1]>A[j]){ //若为逆序
                temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;

                flag= true;
            }

        }

        if(!flag){ //本趟没有发生交换，说明表已有序
            return;
        }

        cout<<"\n第"<<i+1<<"趟：";
        for (int i = 0; i < n; ++i) {
            cout<<A[i]<<" ";
        }
    }

}


/* 快速排序
 * ——————指定pivot划分左右，对左右依次递归划分
 * 输入：int A[8]={49,38,65,97,76,13,27,49};
 *      sort.QuickSort(A,0,7);
 * 输出：
 *      pivot(A[low])：49,low:3,high:3
        pivot左边序列：27 38 13 pivot右边序列：76 97 65 49

        pivot(A[low])：27,low:1,high:1
        pivot左边序列：13 pivot右边序列：38 49 76 97 65 49

        pivot(A[low])：76,low:6,high:6
        pivot左边序列：13 27 38 49 49 65 pivot右边序列：97

        pivot(A[low])：49,low:4,high:4
        pivot左边序列：13 27 38 49 pivot右边序列：65 76 97

        排序结果：13 27 38 49 49 65 76 97
 * */

//用第一个元素将待排序序列划分成左右两个部分
int Partition(int A[],int low,int high){
    int pivot=A[low]; //第一个元素作为枢轴

    while(low<high){ //用low、high搜索枢轴的最终位置

        while(low<high && A[high]>=pivot ){
            --high;
        }
        A[low]=A[high]; //比枢轴小的元素移到左端

        while (low<high && A[low]<=pivot){
            ++low;
        }
        A[high]=A[low]; //比枢轴大的元素移到右端
    }
    A[low]=pivot; //枢轴元素存放到最终位置

    cout<<"pivot(A[low])："<<A[low]<<",low:"<<low<<",high:"<<high<<endl;
    cout<<"pivot左边序列：";
    for (int i = 0; i < low; ++i) {
        cout<<A[i]<<" ";
    }
    cout<<"pivot右边序列：";
    for (int i = low+1; i < 8; ++i) {
        cout<<A[i]<<" ";
    }
    cout<<endl<<endl;

    return low; //返回存放枢轴的最终位置
}

//快速排序
void Sort::QuickSort(int *A, int low, int high) {
    if(low<high){ //递归跳出条件
        int pivotpos= Partition(A,low,high);//划分
        QuickSort(A,low,pivotpos-1);//划分左子表
        QuickSort(A,pivotpos+1,high);//划分右子表
    }
}


/* 简单选择排序（一定要进行n-1趟处理）
 *  输入： int A[8]={49,38,65,97,76,13,27,49};
 *        sort.SelectSort(A,8);
 *  输出：
 *      第1趟：13 38 65 97 76 49 27 49
        第2趟：13 27 65 97 76 49 38 49
        第3趟：13 27 38 97 76 49 65 49
        第4趟：13 27 38 49 76 97 65 49
        第5趟：13 27 38 49 49 97 65 76
        第6趟：13 27 38 49 49 65 97 76
        第7趟：13 27 38 49 49 65 76 97
        排序结果：13 27 38 49 49 65 76 97
 * */
void Sort::SelectSort(int *A, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min=i, //记录最小元素的位置
            temp=0;

        for (int j = i+1; j < n; ++j) { //在A[i]~A[n-1]中选择最小的元素

            if(A[j]<A[min]){
                min=j; //更新最小元素的位置
            }
        }

        if(min!=i){
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
        }

        cout<<"\n第"<<i+1<<"趟：";
        for (int i = 0; i < n; ++i) {
            cout<<A[i]<<" ";
        }

    }
}


/* 堆排序
 * 输入：int H[9]={-1,53,17,78,9,45,65,87,32};//初始建堆序列
 *      sort.HeapSort(H,8);
 * 输出：
 *      第1趟：9 78 45 65 32 17 9 53 87
        第2趟：53 65 45 53 32 17 9 78 87
        第3趟：9 53 45 9 32 17 65 78 87
        第4趟：17 45 32 9 17 53 65 78 87
        第5趟：17 32 17 9 45 53 65 78 87
        第6趟：9 17 9 32 45 53 65 78 87
        第7趟：9 9 17 32 45 53 65 78 87
        排序结果：9 9 17 32 45 53 65 78 87
 * */

//将以k为根的子树调整为大根堆
void HeadAdjust(int A[],int k,int len){
    A[0]=A[k]; //A[0]暂存子树的根结点

    for (int i = 2*k; i <= len ; i*=2) { //沿key较大的子结点向下筛选

        if(i<len && A[i]<A[i+1]){
            i++; //取key较大的子结点的下标
        }

        if(A[0]>=A[i]){
            break; //筛选结束
        }else{
            A[k]=A[i];//将A[i]调整到双亲结点上
            k=i; //修改k值，以便继续向下筛选
        }

    }
    A[k]=A[0]; //被筛选结点的值放入最终位置
}

//建立大根堆————把所有非终端结点都检查一遍，是否满足大根堆的要求
void BuildMaxHeap(int A[],int len){
    for (int i = len/2; i >0 ; --i) {
        HeadAdjust(A,i,len);
    }
}

//堆排序
void Sort::HeapSort(int *A, int len) {
    int temp=0;//用于交换堆顶与堆底元素

    BuildMaxHeap(A,len);//初始建堆

    for (int i = len; i >1 ; --i) {  //n-1趟的交换与建堆
        temp=A[i];
        A[i]=A[1];
        A[1]=temp;
        HeadAdjust(A,1,i-1);//将剩余的待排序元素整理成堆

        cout<<"\n第"<<len-i+1<<"趟：";
        for (int i = 0; i <= len; ++i) {
            cout<<A[i]<<" ";
        }
    }
}
























