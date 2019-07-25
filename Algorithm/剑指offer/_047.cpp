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


//#include <sstream>

using namespace std;

/*
 礼物的最大价值

 动态规划


f(i，j)= max{f(i-1,j),f(i,j-1)}+gitf[i,j],

 是从上到下递归地分析；而求解过程是从下到上循环地求解。
 */

//value 数组存储的是格子里的礼物价值

class SOlution1 {
public:
    int GetMaxValue(const int *value, int rows, int cols) {
        if (value == nullptr || rows <= 0 || cols <= 0)
            return 0;
        int *maxValues = new int[cols];//创建列数相同的一维向量即可
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)//列
            {
                int left = 0;
                int up = 0;

                if (i > 0)
                    up = maxValues[j];//同列
                if (j > 0)
                    left = maxValues[j - 1];//同行，

                maxValues[j] = std::max(left, up) + value[i * cols + j];

            }
        }
        int MaxValue = maxValues[cols - 1];

        delete[] maxValues;
        return MaxValue;
    }


};

int main() {
    int a[][4] = {{1,  10, 3,  8},
                  {12, 2,  9,  6},
                  {5,  7,  4,  11},
                  {3,  7,  16, 5}
    };
    SOlution1 solu;
    cout << solu.GetMaxValue((const int*)a, 4, 4);
    return 0;
}

