

#include "CirQueue.h"
#include <cstdio>
#include <iostream>

using namespace std;

//构造函数
CirQueue::CirQueue(int size){

    pQue=new char[size];//申请一个数组构成循环链表

    front=0,rear=0;//初始化队头队尾都指向0

    maxSize=size;
}

//判队满
bool CirQueue::IsFull() {
    return ((rear+1)%maxSize==front);
}

//判队空
bool CirQueue::IsEmpty() {
    return (front==rear);
}

//返回队内元素个数
int CirQueue::GetSize() {
    return (rear-front+maxSize)%maxSize;
}

//出队
bool CirQueue::DeQueue(int &x) {
    if(!IsEmpty()){//若队不为空
        cout<<"队列不为空，";
        x=pQue[front];//返回队头元素
        front=(front+1)%maxSize;//队头加1
    }
    return true;
}

//入队
bool CirQueue::EnQueue(int x) {
    if(!IsFull()){//若队不满
        cout<<"队列不为满，";
        pQue[rear]=x;//插入队尾
        cout<<"添加元素："<<x<<endl;
        rear=(rear+1)%maxSize;//队尾加1
    }else{
        cout<<"队列已满"<<endl;
    }
    return true;
}

void CirQueue::PrintMember() {
    cout<<"当前循环队列元素：";
    while (rear!=front){
        cout<<pQue[front];
        front++;
    }
}
