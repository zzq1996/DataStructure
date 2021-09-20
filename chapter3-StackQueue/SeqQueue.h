//
// Created by zhangzhiqiang on 2020/8/22.
//

#ifndef DATASTRUCTURE_SEQQUEUE_H
#define DATASTRUCTURE_SEQQUEUE_H

#include <cstdio>

using namespace std;

//循环队列，用数组存储，定义rear和front表示队尾元素的下一个位置和队头元素在数组中的位置
class SeqQueue {
private:
    char *pQue;    //指向申请的空间
    int front;       // 队头
    int rear;        //队尾
    int maxSize;       //记录空间的大小

public:
    //构造函数
    SeqQueue(int Size);
    bool EnQueue(int x);//入队
    bool DeQueue(int &x);//出队
    bool IsEmpty();
    bool IsFull();
    int GetSize();
    void PrintMember(SeqQueue seqQueue);
};



#endif //DATASTRUCTURE_SEQQUEUE_H
