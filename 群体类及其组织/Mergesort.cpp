#include<iostream>
void Merge(vector<int> &data,int start,int end,int mid){//归并排序

    vector<int> tem;
    int i=start;
    int j=mid +1;
    while(i!=mid+1&&j!=end+1){
        if(data[i]<=data[j])
            tem.push_back(data[i]);


        else
            tem.push_back(data[j]);


    }
    while (i != mid + 1) {
        tem.push_back(data[i++]);
    }
    while (j != end + 1) {
        tem.push_back(data[j++]);}
    for (int i = 0; i < tmp.size(); i++) {
        data[start + i] = tem[i];


    }
void Mergesort(vector<int >&data,int start,int end)
if (start<end){
    int mid =(start+end)/2;
    Mergesort(data,start,mid);
    Mergesort(data,mid+1,end);
    Merge(data,start,end,mid);
    
}



