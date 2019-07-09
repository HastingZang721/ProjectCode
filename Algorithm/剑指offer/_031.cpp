#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


using namespace std;

/*
 * 棧的押入和弹出序列
 * 思路：
 * 辅助棧
 * 下一个弹出的数字应该刚好就是棧顶数字，否则直接将还没有入棧的数字进棧，
 * 直到把下一个需要弹出的数字押入棧中；
 * 若所有的数字都押入后仍没能找到下一个要弹出的数字，则不可能是一个弹出序列；
 *
 */

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV)
    {

        if(pushV.size( ) == 0 || popV.size( ) == 0)//入棧序列或者出棧序列为0
        {
            return false;
        }
        stack<int> s;
        int push, pop;

        s.push(pushV[0]);
        cout <<"push" <<pushV[0] <<endl;
        for(push=0,pop=0;push<pushV.size()&&pop<popV.size();)
        {
            if(s.empty()!=true&& s.top()==popV[pop])
            {//当前棧顶元素正好是出棧序列中的元素
                cout<<"pop"<<popV[pop]<<endl;

                s.pop();
                pop++;


            }
            else
                //若下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，
                // 直到把下一个需要弹出的数字压入栈顶为止。
            {
                s.push(pushV[++push]);
                cout<<"push"<<pushV[push]<<endl;


            }
        }
        if(s.empty()==true)//棧中元素都模拟出完了
        {
            return true;

        }
        else
        {
            return false;
        }



    }
};
int main( )
{
    int nPush[5] = {1,2,3,4,5};
    int nPop1[5] = {4,5,3,2,1};
    int nPop2[5] = {4,3,5,1,2};
    int nPop3[5] = {5,4,3,2,1};
    int nPop4[5] = {4,5,2,3,1};

    Solution solu;

    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop1, nPop1 + 5)) << endl;
//    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop2, nPop2 + 5)) << endl;
//    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop3, nPop3 + 5)) << endl;
//    cout <<solu.IsPopOrder(vector<int>(nPush, nPush + 5), vector<int>(nPop4, nPop4 + 5)) << endl;

    return 0;
