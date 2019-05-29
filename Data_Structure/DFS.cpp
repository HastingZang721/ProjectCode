#include<iostream>
#include <Vector>

stack<char*>s;

#define Maxnum=100;
bool visited[Maxnum];//visited数组，用来记录已被访问过的顶点



typedef struct Graph{
    char vexs[Maxnum];//顶点表
    int arcs[Maxnum][Maxnum];//邻接矩阵
    int vexnum,arcnum//顶点数，边数；
}AMGraph;




void DFS(AMGraph &G,int v)
{
    int w;
    printf("%c",G.vexs[v]);
    visited[v]=1;//访问顶点V，算法之前visited【v】=0;
    for(w=0;w<G.vexnum;w++)
        if(G.arcs[v][w]&&!visited[w])
            DFS(G,w);


}


//非递归DFS


void DFS(Vertex v)
{
    visited[v]=1;
    push(s,v);
    while(!s.empty()){
        vertex w=s.pop();
        for(each u in vexs[] and G.arcs[u][w])    //访问指定的起始顶点；若当前访问的顶点的邻接顶点有未被访问的，则任选一个访问之
            //反之，退回到最近访问过的顶点；直到与起始顶点相通的全部顶点都访问完毕
        {
            if (!visited[u])
            {
                push(s,u);
                visited[u]=1;

            }
        }

    }
}