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
#include <iomanip>


using namespace std;

/*
 * 字符流中第一个只出现一次的字符
 *
 * 思路：将字符的ASCII作为键值，字符对应的位置作为哈希表中的值
 * 若是第一次出现，则将位置保存到哈希表中，若改字符再次从字符流中读出时，则、
 *可以将其在哈希表中保存的值改为一个特殊的值（负数-2）
 */

class CharStatics{
public:

    CharStatics(int index, int *occurance) : index(0), occurance(-1) {}

    void Insert(char ch)
    {
        if(occurance[ch]==-1)//第一次访问到
            occurance[ch]=index;
        else if(occurance[ch]>0)
            occurance[ch]=-2;
        
        index++;
    }
    
    
    char FirstApperenceonce()
    {
        char ch='\0';
        int minIndex=numeric_limits<int >::max();
        for(int i=0;i<256;i++)
        {
            if(occurance[i]>=0&&occurance[i]<minIndex)
            {
                ch=(char)i;
                minIndex=occurance[i];
                
            }
        }
        return ch;
    }
private:
    int index;
int occurance[256];


};