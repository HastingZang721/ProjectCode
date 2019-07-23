nclude<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>
#include <set>


using namespace std;

/*
 *求数组中连续子数组的最大值
 *
 */
int NUmberOf1(int n) {
    int num = 0;
   while(n)
    {
        if(n%10==1)
        {
            num++;
        }
        n=n/10;
    }
    return num;


}

int NUmberOf1Between1andN(unsigned int n)
{
    int numbers=0;
    for(unsigned int i=0;i<=n;i++)
    {
        numbers+=NUmberOf1(i);

    }
    return  numbers;

}

int main(){

    cout<<NUmberOf1Between1andN(12);
    return 0;

}