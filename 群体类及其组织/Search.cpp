#include<iostream>
#include <Vector>
#include<stdlib.h>
#define OVERFLOW -1;
#define ERROR -1;


int sequentialsearch(vector<int> &v, int k) {//顺序查找

    for (int i = 0; i < v.size(); ++i) {
        if (v.[i] == k)
            return i;

    }
    return -1;

}


int binarySearch(vector<int> &v, int value, int low, int high) {//折半查找
    if (low < high)
        return -1;
    int mid = low + (high - low) / 2;
    if (v[mid] == value)
        return mid;
    else if(v[mid]>value)
        return binarySearch(v,value,low,mid-1);
    else
        return binarySearch(v,value,mid+1,high);



}

typedef int Status;
typedef int KeyType;
typedef struct{
    KeyType key;
}RcdType;
typedef struct{//节点设计
    RcdType *rcd;
    int size;
    int count;
    int *tag;

}HashTable;

int hashsize[]={11,31,61,127,252,503};
int index=0;
Status InitHashTable(HashTable &H,int size)//创建对象
{
    int i;
    H.rcd=(RdcType *)malloc(sizeof(RcdType)*size);
    H.tag=(int *)malloc (sizeof(int )*size);
    if (H.rcd==null||H.tag==null)
        return OVERFLOW;
    for(int i=0;i<size;i++)
        H.tag[i]=0;
    H.size=size;
    H.count=0;
    return 1;



}
int Hash(KeyType key,int m){
    return (3*key)%m;

}
void collision(int &p,int m){//线行探测
    p=(p+1)%m;

}

Status SearchHash(HashTable H,KeyType key,int &p,int &c){
    p=Hash(Key,H.size);
    int h=p;
    c=0;
    while((1==H.tag[p]&&H.rcd[p].key!=key)||H.tag[p]==-1){
        collision(p,H.size);
        c++;
    }//产生碰撞
    if(H.tag[p]==1&&H.rcd[p].key==key)
        return 1;
    else
        return -1;



}
void printHash(HashTable H){
    int i;
    printf("key: ");
    for(i=0;i<H.size;i++)
        printf("%3d",H.tag[i]);
    printf("\n")
}






















