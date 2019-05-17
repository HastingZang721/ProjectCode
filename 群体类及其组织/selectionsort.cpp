template<class T>
void mySwap(T &x, T & y){//交换X，Y的值
    T temp =x;
    x=y;
    y=temp;
    
}
template<class T>
void SelectionSort(T a[],int n)
{
    for(int i=0;i<n-1;i++){
        int leastindex=i;//最小的元素下标初值设置为i；
        for (int j=i+1,j<n;j++){//a[i+1]--a[n-1]选择最小的
            if (a[j]<a[leastindex])
                leastindex=j;
            mySwap(a[leastindex],a[i])//将这趟找到的最小元素与a【i】交换
            
        }
        
    }
}