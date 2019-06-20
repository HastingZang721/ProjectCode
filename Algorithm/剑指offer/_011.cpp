#include<iostream>
#include<stdio.h>
#include<cstdio>
#include <cstring>
#include<vector>
#include<iterator>
#include<algorithm>
#include<exception>
#include<stack>

using namespace std;

//回溯法
bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char*str,int & pathLength,bool* visited);
bool hasPath(const char* matrix,int rows,int cols,const char* str)
{
    if(matrix==nullptr||rows<1||cols<1||str== nullptr)
        return false;
    bool *visited=new bool[rows*cols];//因为路径不能重复的进入矩阵的格子，所以还需要定义和
                           //字符矩阵同样大小的bool matrix
     memset(visited,0,rows*cols);//将矩阵所有元素设置为0
     int pathLength=0;
     for(int row=0;row<rows;++row)
     {
         for(int col=0;col<cols;++col)
         {
             if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
             {
                 return true;

             }
         }
     }
     delete[] visited;
     return false;


}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char*str,int & pathLength,bool* visited)
{
    if(str[pathLength]=='\0')//此时所有字符都在矩阵中找到合适的位置
        return true;
    bool hasPath=false;
    if(row>=0&&row<rows&&col>=0&&col<cols&&matrix[row*cols+col]==str[pathLength]&&!visited[row*cols+col])
    {
        ++pathLength;
        visited[row*cols+col]=true;

        hasPath=hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||
                hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)||
                hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)||
                hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
        if(!hasPath)
        {
            --pathLength;
            visited[row*cols+col]=false;

        }

    }
    return hasPath;


}

void test(const char* testname,const char* matrix,int rows,int cols,const char* str,bool expected)
{
    if(testname!= nullptr)
        printf("%s begin:",testname);
    if(hasPath(matrix,rows,cols,str)==expected)
        printf("passed");
    else
        printf("Failed");

}
void test1(){
    const char* matrix="ABCDEFGHIJKL";
    const char* str="BFGK";
    test("test1",(const char*)matrix,3,4,str,true);

}
















int main(){

    test1();


    return 0;

}













