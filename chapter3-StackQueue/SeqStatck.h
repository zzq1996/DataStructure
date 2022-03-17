

#ifndef DATASTRUCTURE_SEQSTATCK_H
#define DATASTRUCTURE_SEQSTATCK_H

//顺序栈（基于数组的存储表示）
struct SeqStatck{
private:
    int *data;//int型指针用于分配动态数组
    int top;//指向栈顶
    int maxSize;//记录栈的长度
public:
    SeqStatck(int size);//构造函数，size为初始化时栈的长度
    bool IsFull();//判满
    bool IsEmpty();//判空
    bool Push(int &x);//进栈（将元素x放入栈顶）
    bool Pop(int &x);//出栈（用x保存出栈元素）
};




#endif //DATASTRUCTURE_SEQSTATCK_H
