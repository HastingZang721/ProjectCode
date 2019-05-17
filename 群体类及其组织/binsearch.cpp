#define Headerbinsearch.h
template<class T>
int binsearch(const T list[],int n,const T&key){
    int low=0;
    int high=n-1;
    while(low<high)//low<high表示整个数组还未查找完
    {
        int mid=(high+low)/2;
        if (key==list[mid])
            return mid;
        else if (key <list[mid])
            high=mid-1;
        else
            low=mid+1;
        
    }
    
    return -1;
    
    
}