//
// Created by zhangzhiqiang on 2020/7/5.
//

#ifndef DATASTRUCTURE_SINLIST_H
#define DATASTRUCTURE_SINLIST_H

#include <iostream>

struct LinkNode{//单链表结点
    int data;//数据域
    LinkNode *link;//指针域
};
class SinList{//带头结点的单链表
private:
    LinkNode *first;//指向头结点的指针
public:
    SinList();//构造函数
    bool Insert(int &x);//将新元素x插入
    bool Remove(int i,int &x);//删除第i个位置的结点（i从1开始），将被删结点值通过引用类型x返回
    void Print();
};
//附加头结点的单链表构造函数
SinList::SinList() {
    LinkNode *headNode=new LinkNode;
    headNode->link=nullptr;
    first=headNode;
}
//插入新元素x
bool SinList::Insert(int &x) {
    LinkNode *newNode=new LinkNode;//为新插入元素构造结点
    newNode->data=x;//数据域为元素值
    //将新结点放在头结点的后面（不必区分在单链表头部或中部、尾部插入）
    newNode->link=first->link;
    first->link=newNode;
    return true;
}
//删除第i个位置的结点（i从1开始），将被删结点值通过引用类型x返回
bool SinList::Remove(int i, int &x) {
    LinkNode *del;//被删结点的指针
    LinkNode *current;//被删除结点的前一个结点
    current=first;//先将结点指向头结点，然后遍历寻找第i个位置的前一个结点
    for (int j = 0; j <i-1 ; ++j) {
        current=current->link;
    }
    del=current->link;//保存被删除结点
    current->link=del->link;//重新拉链
    x=del->data;//保存被删结点元素
    delete del;//删除del指向的结点
    return true;
}

#endif //DATASTRUCTURE_SINLIST_H
