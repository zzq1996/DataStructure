#include <iostream>
#include "chapter5/BInaryTree.h"
#include "chapter3/SeqQueue.h"

using namespace std;

int main() {
    BiTree biTree;
    cout<<"输入结点数据，'#'表示结点为空:"<<endl;
    CreateBiTree(biTree);
    cout<<"先序遍历：";
    PreOrder(biTree);

    cout<<"中序遍历：";
    InOrder(biTree);

    cout<<"后序遍历：";
    PostOrder(biTree);
    return 0;
}
