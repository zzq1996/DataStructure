//
// Created by zhangzhiqiang on 2020/7/6.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <iostream>
using namespace std;

//二叉链表的结点
typedef struct BinTreeNode {
    BinTreeNode *leftChild;//左孩子指针
    BinTreeNode *rightTree;//右孩子指针
    char data; //结点存放数据
}*BiTree;//定义指向该结构体的指针，即该二叉树第一个结点的首地址


//打印结点数据
void visit(BiTree pNode) {
    cout<<pNode->data<<" ";
}

//前序创建二叉树，这里输入的是二叉树的先序序列
 void CreateBiTree(BiTree &T){
    char item;
    cin>>item;
    if(item=='#'){
        T= nullptr;
    }else{
        T=new BinTreeNode ;
        T->data=item;

        CreateBiTree(T->leftChild);

        CreateBiTree(T->rightTree);
    }
}

//先序遍历
void PreOrder(BiTree T){
    if(T!= nullptr){
        visit(T);
        PreOrder(T->leftChild);
        PreOrder(T->rightTree);
    }
}

//中序遍历
void InOrder(BiTree T){
    if(T!= nullptr){
        PreOrder(T->leftChild);
        visit(T);
        PreOrder(T->rightTree);
    }
}

//后序遍历
void PostOrder(BiTree T){
    if(T!= nullptr){
        PreOrder(T->leftChild);
        PreOrder(T->rightTree);
        visit(T);
    }
}



#endif //DATASTRUCTURE_BINARYTREE_H
