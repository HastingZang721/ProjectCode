#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>

using namespace std;

/*
 *八皇后问题
 *
 * 假设采用八叉树来考虑
 * x[i]: 在i 行，皇后放在x[i]的位置
 * 不能在同一对角线：abs(j-k)!=abs(x[j]-x[k])
 *
 *
 */
#include<iostream>
#include<algorithm>
using namespace std;
int *x, num, sum;                                                  //x[]存储位置信息，num表示皇后数目，sum代表解的个数
bool place(int k)                                                  //放置第k个皇后时，对其位置考虑规则
{
    for (int j = 1; j < k; j++)
    {
        if (abs(x[j] - x[k]) == abs(j - k) || x[j] == x[k])
            return false;
    }
    return true;
}
void backtrack(int t)                                            //给第t层放置皇后，即放置第t个皇后
{
    if (t>num)                                                  //深度搜索结束
    {
        sum++;                                                 //每次成功加一次，表示解的个数
        for (int i = 1; i <= num; i++)
        {
            cout << "<" << i << "," << x[i] << ">"<<" ";      //输出每一层皇后的位置，i代表层数，x[i]表示位置
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            x[t] = i;    //第t个皇后的位置
            if (place(t))//根据规则判断这个位置是否可以放
                backtrack(t + 1);
        }
    }
}
int main()
{
    num = 8, sum = 0;
    x = new int[num+1];
    for (int i = 1; i <= num; i++)
    {
        x[i] = 0;
    }
    backtrack(1);
    cout << "the solution's num is: " << sum << endl;
    delete[]x;
}
