#include<vector>
#include<iterator>
using std::vector;
//桶排序，将值为i的的元素放入i桶，最后将桶中元素倒出来；
const int num=10;
void BucketSort(int *score,int num){
    int a[11];//buycket
    for(int i=0;i<=10;i++){
        a[i]=0;
        //现将全部bucket计数初始化为0
    }
    for(int i=0;i<num;i++){
        int temp=score[i];
        ++a[temp];//有多少个数放入该bucket，则计数值加一

    }
    for(int i=0;i<11;i++){
        int num_print=a[i];
        for(int j=1;j<num_print;j++)
            cout<<i<<'';


    }
}

int main(){
    int Score[]={       };
    int num= sizeof(Score)/sizeof(int);
    BucketSort(Score,num);
    getchar();
    return 0;
}