#include<iostream>
//#include<stack>
#include<queue>

using namespace std;
//Fibonacci


class Solution{
public:


    long long Fibonacci(unsigned n);



private:
    long long minusone=0;
    long long minustwo=0;
    long long fibN;


};

long long Solution::Fibonacci(unsigned n) {
    if(n<2)
    {
        if(n==0)return 0;
        fibN=1;
        return fibN;


    }
    minusone=1;
    minustwo=0;
    fibN=0;
    for(unsigned i=2;i<=n;i++)
    {
        fibN=minustwo+minusone;
        minustwo=minusone;
        minusone=fibN;

    }
    return fibN;


}


int main(){
    int n=10;
    Solution solu;
    cout<<solu.Fibonacci(n);


}