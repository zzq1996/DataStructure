//
// Created by zhang zhiqiang on 2021/9/11.
//

#include "SinList.h"

/*
 * @Description 附加头结点的单链表构造函数
 * 新建一个空结点作为头结点
 */
SinList::SinList() {
    LinkNode *headNode=new LinkNode;//新建一个结点对象

    headNode->link=nullptr;//结点的next为空

    first=headNode;//结点头指针指向该结点
}



/*
 * @Description 插入新元素x
 * 每次插在头结点的后面
 */
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