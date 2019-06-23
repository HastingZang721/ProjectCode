#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>

using namespace std;

//求解二进制中1的个数
//解法一
//此解法可能会陷入死循环（当最高位是负数的情况下，每次右移仍要保证数字为负数，若一直做右移运算，最终数字会变成FFFFFFFF而陷入死循环）
class Solution1 {
public:
    int NumberOf(int n) {
        int count = 0;
        while (n) {
            if (n & 1 == 1)//如果n 与1做位运算 与" 结果为1 表示n 的最右边一位也是1；

                count++;
            n = n >> 1;//n 继续右移动一位；

        }
        return count;

    }
};


//解法2：每次将1左移，然后来与n做 与 运算；
//此算法中循环的次数等于整数二进制的位数
class SOlution2 {
public:
    int NumberOf2(int n) {
        int count = 0;
        unsigned int flag = 1;

        while (flag) {
            if (n & flag)
                count++;

            flag = flag << 1;

        }
        return count;

    }

};


class SOlution3{//将一个整数减去1，再和原整数做与运算，会把该整数的最右边1变成0；
    
public:
    int NumberOf3(int n)
    {
        int coount=0;
        while(n){
            count++;
            n=(n-1)&n;
            
            
        }
        return count;
        
                
    }
};

int main() {

//    Solution1 solu1;
//    cout<<solu1.NumberOf(9);

    SOlution2 solu2;
    cout<<solu2.NumberOf2(9);


    return 0;

}


//用一条语句判断一个整数是不是2的整数次方
//0==(n-1)&n



//输入两个整数m和n,计算需要改变m中二进制中的多少位才能得到n;
//int a;
//
//a=m^n;

//