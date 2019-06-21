#include<iostream>

#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>
#include<set>
#include<map>
#include<utility>

//剪绳子
using namespace std;
//解法1 动态规划：找出最优子结构+重叠子问题
//f(n)=max(f(i)*f(n-i));
class Solution1{
public:
    int maxProductAfterCutting_solution1(int length)
    {
        if(length<2)
            return 0;
        if(length==2)
            return 1;

        if(length==3)
            return 2;

        int* products=new int[length+1];
        products[0]=0;
        products[1]=1;
        products[2]=2;
        products[3]=3;//至此说明length<=3的绳子 都不需要剪，（因为剪过还不如没剪）

        int max=0;
        for(int i=4;i<=length;++i)
        {
            max=0;
            for(int j=1;j<=i/2;j++) {//因为要计算f(j)乘以f(i-j)的最大值,j超过i的一半时是重复计算
                //所以只需要考虑j不超过i的一半的情况
                int product = products[j] * products[i - j];
                if (max < product){
                    max=product;

                }
                products[i]=max;//最终,更新表中的f(i)=max(f(j)·f(i-j))

            }
        }
        max=products[length];//循环结束后,所求的f(length)也就求出来了,并将其记录下来，以便销毁后能返回




        delete[] products;
        return max;



    }

};


//解法2 贪婪算法
class Solution2{
public:
    int maxProductAfterCutting_solution2(int length) {
        if (length < 2)
            return 0;
        if (length == 2)
            return 1;

        if (length == 3)
            return 2;

        int timeOf3=length/3;//尽可能的去剪去长度为3的绳子段；
        if(length-timeOf3*3==1)//当绳子最后剩下的长度为4的时候,不能再剪去长度为3的绳子段。
            //此时更好的方法是把绳子剪成长度为2的两段,因为2*2>3*1。
            timeOf3-=1;
        int timeOf2=(length-timeOf3*3)/2;//保证剩下的一定是4或者2或者0,计算一下能剪出几个2来(只有2/1/0三种情况)
        return (int)(pow(3,timeOf3))*(int)(pow(2,timeOf2));




    }

};

int main(){
//    Solution1 solu1;
//    cout<<"最大乘积为："<<solu1.maxProductAfterCutting_solution1(8)<<endl;
  Solution2 solu2;
  cout<<solu2.maxProductAfterCutting_solution2(8);





    return 0;

}
