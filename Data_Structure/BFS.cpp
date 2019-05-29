#include<iostream>
#include <Vector>
Queue<char> q;//创建一个队列，用来存放每一层的顶点
#define Maxnum=100;
bool visited[Maxnum];//visited数组，用来记录已被访问过的顶点



typedef struct Graph{
    char vexs[Maxnum];//顶点表
    int arcs[Maxnum][Maxnum];//邻接矩阵
    int vexnum,arcnum//顶点数，边数；
}AMGraph;


int locateVex(AMGraph &G,char v){//找到顶点的相应下标
    int i;
    for(i=0;i<G.vexnum;i++)
        if(G.vexs[i]==v)
            return v;

}

//)队头顶点u出队。

//(2)依次检查u的所有邻接顶点w，若visited[w]的值为false，则访问w，并将visited[w]置为true，
// 同时将w入队。
void BFS（AMGraph &G,char v0）{//从V0开始的广度优先遍历
    int u,i,v,w;
    v=locateVex(G,v0);
    printf("%c",v0);//找到v0对应下标并打印
    visited[v0]=1;//标记为已访问
    q.push(v0);
    while(!q.empty()){
        u=q.front();//将队头元素u出队，并且访问u所有领结点；
        v=locateVex(G,u)//打印u 对应的下标；
        q.pop();
        for(i=0;i<G.vexnum;i++){
            w=G.vexs[i];//下标i对应的顶点是W
            if(G.arcs[v][i])&&!visited[i])//w和u之间有边，且w未被访问
             {
                     printf("%c",w);
                     q.push(w)；//w入队
                     visited[i]=1;//顶点W已被访问

             }

        }
    }



};