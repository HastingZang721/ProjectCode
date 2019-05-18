#include<iostream>
int heapsize
void HeapMax(int a[],int i){//大顶堆化
    int l=2*i+1;
    int r=2*i+2;
    int largest;
    if(l<heapsize&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if (r<heapsize&& a[r]>a[i])
        largest=r;
    if (largest!=i){
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;

        HeapMax(a,largest);

    }


}
void Build_MAX_Heap(int a[])
{
    for(int i=(heapsize/2)-1,i>=1;i++){//从第一个非叶节点开始
        HeapMax(a,i);
        for(i=heapsize-1;i>=2;i--)
            swap(a[i],a[0]);//将根节点与最后一个叶节点互换
        HeapMax(a,0);
    }

}

int main(){
    int a[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(a) / sizeof(*a);
    Build_MAX_Heap(a);
    for (int i = 0; i < len; i++)
        cout << ai] << ' '; 
     return 0;
}
