//
// Created by zhang zhiqiang on 2021/9/11.
//

#include <iostream>
#include "LinkedStack.h"

//构造函数
LinkedStack::LinkedStack() {
    top= nullptr;
}

//出栈
bool LinkedStack::Pop(int &x) {
    LinkNode *del=top;//暂存栈顶元素
    top=top->link;//栈顶指针退到新的栈顶位置
    x=del->data;//保存退栈元素
    delete del;//删除结点
    return true;
}

//入栈
bool LinkedStack::Push(int x) {
    LinkNode *newNode=new LinkNode;//为插入元素构造新结点
    newNode->data=x;//赋值
    if(IsEmpty()){//若栈为空
        top=newNode;//新插入结点为栈顶
    }else{//若栈不为空
        newNode->link=top;//新插入结点指向栈顶结点
        top=newNode;//栈顶指针指向新插入结点
    }
    return true;
}

//判栈空
bool LinkedStack::IsEmpty() {
    return (top== nullptr);
}

//清空栈
void LinkedStack::makeEmpty() {
    LinkNode *p;
    while(!IsEmpty()){//逐个清空
        p=top;
        std::cout<<p->data;
        top=top->link;
        delete p;
    }
}