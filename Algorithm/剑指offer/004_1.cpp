class Solution{
public:
    void insertArray(int* A1,int*A2,int len1,int len2)
    {
        int newIndex=((len1--)+(len2--))-1;
        while(len1>=0&&len2>=0)
        {
            if(A1[len1]>=A2[len2])
                A1[newIndex--]=A1[len1--];
            else
                A1[newIndex--]=A2[len2--];



        }
        while(len1>=0)
            A1[newIndex--]=A1[len1--];
        while(len2>=0)
            A1[newIndex--]=A2[len2--];


    }

};

void Test(char * testname,int *A1,int* A2,int len1,int len2)
{
    if(testname!= nullptr)
    cout<<testname<<"  starts:"<<endl;
    Solution solu;
    solu.insertArray(A1,A2,len1,len2);
    for(int i=0;i<len1+len2;i++)
        cout<<A1[i]<<" ";


}
void test1(){
    const int len1=6,len2=5;
    int A1[20]={1,3,5,7,9,11};
    int A2[10]={2,4,6,8,10};
    Test("test1",A1,A2,len1,len2);

}
int main(){
    test1();
    return 0;
}