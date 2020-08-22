//
// Created by zhangzhiqiang on 2020/7/5.
//

#ifndef DATASTRUCTURE_CIRCLIST_H
#define DATASTRUCTURE_CIRCLIST_H
#include <iostream>
using namespace std;
struct LinkNode{//单链表结点
    int data;//数据域
    LinkNode *link;//指针域
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
//构造函数，初始化附加头结点的循环单链表
CircList::CircList() {
    LinkNode *headNode=new LinkNode;//分配一个头结点
    headNode->link=headNode;//link域存放的是头结点的地址
    first=headNode;//头指针指向头结点
    last=headNode;//尾指针指向头结点
}
//将新元素x插入到循环链表
bool CircList::Insert(int &x) {
    LinkNode *newNode=new LinkNode;//为新插入元素构建结点
    newNode->data=x;//数据域存放元素值
    //尾插法(新插入元素作为表尾)
    newNode->link=first;//新插入元素的结点作为尾结点，指向头结点
    last->link=newNode;//插入在最后一个结点后面
    last=newNode;//尾指针指向尾结点
}

//删除第i个位置的结点（i从1开始），将被删结点值通过引用类型x返回
bool CircList::Remove(int i, int &x) {
    LinkNode *current;//被删除结点的前一个结点
    LinkNode *del;//被删除结点
    current=first;//先将结点指向头结点，然后遍历寻找第i个位置的前一个结点
    for (int j = 0; j < i-1; ++j) {
        current=current->link;
    }
    del=current->link;//找到删除结点
    x=del->data;//保存删除结点的元素值
    if(del==last){//删除位置为表尾结点
        current->link=first;//则current变成表尾,让其指向头结点
        last=current;//修改表尾指针
    }else{
        current->link=del->link;//重新拉链，表尾指针不变
    }
    delete del;//删除结点
    return true;
}

void CircList::Print() {
    LinkNode *current=first->link;
    do{
        cout<<current->data<<",";
        current=current->link;
    }while (current->link!=first);
    cout<<last->data;

}

#endif //DATASTRUCTURE_CIRCLIST_H
