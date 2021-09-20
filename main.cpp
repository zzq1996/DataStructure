#include <iostream>
#include "chapter5-Tree/BInaryTree.h"

using namespace std;

int main() {

    BiTree tree;
    cout<<"输入结点（#表示为空），构造二叉树："<<endl;
    CreateBiTree(tree);
    cout<<"中序遍历序列：";
    InOrder(tree);

    return 0;
}
