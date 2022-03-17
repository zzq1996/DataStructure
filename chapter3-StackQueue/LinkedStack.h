

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



#endif //DATASTRUCTURE_LINKEDSTACK_H
