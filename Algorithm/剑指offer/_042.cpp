#include<iostream>
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
//解法一：暴力傻瓜解法，遍历每一个A【i】为根节点的数字，以其为根节点来计算,时间复杂度o（n3）
int FindGreatestSumOfSubArray1(int *arr,int nlength)
{
    int sum=1<<31;//极小值
    for(int i=0;i<nlength;i++)
    {
        for(int j=0;j<nlength;j++)
        {
            int cursum=0;
            for(int k=i;k<j;k++)
            {
                cursum+=arr[k];
            }
            if(cursum>sum)
            {
                sum=cursum;
            }
        }
    }
    return sum;

}





//解法2 在以上方法改进：sum[i,j]=sum[i,j-1]+a[j]
int FindGreatestSunOfSUbArray2(int * arr,int nlength)
{
    int sum=1<<31;
    for(int i=0;i<nlength;i++)
    {
        int cursum=0;
        {
            for(int j=i;j<nlength;j++)
            {
                cursum+=arr[j];
                if(cursum>sum)
                {
                    sum=cursum;

                }

            }

        }
    }
    return  sum;

}


//解法三 动态规划
/*
 * 当以第(i-1)个数字为结尾的子数组中所有数字的和f(i-1)小于0时，如果把这个负数和第i个数相加，得到的结果反而不第i个数本身还要小，
 * 所以这种情况下最大子数组和是第i个数本身。

如果以第(i-1)个数字为结尾的子数组中所有数字的和f(i-1)大于0，与第i个数累加就得到了以第i个数结尾的子数组中所有数字的和
 */

//max( dp[ i ] ) = getMax( max( dp[ i -1 ] ) + arr[ i ] ,arr[ i ] )

int GetGreatestSubarray(int *arr,int nlength)
{
    if(nlength<=0||arr==NULL)
        return 0;
    int Maxsum=arr[0];//存放比较后的最大值
    int cursum=arr[0];//比较临时的最大值
    for(int i=0;i<nlength;i++)
    {
        cursum=(cursum+arr[i])>arr[i]?(cursum+arr[i]):arr[i];//判断出max( dp[ i -1 ] ) + arr[ i ] ,arr[ i ]的最大值
        if(cursum>Maxsum)
        {
            Maxsum=cursum;
        }
    }
    return Maxsum;
}







int main(){
    int a[]={1,-2,3,10,-4,7,2,-5};

   // cout<<FindGreatestSumOfSubArray1(a,8);
   //cout<<FindGreatestSunOfSUbArray2(a,8);
   cout<<GetGreatestSubarray(a,8);
    return 0;

}
