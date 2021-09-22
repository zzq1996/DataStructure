//
// Created by zhang zhiqiang on 2021/9/22.
//

#ifndef DATASTRUCTURE_BINARYSEARCHTREE_H
#define DATASTRUCTURE_BINARYSEARCHTREE_H

//BST结点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}*BSTree;


//查找关键值为key的结点(非递归实现)，最坏空间复杂度O(1)
BSTNode *BST_Search1(BSTree T,int key){

    while (T!= nullptr && key!=T->key){//若树空或等于根结点值，则结束循环

        if(key<T->key){ //小于，在左子树查找
            T=T->lchild;

        }else{ //大于，在右子树查找
            T=T->rchild;
        }
    }
    return T;
}


//查找关键值为key的结点(递归实现)，最坏空间复杂度O(h)
BSTNode *BST_Search2(BSTree T,int key){

    if(T== nullptr){
        return nullptr;//查找失败
    }

    if(key==T->key){
        return T;//查找成功

    }else if(key<T->key){
        return BST_Search2(T->rchild,key);//在左子树中找

    }else{
        BST_Search2(T->rchild,key);//在右子树中找
    }

}






//在BST插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T,int k){

    if(T== nullptr){ //原树为空，新插入的结点为根结点

        T=(BSTree)malloc(sizeof (BSTNode));
        T->key=k;
        T->lchild=T->rchild= nullptr;
        return 1;//返回1，插入成功

    }else if(k==T->key){ //树中存在相同关键字的结点，插入失败
        return 0;

    }else if(k<T->key){//插入到左子树
        return BST_Insert(T->lchild,k);

    }else{//插入到右子树
        return BST_Insert(T->rchild,k);
    }
}


/*按照str[]中的关键字序列构造BST
 * ————不同的关键字序列得到的BST可能相同，也可能不同*/
void Create_BST(BSTree &T,int str[],int n){
    T= nullptr;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}




#endif //DATASTRUCTURE_BINARYSEARCHTREE_H
