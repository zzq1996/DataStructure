//
// Created by zhangzhiqiang on 2020/8/22.
//

#ifndef DATASTRUCTURE_CIRQUEUE_H
#define DATASTRUCTURE_CIRQUEUE_H

#include <cstdio>

using namespace std;

//循环队列，用数组存储，定义rear和front表示队尾元素的下一个位置和队头元素在数组中的位置
class CirQueue {
private:
    char *pQue;    //指向申请的空间，队列元素类型为char
    int front;       // 队头
    int rear;        //队尾
    int maxSize;       //记录空间的大小

public:
    //构造函数
    CirQueue(int Size);

    bool EnQueue(int x);//入队
    bool DeQueue(int &x);//出队
    bool IsEmpty();
    bool IsFull();
    int GetSize();
    void PrintMember();
};



#endif //DATASTRUCTURE_CIRQUEUE_H
