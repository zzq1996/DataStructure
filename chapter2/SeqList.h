//
// Created by zhangzhiqiang on 2020/5/16.
//

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H
#include <cstdlib>
#include <iostream>
//顺序表
struct SeqList{
private:
    int *data;//定义int型指针用于动态分配数组
    int maxSize;//顺序表的最大容量
    int last;//当前已存表项的最后位置（从0开始)，表空时为-1
public:
    SeqList(int size);//构造函数,size为初始化顺序表的大小
    bool IsFull();//判满
    bool IsEmpty();//判空
    bool Insert(int i,int x);//将新元素x插入到第i个位置后面
    bool Remove(int i,int &x);//删除第i个位置的元素，并通过引用类型x返回其值
    void ReSize(int newSize);//扩充顺序表，使其新数组的元素个数为newSize
};
//构造函数（初始化）
SeqList::SeqList(int size) {
    maxSize=size;
    last=-1;//设置表长为空
    data=new int[size];
}
//判满
bool SeqList::IsFull() {
    return last == maxSize - 1;
}
//判空
bool SeqList::IsEmpty() {
    return last==-1;
}
//插入
bool SeqList::Insert(int i, int x) {
    if(IsFull() || i<0 || i>last+1 ){//判表满、参数i是否合理，(i>last+1)表示只能顺序存储
        return false;
    }else{
        for (int j = last; j >= i ; j--) {
            data[j+1]=data[j];//先依次后移，空出第i号位置
        }
        data[i]=x;//这里注意，若定义数组 int a[10],表示10个元素，但使用数组时，下标是0～9
        last++;//最后位置加1
        return true;
    }
}
//删除
bool SeqList::Remove(int i, int &x) {
    if (IsEmpty() || i<1 ||i>last+1){//判表空、参数i是否合理
        return false;
    }else{
        x=data[i-1];//保存第i个被删元素
        for (int j = i; j <= last; j++) {
            data[j-1]=data[j];//依次往前移，填补
        }
        last--;//最后位置减1
        return true;
    }
}
//扩充顺序表，新数组元素个数为newSize
void SeqList::ReSize(int newSize) {
    if (newSize<=0 || newSize==maxSize){//检查参数的合理性
        std::cout<<"无效的数组大小\n";
    }else{
        int *newArray=new int[newSize];//建立新数组
        int n=last+1;//记录原数组长度为n
        int *srcptr=data;//原数组首地址
        int *destptr=newArray;//新数组首地址
        while (n--){
            *destptr++ = *srcptr++;//复制元素
        }
        delete []data;//删老数组
        data=newArray;//复制新数组
        maxSize=newSize;
    }
}
#endif //DATASTRUCTURE_SEQLIST_H
