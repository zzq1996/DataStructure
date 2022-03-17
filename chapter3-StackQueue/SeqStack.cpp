

#include "SeqStatck.h"

//构造函数，size为初始化时栈的长度
SeqStatck::SeqStatck(int size) {
    data=new int [size];
    maxSize=size;
    top=-1;//栈顶指针初始化为-1
}

//判满
bool SeqStatck::IsFull() {
    return top==maxSize-1;
}

//判空
bool SeqStatck::IsEmpty() {
    return top==-1;
}

//进栈（三步走）
bool SeqStatck::Push(int &x) {
    if(!IsFull()){//1、先判栈是否为满
        top=top+1;//2、栈顶指针加1
        data[top]=x;//3、将元素放入栈顶
        return true;
    }else{
        return false;
    }
}

//出栈（三步走）
bool SeqStatck::Pop(int &x) {
    if(!IsEmpty()){//1、先判栈是否为空
        x=data[top];//2、将栈顶元素保存在x
        top=top-1;//3、栈顶指针减1
        return true;
    }else{
        return false;
    }
}