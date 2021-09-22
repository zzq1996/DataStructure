//
// Created by zhang zhiqiang on 2021/9/22.
//

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#define MaxVertexNum = 100;//顶点数目的最大值

/*邻接矩阵表示法（数组实现的顺序存储，空间复杂度高）
 * ————适合稠密图
 * 对无权图：对角线为0，若有边/弧为1
 * 对带权图：对角线/不可达（没有边/弧）为无穷，有边/弧为权值
 * */
typedef struct {
    char Vex[MaxVertexNum];//顶点表
    int Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum,arcnum;//图的当前顶点数和边数/弧数
}Graph;


/*邻接表法（顺序+链式存储）
 *————表示不唯一
 *
 * */

//边
typedef  struct {
    int adjvex; //边/弧指向哪条边
    struct ArcNode *next; //指向下一条弧的指针
//    InfoType info; //边权值
}ArcNode;

//顶点
typedef struct {
    char data; //顶点信息
    ArcNode *first; //第一条边/弧
}VNode,AdjList[MaxVertexNum];

//邻接表法
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;



bool visited[MaxVertexNum]; //访问标记数组，初始都为false


/*广度优先遍历BFS（Breadth-First-Search）
 * 1、找到与一个顶点相邻的所有顶点
 * 2、标记哪些顶点被访问过
 * 3、需要一个辅助队列和标记数组
 *
 * FirstNeighbor(G,v) ：返回顶点v的第一个邻接点，没有返回-1
 * NextNeighbor(G,v,w)：返回除w外x的邻接点，没有返回-1
 *
 * 对于无向图，调用BFS函数的次数=连通分量数
 * */


//对图G进行广度优先遍历
void BFSTraverse(Graph G){

    for ( i = 0; i <G.vexnum ; ++i) {//访问标记数组初始化
        visited[i]= false;
    }

    InitQueue(Q);//初始化辅助队列Q

    for (i = 0; i <G.vexnum ; ++i) { //从0号顶点开始遍历

        if(!visited[i]){ //对每个连通分量调用一次BFS

            BFS(G,i);//Vi未被访问，从Vi开始BFS

        }

    }
}

//从顶点v出发，广度优先遍历图G
void BFS (Graph G,int v){

    visit(v);//访问初始顶点v

    visited[v]= true;//对v做已访问标记

    Enqueue(Q,v);//顶点v入队列Q

    while (!isEmpty(Q)){

        DeQueue(Q,v);//顶点v出队列Q

        for (w =FirstNeighbor(G,v) ; w>=0 ; w=NextNeighbor(G,v,w)) {//检测V的所有邻接顶点

            if(!visited[w]){//w为v尚未访问的邻接顶点

                visit[w];//访问顶点w
                visited[w]= true;//对w做已访问标记
                EnQueue(Q,w);//顶点w入队列

            }

        }
    }


}


/*深度优先遍历
 * 需要一个标记数组和函数调用栈
 *
 *空间复杂度来自函数调用栈，最坏为O(v)
 *
 * */

//对图G进行深度优先遍历
void DFSTraverse(Graph G){

    //初始化标记数组为false
    for(int v=0;v<G.vexnum;++v){
        visited[v]= false;
    }

    //从v=0开始遍历
    for (int v = 0; v < G.vexnum; ++v) {
        if(!visited[v]){
            DFS(G,v);
        }
    }
}

//从顶点v出发，深度优先遍历图G
void DFS(Graph G,int V){

    visit(v);

    visited[v]= true;

    for(w =FirstNeighbor(G,v) ; w>=0 ; w=NextNeighbor(G,v,w)){

        if(!visited[w]){//w为u的尚未访问的邻接顶点

            DFS(G,w);

        }

    }
}


















#endif //DATASTRUCTURE_GRAPH_H
