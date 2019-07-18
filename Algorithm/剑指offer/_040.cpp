#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


#include <queue>

using namespace std;

/*
 * partition 函数的运用
 * 快排序
 * 最小的K个树
 *
 */

int partition(vector<int> &number, int begin, int end) {
    int pivot = number[begin];
    while (begin < end) {
        while (begin < end && pivot <= number[end])//从后往前找比关键字小的
        {
            end--;

        }
        number[begin] = number[end];

        while (begin < end && pivot >= number[begin]) {
            begin++;

        }
        number[end] = number[begin];//若找到比关键字pivot大的就移动到高端处

    }
    number[begin] = pivot;//基准归位

    return begin;


}

void QuickSort(vector<int> &number, int begin, int end) {
    if (begin < end) {
        int index = partition(number, begin, end);
        QuickSort(number, begin, index - 1);
        QuickSort(number, index + 1, end);

    }


}

void PrintMethod(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";

    }
    cout << endl;

}


void test1() {

    int num[] = {1, 22, 42, 13, 65, 7, 89, 4, 26, 10};
    vector<int> number(num, num + 10);
    cout << "Array before sort" << endl;

    PrintMethod(number);
    QuickSort(number, 0, number.size() - 1);
    cout << "sorted Array" << endl;
    PrintMethod(number);


}


void GetLeastNumber(vector<int>&input, int n, int *output, int k) {
    if (input.size()==0 || output == nullptr || k > n || n <= 0 || k <= 0)
        return;
    int start = 0;
    int end = n - 1;

    int index = partition(input, start, end);
    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
            index = partition(input, start, end);

        } else {
            start = index + 1;
            index = partition(input, start, end);

        }
    }
    for (int i = 0; i < k; ++i) {
        output[i] = input[i];

    }


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
    GetLeastNumber(data, n, output, k);
    cout<<"最小的K个树为："<<endl;
    for (int i = 0; i < k; i++) {
        cout <<output[i]<<" ";

    }
    cout<<endl;


}

int main() {
    // test1();
    test2(10,4);
    return 0;

}