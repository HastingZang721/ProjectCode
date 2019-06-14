#include<iostream>
#include<stack>
using namespace std;


//s1作为输入棧 ，s2作为输出棧
class Solution{
public:
    void CQueueInsert(int node)//模拟入队
    {
        s1.push( node);
    }
    int CQueueRemove(){//模拟出队
        int node=-1;
        if(this->empty()==true)
        {cout<<"整个队列为空"<<endl;
            return -1;
        }
        else
        {
            //情况1）：s2 空 ，s1 不为空
            //情况2）：s2=非空，直接弹出即可
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    node=s1.top();
                    s1.pop();
                    s2.push(node);
                    cout<<node<<"从S1传递到S2"<<endl;


                }

            }
            node=s2.top();
            s2.pop();
            cout<<"队头元素为："<<node<<endl;

        }
        return node;


    }
    bool empty(){
        return (s1.empty()==true&&s2.empty()==true);

    }
private:
    std::stack<int >s1;
    std::stack<int >s2;
};



int main(){
    Solution solu;
    solu.CQueueInsert(1);
    solu.CQueueInsert(2);
    solu.CQueueInsert(3);
    int node;
    while(solu.empty()!=true)
    {
        cout<<solu.CQueueRemove()<<"  ";
    }
    return 0;
}
