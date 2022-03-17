

#ifndef DATASTRUCTURE_CIRCLIST_H
#define DATASTRUCTURE_CIRCLIST_H
#include <iostream>
using namespace std;
class LinkNode{//单链表结点
public:
    LinkNode *link;//指针域
    int data;//数据域
};

//带头结点的循环单链表
class CircList{
private:
    LinkNode *first,*last;//first指向头结点，last指向尾结点
public:
    CircList();//构造函数
    bool Insert(int &x);//将新元素x插入
    bool Remove(int i,int &x);//删除第i个位置的结点（i从1开始），将被删结点值通过引用类型x返回
    void Print();
};



#endif //DATASTRUCTURE_CIRCLIST_H
