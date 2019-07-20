include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>
#include <set>


#include<cstdlib>

#define  Random(x)(rand()%x)//预定义一个范围在100以内的随机函数
using namespace std;

/*
 *现有一个包含n个整数（1<=n<=10000000）的无序序列(保证序列内元素各不相同)，输入一个整数k（1<=k<=n）,请用较快的方式找出该序列的第k小数并输出。
 *
 * 解法有1：给数据排序(快排序)，然后找出第K个元素 时间复杂度o(nlgn)
 * 解法2：分治（运用partition ）然后判断第K个数是在左右那个区间，然后继续寻找(第40题)
 *
 */

//--------------------------------------------------------解法1
int partition(vector<int> &num, int start, int end) {
    int pivot = num[start];
    while (start < end) {
        while (start < end && num[end] >= pivot) {
            end--;

        }
        num[start] = num[end];
        while (start < end && num[start] <= pivot) {
            start++;

        }
        num[end] = num[start];

    }
    num[start] = pivot;//gui wei
    return start;

}

void QuickSort(vector<int> &num, int left, int right) {
    if (left < right) {
        int index = partition(num, left, right);
        QuickSort(num, left, index - 1);
        QuickSort(num, index + 1, right);
    }
}

void PrintMethod(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

}


void test1(int k) {//调用快排序
    const int N = 20;
    int arr[N];
    for (int i = 0; i < N; i++) {

        arr[i] = Random(100);

    }
    vector<int> data(arr, arr + N);
    cout << "原先的数组为" << endl;
    PrintMethod(data);
    QuickSort(data, 0, data.size() - 1);
    cout << "排序后的数组" << endl;
    PrintMethod(data);
    cout << " 第K个小的数是  " << data[k - 1] << endl;


}

void test2(int k)//使用vector自带的sort算法
{
    const int N = 20;
    int arr[N];
    for (int i = 0; i < N; i++) {

        arr[i] = Random(100);

    }
    vector<int> data(arr, arr + N);
    cout << "原先的数组为" << endl;
    PrintMethod(data);
    //QuickSort(data,0,data.size()-1);
    sort(data.begin(), data.end());
    cout << "使用STL的sort算法排序后的数组" << endl;
    PrintMethod(data);
    cout << " 第K个小的数是  " << data[k - 1] << endl;

}

//解法2--------------------------------------------
int FindKth(vector<int> &v, int start, int end, int k) {
    int index = partition(v, start, end);
    if (k - 1 == index)
        return v[index];
    else if (k - 1 < index)
    {
        FindKth(v, start, index - 1, k);

    }
    else
    {
        FindKth(v, index + 1, end, k);
    }


}

void test3(int k) {
    const int N = 20;
    int arr[N];
    for (int i = 0; i < N; i++) {

        arr[i] = Random(100);

    }
    vector<int> data(arr, arr + N);
    cout << "原先的数组为" << endl;
    PrintMethod(data);


    cout << " 第K个小的数是  " <<  FindKth(data,0,data.size()-1,k)<< endl;




}

int main() {
    //test1(5);
    //test2(5);
   test3(5);

    return 0;

}
