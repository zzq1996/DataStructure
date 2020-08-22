//
// Created by zhangzhiqiang on 2020/8/22.
//

#ifndef DATASTRUCTURE_SEQQUEUE_H
#define DATASTRUCTURE_SEQQUEUE_H

//循环队列
class SeqQueue {
private:
    int rear,front;//队尾/队头指针
    int *element;//存放队列元素的数组
    int maxSize;
public:
    SeqQueue();//构造函数
    bool EnQueue(int x);//入队
    bool DeQueue(int &x);//出队
    bool IsEmpty();
    bool IsFull();
    int getSize();
};

//构造函数
SeqQueue::SeqQueue() {
    rear=front=0;
    maxSize=10;
    element =new int [maxSize];
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
int SeqQueue::getSize() {
    return (rear-front+maxSize)%maxSize;
}

//出队
bool SeqQueue::DeQueue(int &x) {
    if(!IsEmpty()){//若队不为空
        x=element[front];//返回队头元素
        front=(front+1)%maxSize;//队头加1
    }
    return true;
}

//入队
bool SeqQueue::EnQueue(int x) {
    if(!IsFull()){//若队不满
        element[rear]=x;//插入队尾
        rear=(rear+1)%maxSize;//队尾加1
    }
    return true;
}



#endif //DATASTRUCTURE_SEQQUEUE_H
