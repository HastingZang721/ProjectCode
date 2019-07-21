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
 *数据流中的中位数
 * 数值可能会不断增加
 * 1：若是没有排序的数组中，则使用第39题的方法调用partition函数来查找
 * 2：若是在两个已排序的数组中查找中位数（见41——1.cpp）
 * 3:若是在排序的链表中使用两指针求中位数（见41-2。cpp）
 * 4:使用最大堆和最小堆来实现（见41-3。cpp）
 *
 */

//4:使用最大堆和最小堆来实现（见41-3。cpp）
//左边是大顶堆，右边是最小堆，当数据总数是偶数时，将新数据插入最小堆（为防止新插入的数据比最大堆中的某些数据小，
// 将新数据插入到最大堆，然后将最大堆中的最大数字拿出来插入最小堆）
//https://blog.csdn.net/my_lovely_lemon_tree/article/details/78007316

//
//void testHeap() {
//    vector<int> data{ 3,1,2,7,5 };
//    //构造堆，最大堆
//    make_heap(data.begin(), data.end(), less<int>());
//    for (int x : data)
//        cout << x << " ";
//    cout << endl;
//    //pop堆顶元素，最大的元素
//    pop_heap(data.begin(), data.end(), less<int>());
//    cout << data.back() << endl;//输出7
//    data.pop_back();
//    //往堆中添加元素
//    data.push_back(4);
//    push_heap(data.begin(), data.end(), less<int>());//调整堆
//    for (int x : data)
//        cout << x << " ";
//    cout << endl;
//    //排序
//    sort_heap(data.begin(), data.end(), less<int>());
//    for (int x : data)
//        cout << x << " ";
//    cout << endl;//输出 1，2，3，4，5
//}

template<class T>
class DynamicArray {
public:
    void Insert(T num)//插入元素，并且始终保证最大堆中所有数据都是小于最小堆的
    {
        if ((((min.size() + max.size()) & 1)) == 0)//总数是偶数的时候插入
        {
            if (max.size() > 0 && num < max[0])//插入的数比左边大顶堆中最大的数小，插入大顶堆中
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];//将左边最大值赋给num
                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();

            }
            min.push_back(num);//将最大值插入最小堆
            push_heap(min.begin(), min.end(), greater<T>());
        } else{//总数是奇数的时候
            if (min.size() > 0 && min[0] < num)
            {
                min.push_back(num);//先插入最小dui
                push_heap(min.begin(), min.end(), greater<T>());
                num = min[0];//将最小堆中的最小值
                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();


            }
            max.push_back(num);//插入大顶堆
            push_heap(max.begin(), max.end(), less<T>());

        }
    }



   T GetMIdian() {
        int size = min.size() + max.size();
        if (size == 0)
            cout<<"No numbers are available"<<endl;

        T median = 0;
        if ((size & 1) == 1)
            median = min[0];
        else
            median = (min[0] + max[0]) / 2;
        return median;


    }

private:
    vector<T> min;
    vector<T> max;
};

void Test(char *testname, DynamicArray<double> &number, double excepted) {
    if (testname != nullptr)
        cout << testname << "   begin :" << endl;
    if (abs(number.GetMIdian() - excepted) <= 0.000001)
        cout << "Passed";
    else
        cout << "failed";

}


int main() {
    //testHeap();
    DynamicArray<double> numbers;

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;

}
