
void Merge(int a[],int start,int mid,int end)

{
    int len=end-start+1;
    int temp[end-start+1];
    int i=0;
    int p1=start;
    int p2=mid+1;
    //比较左右两个部分的元素，哪个元素小就将其填入temp
    while(p1<=mid&&p2<=end)
    {
        if(a[p1]<a[p2])
        {
            temp[i++]=a[p1++];

        }
        else
        {
            temp[i++]=a[p2++];

        }
        //<==>temp[i++]=a[p1]<a[p2]?a[p1++]:a[p2++];
    }
    // 上面的循环退出后，把剩余的元素依次填入到temp中
    while(p1<=mid)
    {
        temp[i++]=a[p1++];

    }
    while(p2<=end)
    {
        temp[i++]=a[p2++];
    }


    //int len=sizeof(temp)/sizeof(temp[0]);
    //把最终的结果复制给原数组
    for(int j=0;j<len;j++)
    {
        a[start+j]=temp[j++];
    }





}

void MergeSort(int a[],int l,int r)
{
    if(l==r) return ;

    int mid=(l+r)/2;
    MergeSort(a,l,mid);
    MergeSort(a,mid+1,r);
    Merge(a,l,mid,r);

}

int main(){
    int arr[]={1,3,2,4,1,3,22,455,21,13};
    int len=sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,len-1);
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;

}