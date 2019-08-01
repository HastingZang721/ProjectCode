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
#include <math.h>

#include <string>


using namespace std;

/*数字在在排序数组中出现的次数
 *
 */
//顺序查找的复杂度O（N），二分查找O（lgN）
class SOlution {
public:
    int GetFirstK(int *data, int length, int k, int start,int end) {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;
        int midData = data[mid];
        if (midData == k) {
            if ((mid > 0 && data[mid - 1] != k )|| mid == 0)//前一个数不是K，返回下标
                return mid;
            else
                end = mid - 1;

        }
        else if(mid>k)
             end=mid-1;
        else
            start=mid+1;

        return GetFirstK(data,length,k,start,end);

    }
    int GetLastK(int*data,int length,int k,int start, int end)
    {
        if(start>end)
            return -1;
        int mid = (start + end) / 2;
        int midData = data[mid];
        if (midData == k) {
            if ((mid <length-1 && data[mid + 1] != k) || mid ==length-1)//后一个数不是K，返回下标
                return mid;
            else
                start = mid + 1;//否则继续向后寻找
        } else if(midData<k)
            start=mid+1;
        else
            end=mid-1;
        return GetLastK(data,length,k,start,end);


    }

    int GetNUmofK(int *data,int length,int k)
    {
        int num=0;
        if(data!=NULL&&length>0)
        {
            int first=GetFirstK(data,length,k,0,length-1);
            int last=GetLastK(data,length,k,0,length-1);

            if(first>-1&&last>-1)
            {
                num=last-first+1;

            }
        }
        return num;
    }

};


int main(){
    SOlution silu;
    int data[10]={1,2,3,4,2,5,67,3,2,3};
    cout<<silu.GetNUmofK(data,10,2);
    return 0;


}