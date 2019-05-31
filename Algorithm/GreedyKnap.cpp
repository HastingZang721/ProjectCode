#include<iostream>
//小数背包问题《贪心算法》
//计算每种物品的单位重量价值作为贪心选择的依据指标，选择单位重量价值最高的物品，将尽可能多的该物品装入背包，依此策略一直地进行下去，直到背包装满为止
void GreedyKnap(n,c,w[],v[],x[])//x表述装入物品的比例
int i;
{
    sort(n,v,w);//使得v1/w1>v2/w2;
    for(i=1;i<n;i++)
        x[i]=0;
    //物品全部装入
    for( i=1;i<n;i++){
        if (w[i]>c) break;
        else
            x[i]=1;//全部装入
            c-=w[i];

    }
    //物品part装入
    if(i<n)
        x[i]=c/w[i];
    


}


