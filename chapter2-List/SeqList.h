

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

#endif //DATASTRUCTURE_SEQLIST_H
