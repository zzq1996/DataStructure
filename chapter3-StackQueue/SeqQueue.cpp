//
// Created by zhang zhiqiang on 2021/9/11.
//

#include "SeqQueue.h"
#include <cstdio>
#include <iostream>

using namespace std;

//构造函数
SeqQueue::SeqQueue(int size){
    pQue=new char[size];//申请一个数组构成循环链表
    front=0;
    rear=0;
    maxSize=size;
}

//判队满
bool SeqQueue::IsFull() {
    return ((rear+1)%maxSize==front);
}

//判队空
bool SeqQueue::IsEmpty() {
    return (front==rear);
}

//返回队内元素个数
int SeqQueue::GetSize() {
    return (rear-front+maxSize)%maxSize;
}

//出队
bool SeqQueue::DeQueue(int &x) {
    if(!IsEmpty()){//若队不为空
        cout<<"队列不为空，";
        x=pQue[front];//返回队头元素
        front=(front+1)%maxSize;//队头加1
    }
    return true;
}

//入队
bool SeqQueue::EnQueue(int x) {
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

void SeqQueue::PrintMember(SeqQueue seqQueue) {
    cout<<"当前循环队列元素：";
    for (int i = 0; i < seqQueue.GetSize(); ++i) {
        cout<<pQue[i]<<" ";
    }
}
