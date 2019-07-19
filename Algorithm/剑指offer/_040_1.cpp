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
 * STL multiset 红黑树大顶堆
 * 最小的K个树
 *
 */


typedef multiset<int ,std::greater<int>>  inSet;
typedef multiset<int ,std::greater<int>>:: iterator  setIterator;

void GetLeastNumbers_solution2(const vector<int>& data,inSet& leastNumbers,int k)
{
    leastNumbers.clear();
    if(k<1||data.size()<k)
        return ;
    vector<int >::const_iterator iter=data.begin();
    for(;iter!=data.end();++iter)
    {
        if(leastNumbers.size()<k)
            leastNumbers.insert(*iter);

        else
        {
            setIterator iterGreatest=leastNumbers.begin();

            if(*iter<*(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);

            }
        }
    }
}



void PrintMethod(vector<int>&v){
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";

    }
    cout<<endl;

}


void test2(int n, int k) {
    if (k > n)
        return;
   // Solution1_GetLeastNumbers solu1;
    int num[] = {1, 22, 42, 13, 65, 7, 89, 4, 26, 10};

    vector<int> data(num, num + 10);
    PrintMethod(data);
    cout<<"原先的数组为："<<endl;

    int *output = new int[k];
    //GetLeastNumber(data, n, output, k);
    inSet leastNumbers;
    GetLeastNumbers_solution2(data,leastNumbers,k);
    cout<<"最小的K个树为："<<endl;
    for(setIterator iter=leastNumbers.begin();iter!=leastNumbers.end();iter++)
    {
        cout<<*iter<<" ";

    }
    cout<<endl;
    delete[] output;



}

int main() {
    // test1();
    test2(10,4);
    return 0;

}