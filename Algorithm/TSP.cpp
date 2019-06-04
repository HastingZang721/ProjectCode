#include<iostream>

using namespace std;
#define n 4;

//Travelling Salesman Problem
//中国邮递员问题（Chinese Postman Problem CPP）
//算法思路（贪心）：用数字标好城市，任何两个城市的距离记录在数组D[i,j];
//依次被访问过的城市被记录在S[1,2,..N]中，即第i次被访问的城市记录在s[i];
//初始：将城市1 的编号赋值给s[1]/;
//第i 次访问的城市为j,其距离i-1次被访问的城市距离最短

int main() {
    int i,j, k, l;//k是未访问的城市节点
    int s[n];//
    int D[n][n];
    int sum;//记录已访问城市的最小距离；
    int Dtemp;//设置为一个很大的数
    int flag;//访问过设置为1
    i = 1;
    s[0] = 0;
    D[0][1] = 2;
    D[0][2] = 6;
    D[0][3] = 5;
    D[1][0] = 2;
    D[1][2] = 4;
    D[1][3] = 4;
    D[2][0] = 6;
    D[2][1] = 4;
    D[2][3] = 2;
    D[3][0] = 5;
    D[3][1] = 4;
    D[3][2] = 2;


    do{
        k=1;Dtemp=1000;
        do{
            l=0;flag=0;
            do{
                if(s[l]==k){//判断该城市是否被访问过
                    flag=1;
                    break;

                } else
                    l++;


            }while(l<i)
                if(flag==0&&D[k]s[[i-1]]<Dtemp)
                    j=k;
                Dtemp=D[k][s[i-1]]//此时Dtemp暂存当前最小路径的值
        }k++;
        while(k<n);
        s[i]=j;
        i++;
        sum+=Dtemp;


    }while (i<n);
    sum+=D[0][j]
            for(j=0;j<n;j++)//输出经过城市的路径
                cout<<s[j]<<"";



}
cout<<sum;






