#include<iostream>
#include <cstdio>
 //num[]:整数数组
 //du ：输出数组中一个重复的数字

bool duplicate(int num[],int length,int* du){
    if(num==nullptr||length <=0)
        return false;

    for(int i=0;i<length ;++i)
    {
        if(num[i]<0||num[i]>length-1)
            return false;

    }
    for(int i=0;i<length;++i)
    {
        while(num[i]!=i){
            if(num[i]==num[num[i]])//记录是否和之前的下标有相同的数字，发现重复，输出
            {
                *du=num[i];
                return true;

            }
            //num[i]<--->num[num[i]]
            int temp=num[i];
           num[i]=num[num[i]];
           num[num[i]]=temp;


        }
    }
    return false;//无重复


}


//----------------------=======测试代码----------------------------


bool contains(int array[],int length,int number){
    for(int i=0;i<length;++i){
        if(array[i]==number)
            return true;

    }
    return false;

}

void test(char* testName,int num[],int lengthnum,int excepted[],int exceptedlength,bool validArgument)
{
    printf("%s starts:",testName);
    int du;
    bool validInput=duplicate(num,lengthnum,&du);//检查是否有重复数字
    if(validArgument==validInput){
        if(validArgument){
            if(contains(excepted,exceptedlength,du))//检查查出的重复数字是否在except[]其中
                printf("passed.\n");
            else
                printf("Failed,\n");

        }
        else
            printf("passed.\n");

    }
    else
        printf("Failed.\n");




}

void test1(){
    int number[]={2,1,3,1,4};
    int duplications[]={1};
    test("Test1",number, sizeof(number)/sizeof(int),duplications,sizeof(duplications)/sizeof(int),true);

}


int main(int argc,char* argv[])
{
    test1();
    return 0;
}









