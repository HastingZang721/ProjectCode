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


#include<cstdlib>

#define Random(x) rand()%x

#include <time.h>

using namespace std;

/*
 *数据流中的中位数
 * 数值可能会不断增加
 * 1：若是没有排序的数组中，则使用第39题的方法调用partition函数来查找
 * 2：若是在两个已排序的数组中查找中位数（见41——1.cpp）
 * 3:若是在排序的链表中使用两指针求中位数（见41-2。cpp）
 * 4:使用最大堆和最小堆来实现（见41-3。cpp）
 *
 */

/*
 * 求两个排序数组的中位数

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。
 */

//----------------------------------------------------------解法1：将两数组合并后查询中位数
//算法的时间复杂度较大  不合适



void PrintMethod(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";

    }
    cout << endl;
}


double FindMiddleNumArray(vector<int> &v1, vector<int> &v2) {
    vector<int> num;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size())//二路归并将两数组合并到一个」
    {
        if (v1[i] < v2[j]) {
            num.push_back(v1[i++]);

        } else {
            num.push_back(v2[j++]);

        }
    }
    if (i == v1.size()) {
        while (j < v2.size()) {
            num.push_back(v2[j++]);

        }
    }
    if (j == v2.size()) {
        while (i < v1.size()) {
            num.push_back(v1[i++]);
        }
    }


    //PrintMethod(num);


    if (num.size() % 2 == 1)//num 数组数字是奇数
    {
        return double(num[num.size() / 2]);
    } else {
        return double(num[num.size() / 2] + num[num.size() / 2 - 1]) / 2;
    }

}

void test1() {
    int arr1[] = {1, 3, 4, 6, 8, 9};
    int arr2[] = {0, 2, 7, 10, 22, 24, 26};
    vector<int> v1(arr1, arr1 + 6);
    vector<int> v2(arr2, arr2 + 7);
    PrintMethod(v1);
    PrintMethod(v2);
    cout << " 中位数 " << FindMiddleNumArray(v1, v2) << endl;
}



//===============================================解法2: 在两个未合并的数组中使用二分法
/*
 *
这里我们需要定义一个函数来找到第K个元素，下面重点来看如何实现找到第K个元素，首先我们需要让数组1的长度小于或等于数组2的长度，那么我们只需判断如果数组1的长度大于数组2的长度的话，交换两个数组即可，
 然后我们要判断小的数组是否为空，为空的话，直接在另一个数组找第K个即可。还有一种情况是当K = 1时，表示我们要找第一个元素，只要比较两个数组的第一个元素，返回较小的那个即可。

首先假设数组A和B的元素个数都大于k/2，我们比较A[k/2-1]和B[k/2-1]两个元素，这两个元素分别表示A的第k/2小的元素和B的第k/2小的元素。这两个元素比较共有三种情况：>、<和=。
 如果A[k/2-1]小于B[k/2-1]，则A[k/2-1]小于合并之后的第k小值。
当A[k / 2 - 1] = B[k / 2 -1]时，表示，在在A的k/2 -1之前已经有k/2 -1和数小于A[k / 2 -1]，同理在B 之前也是一样的，所以此时已经找到了第k小的数，即这个相等的元素。
 *
 */
double findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
    // 首先需要让数组1的长度小于或等于数组2的长度
    if (nums1.size() - i > nums2.size() - j) {
        return findKth(nums2, j, nums1, i, k);
    }
    // 判断小的数组是否为空，为空的话，直接在另一个数组找第K个即可
    if (nums1.size() == i) {
        return nums2[j + k - 1];
    }
    // 当K = 1时，表示我们要找第一个元素，只要比较两个数组的第一个元素，返回较小的那个即可
    if (k == 1) {
        return min(nums1[i], nums2[j]);
    }
    int pa = min(i + k / 2, int(nums1.size())), pb = j + k - pa + i;

    if (nums1[pa - 1] < nums2[pb - 1]) {
        return findKth(nums1, pa, nums2, j, k - pa + i);//num1 的分界线及其前面的值都小于K值，所以从Pa开始重新找k-(pa-i)
    } else if (nums1[pa - 1] > nums2[pb - 1]) {
        return findKth(nums1, i, nums2, pb, k - pb + j);
    } else {
        return nums1[pa - 1];
    }
}

double findMedianSortedArrays(vector<int> A, vector<int> B) {
    int sizeA = A.size(), sizeB = B.size();
    if (sizeA <= 0 && sizeB <= 0) {
        return 0;
    }
    int total = sizeA + sizeB;
    if (total % 2 == 1) {
        return findKth(A, 0, B, 0, total / 2 + 1);
    } else {
        return (findKth(A, 0, B, 0, total / 2) + findKth(A, 0, B, 0, total / 2 + 1)) / 2;
    }
}

void test2(){
    int arr1[] = {1, 3, 4, 6, 8, 9};
    int arr2[] = {0, 2, 7, 10, 22, 24, 26};
    vector<int> v1(arr1, arr1 + 6);
    vector<int> v2(arr2, arr2 + 7);
    PrintMethod(v1);
    PrintMethod(v2);
    cout<<"中位数是："<<findMedianSortedArrays(v1,v2)<<endl;

}

int main() {

    clock_t start, finish;
    start = clock();

    test1();
    //test2();//90


    finish = clock();


    cout << (double) (finish - start) << endl;
    return 0;
}

