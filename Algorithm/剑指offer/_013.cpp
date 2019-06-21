#include<iostream>

#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

#include<cmath>
#include<set>
#include<map>
#include<utility>

//同面试题12类似
using namespace std;

int movingCount(int threshold,int rows,int cols);
int movingCOuntCore(int threshold,int rows,int cols,int row,int col,bool *visited);
bool check(int threshold,int rows,int cols,int row,int col,bool* visited);
int getDigitSum(int number);



int movingCount(int threshold,int rows,int cols)
{
    if(threshold<0||rows<0||cols<0)
        return 0;
    bool *visited=new bool[rows*cols];//路径不能走入重复的节点，所以生成与方格大小一样的标记方格

    for(int i=0;i<rows;i++)
    {

        visited[i]=false;//先将节点设置为未访问
    }
    int count=movingCOuntCore(threshold,rows,cols,0,0,visited);//从00 开始移动
    delete[] visited;
    return count;

}

int movingCOuntCore(int threshold,int rows,int cols,int row,int col,bool *visited)
{
    int count=0;
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col]=true;
        count=1+movingCOuntCore(threshold,rows,cols,row-1,col,visited)
                +movingCOuntCore(threshold,rows,cols,row,col-1,visited)
                +movingCOuntCore(threshold,rows,cols,row+1,col,visited)
                +movingCOuntCore(threshold,rows,cols,row,col+1,visited);


    }//用来判断是否能进入四个相邻的格子

    return count;

}

bool check(int threshold,int rows,int cols,int row,int col,bool * visited)
{
    if(row>=0&&row<rows&&col>=0&&col<cols&&getDigitSum(col)+getDigitSum(row)<=threshold&&!visited[row*cols+col])
        return true;
    else
        return false;

}





int getDigitSum(int number){//计算数位和
    int sum=0;
    while(number>0)
    {
        sum+=number%10;
        sum/=10;

    }
    return sum;


}


void test(char* testname,int threshold,int rows,int cols,int  expected){
    if(testname!= nullptr)
        cout<<testname<<" ";
    if(movingCount(threshold,rows,cols)==expected)
        cout<<"passed"<<endl;
    else
        cout<<"Failde"<<endl;




}


void test1(){
    //movingCount(18,10,10);
    test("test1",18,6,6,21);

}

int main(){

    test1();

    return 0;

}


