/*
//#include <cstdio>
//#include <iostream>
//#include<vector>
//
//二维数组中的查找
//// 参数:
////numbers[][] 数组
////key 待查找的数字
//using namespace std;
//bool find(vector<vector<int>> numbers,int key)
//{
//    int row=0,col=0,t=0;
//    bool flag=false;
//
//    for(int i=0;i<numbers.size();++i)
//    {
//        for(int j=0;j<numbers[i].size();++j)
//        {
//            if(false==flag&&key==numbers[i][j])
//            {
//                flag==true;//已经找到
//
//            }
//        }
//    }
//
//    return flag;
//
//
//
//}
//int main(){
//    int mRow=4;
//    int nCol=4;
//    vector<vector<int >>array(mRow);//初始化M*N的二维数组
//    for(int i;i<mRow;i++){
//        array[i].resize(nCol);//nCol列
//    }
//    array[0]={1,2,8,9};
//    array[1]={2,4,9,12};
//    array[2]={4,7,10,13};
//    array[3]={6,8,11,15};
//    cout<<("%d",find(array,13));


}*/
#include<cstdio>
#include<iostream>


//////////////////////second solution /////////////
bool Find(int* matrix, int row, int col, int key) {
    bool found = false;
    if (matrix != nullptr && row > 0 && col > 0) {
        int r = 0;
        int c = col - 1;
        while (r < row && c >= 0) {
            if(matrix[r*col+c]==key)
            {
                found =true;
                break;//找到 退出

            }
            else if (matrix[r*col+c]>key)
                --c;
            else
                ++r;


        }


    }
    return found;


}


//测试代码
void Test(char* testName,int* matrix,int row,int col,int key,bool excepted)
{
    if(testName != nullptr)
        printf("%s start:",testName);
    bool result=Find(matrix,row,col,key);
    if (result == excepted)
        printf("Passed.\n");
    else
        printf("Failed.\n");


}

void test1()
//要找的数字在数组中
{
    int matrix[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Test("test1",(int*) matrix,4,4,13,true);

}


void test2()
//要找的数字不在数组中
{
    int matrix[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    Test("test2",(int*) matrix,4,4,19,true);

}
int main(int argc,char* argv[])

{
    //test1();
    test2();

    return 0;
}





































