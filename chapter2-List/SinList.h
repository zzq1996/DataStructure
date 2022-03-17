
#ifndef DATASTRUCTURE_SINLIST_H
#define DATASTRUCTURE_SINLIST_H

#include <iostream>

//单链表结点
struct LinkNode{
    int data;//数据域
    LinkNode *link;//指针域

};

//带头结点的单链表
class SinList{

private:
    LinkNode *first;//指向头结点的指针

public:
    SinList();//构造函数
    bool Insert(int &x);//将新元素x插入
    bool Remove(int i,int &x);//删除第i个位置的结点（i从1开始），将被删结点值通过引用类型x返回
};


#endif //DATASTRUCTURE_SINLIST_H
