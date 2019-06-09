#include<iostream>
//最小生成树算法Minimum Spanning Tree


//加点法Prim：每次迭代选择代价最小的边所对应的点，加入最小生成树中；时间复杂度T = O( |V|2 ) 稠密图合算
//MST 最小生成树
void Prim)(){
    MST={s};//树中已有节点集合
    while(1){
        //dist 表示距离这棵树的距离，不相连的节点间权重为无穷大
        V=未收录节点中dist最小值;
        if(这样的节点V不存在)
            break;
        将V收录到MST,dist[v]=0;//dist=0表示已经被收录到树中；
        for(V中每一个连接点W)//收录到树中 会对该节点相邻节点的dist有影响
            if(W未被收录)
                if(E(V,W)<dist[W])
                {//更新W到树的最小距离
                    dist[W]=E[V,W];
                    parent[W]=V;

                }




    }
    if(MST 中收录的节点树不到【V】个)//图不联通
        printf("ERROR,生成树不存在！")


}

//加边法 Krustal
//初始化最小边为0，每次迭代选择一条满足条件的最小代价边
void Krustal(Graph G)

{
    MST={};//生成树中收集的边
    while(MST 中不到[V ]-1条边&& E 中还有边)
    {

        选择权值最小的边E[V,W]//最小堆 log（E）
        E -=E[V,W];//将E【V，W】从E中减去
        if(E[V,W]在MST不构成回路)/////并查集https://www.cnblogs.com/xzxl/p/7226557.html
            将E[V,W]加入MST;
        else
            彻底不要E[V,W]


    }
    if(MST 中不到[V]-1条边)
        printf("ERROR");
}


