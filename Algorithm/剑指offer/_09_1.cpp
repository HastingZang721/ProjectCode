#include<iostream>
//#include<stack>
#include<queue>

using namespace std;

//两个队列来表示一个棧
template <typename T> class CStack{
public:
    CStack();
    ~CStack();

    void appendTail(const T& node);
    T deletHead();


private:
    queue<T>q1;
    queue<T>q2;



};
template<typename T> CStack<T>::CStack()
{
}

template<typename T>  CStack<T>::~CStack()
{
}

template<typename T> void CStack<T>::appendTail(const T& node){
    //实现尾部插入；
    if(!q1.empty())
        q1.push(node);

    else
        q2.push(node);


}
//T CStack<T>::deleteHead()
template <class T>T CStack<T>::deletHead() {//模拟棧后进先出
    int ret=0;//用来表示将删除的节点

    if(!q1.empty())
    {
        int num=q1.size();
        while(num>1)//最后要删除的ret节点将直接弹出
        {
            q2.push(q1.front());
            q1.pop();
            --num;

        }
        ret=q1.front();
        q1.pop();



    }//q1为空，q2是有的
    else{
        int num=q2.size();
        while(num>1)
        {
            q1.push(q2.front());
            q2.pop();
            --num;

        }
        ret =q2.front();
        q2.pop();

    }
    return ret;



}


void test(char actual,char excepted)
{
    if(actual ==excepted)
        cout<<"Test Passed"<<endl;
    else
        cout<<"Test Failed"<<endl;
}

int main()
{
    CStack<char> cs ;
    cs.appendTail('a');
    cs.appendTail('b');
    cs.appendTail('c');
    int node;

    char head=cs.deletHead();
    test(head,'c');

    return 0;

}
