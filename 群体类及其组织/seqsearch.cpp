#define HEADER_Seqsearch.h
template<class T>
int seqsearch(const T list[],int n,const T &key){//顺序查找在数组list中值为KEY的元素
    
    for(int i=0;i<n;i++)
        if (list[i]==key)
            return i;
        
    return -1;
    
    
}