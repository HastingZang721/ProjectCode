template<class T>
void Quicksort(T a[],int start,int end)
{
    while(start<end){
        int i=start,j=end;
        T temp=a[start];//取第一个数为基准
        while(i!=j){
            while(temp<a[j]&&i<j)//从右边查找出第一个小于基准的数
                j--;
            while(temp>a[i]&&i<j)//从左到右找出第一个大于基准的数
                i++;
            if (i<j)
                swap(a[i],a[j]);



        }
        swap(a[start],a[i]);//基准数归位
        Quicksort(a,start,i-1);
        Quicksort(a,i+1,end);


    }
    return 0；


}