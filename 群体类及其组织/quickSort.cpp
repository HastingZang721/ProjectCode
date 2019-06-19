#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

//STL
//standard Template library
//数据结构与算法分离
//容器：序列 关联
//迭代器： 相当于指针，实际上迭代器是一个类，封装成一个指针
//算法：通过有限的步骤解决问题
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
template <typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)、"大於"(>)、"不小於"(>=)的運算子功能
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}
int main(){
    int n=10;
    int a[10]={1,12,23,41,5,2,6,4,78,3};
    quick_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}