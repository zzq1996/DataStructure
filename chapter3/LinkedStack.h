//
// Created by zhangzhiqiang on 2020/8/22.
//

#ifndef DATASTRUCTURE_LINKEDSTACK_H
#define DATASTRUCTURE_LINKEDSTACK_H

//链栈的结点
struct LinkNode{//单链表结点
    int data;//数据域
    LinkNode *link;//指针域
};
//链栈（入/出栈都在栈顶即链表表头进行）
class LinkedStack {
private:
    LinkNode *top;//栈顶指针，即链头指针
public:
    LinkedStack();//构造函数
    bool Pop(int &x);//出栈，将出栈值赋给x
    bool Push(int x);//入栈
    bool IsEmpty();//判栈空
    void makeEmpty();//清空
};
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


#endif //DATASTRUCTURE_LINKEDSTACK_H
