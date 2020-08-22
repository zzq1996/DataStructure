//
// Created by zhangzhiqiang on 2020/7/6.
//

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <iostream>

struct BinTreeNode{//二叉链表的结点
    BinTreeNode *leftChild;//左孩子指针
    BinTreeNode *rightTree;//右孩子指针
    int data;//结点存放数据
};
class BinaryTree{
    BinTreeNode *root;//二叉树的根指针
public:
    BinaryTree();
    void visit(BinTreeNode *BTnode);//结点的访问函数
    int getHeight(BinTreeNode *BTnode);//获取二叉树的高度
    void search(int &x,BinTreeNode *&p,BinTreeNode *BTnode);//查找是否有数据域为x的结点，若存在，将p指向该结点；若不存在，p=nullptr
    //二叉树遍历的递归算法
    void preOrder(BinTreeNode *BTnode);//先序遍历
    void inOrder(BinTreeNode *BTnode);//中序遍历
    void postOrder(BinTreeNode *BTnode);//后序遍历
    //二叉树遍历的非递归算法
    void  levelOrder(BinTreeNode *BTnode);//层次遍历
};

//构造函数
BinaryTree::BinaryTree() {
    root= nullptr;
}

//输出结点的数据
void BinaryTree::visit(BinTreeNode *BTnode) {
    std::cout<<BTnode->data;
}

//计算二叉树高度（左右子树中较高的加1）
int BinaryTree::getHeight(BinTreeNode *BTnode) {
    if(BTnode== nullptr){
        return 0;
    }
    int lh,rh;
    lh=getHeight(BTnode->leftChild);
    rh=getHeight(BTnode->rightTree);
    return lh<rh ? rh+1 : lh+1;
}

//查找是否有数据域为x的结点，若存在，将p指向该结点；若不存在，p=nullptr
//这里要将p定义为引用型指针哦
void BinaryTree::search(int &x, BinTreeNode *&p, BinTreeNode *BTnode) {
    if(BTnode!= nullptr){
        if(BTnode->data==x){
            p=BTnode;
        }else{//如果BTnode的数据域不为x，则到它的左右子树去找
            search(x,p,BTnode->leftChild);//先找左子树
            if(p== nullptr){//左子树没找到
                search(x,p,BTnode->leftChild);//到右子树去找
            }
        }
    }
}

//先序遍历（根、左、右）
// 递归
void BinaryTree::preOrder(BinTreeNode *BTnode) {
    if(BTnode!= nullptr){
        visit(BTnode);
        preOrder(BTnode->leftChild);
        preOrder(BTnode->rightTree);
    }
}
//中序遍历（左、根、右）
// 递归
void BinaryTree::inOrder(BinTreeNode *BTnode) {
    if(BTnode!= nullptr){
        inOrder(BTnode->leftChild);
        visit(BTnode);
        inOrder(BTnode->rightTree);
    }
}
//后序遍历（左、右、根）
//递归
void BinaryTree::postOrder(BinTreeNode *BTnode) {
    if(BTnode!= nullptr){
        postOrder(BTnode->leftChild);
        preOrder(BTnode->rightTree);
        postOrder(BTnode);
    }
}

//层次遍历（定义循环队列，从上到下，从左到右遍历）
void BinaryTree::levelOrder(BinTreeNode *BTnode) {
    int maxSize=20;
    int front,rear;//定义队列的头尾指针
    BinTreeNode *que=new BinTreeNode[maxSize];//定义一个二叉树结点的数组，长度为20
    front=rear=0;//初始化队列收尾指针
    BinTreeNode *q;
    if(BTnode!= nullptr){
        rear=(rear+1)%maxSize;//先将队尾指针加1
        
    }
}



#endif //DATASTRUCTURE_BINARYTREE_H
