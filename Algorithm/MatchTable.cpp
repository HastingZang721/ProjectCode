//循环赛日程安排《分治法》
//在2^k的个选手的比赛日程是在2^k-1的基础上迭代
#include<math.h>
#include <iostream>

using namespace std;
void MatchTable(int k,int n,int **table);//声明



int mian()
{
    int n=0,k=0;
    //user interface
    cout<<"------------循环赛的日程安排标---------------"<<endl;
    cout<<"请输入K，构成n=2^k个选手的循环赛"<<endl;

    cin>>k;
    if(cin.fail()||k<0){//输入合法性判断
        cout<<"Error!"<<endl;
        system("pause");
        return 0;

    }

    n=pow(2,k);//计算日程表的大小

    int **table=new int *[n+1];//分配表的空间
    for(int i=0;i<n;i++){
        table[i]=new int [n+1];

    }

    MatchTable(k,n,table);



    cout<<":----------------------------------"<<endl;
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            cout<<table[i][j]<<'\t';

        }
        cout<<endl;

    }
    cout<<"-----------------------------------"<<endl;



    system("pause");


    for(int i=0;i<=n;i++){
        delete[] table[i];
        delete[] table;


        table ==null;
        return 0;


    }


}

void MatchTable(int k,int n,int **table)
{
    //设置日程表的第一行
    for(int i=1;i<n;i++)
        table[1][i]=i;

    int begin =1;//每次填充的起始位置

    for(int s=1;s<k;s++){//用分治法分为s份，循环求解

        n/=2;//日程表划分

        for(int flag=1;flag<=n;flag++){//flag为每一份的列标记
            for(int i=begin+1;i<=2*begin;i++)//操作行

                for(int j=begin+1;j<2*begin;j++)

                {

                    //把左上角赋值给右下角
                    table[i][j+(flag-1)*begin*2]=table[i-begin][j+(flag-1)*begin*2-begin];
                    //把右上角赋值给左下角
                    table[i][j+(flag-1)*begin*2-begin]=table[i-begin][j+(flag-1)*begin*2];
                }



        }
        begin*=2;
        
    }

}




























