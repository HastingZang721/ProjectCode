#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<string>

using namespace std;
template <class T>
class MyArray{
public:
    MyArray(int capacity){
        this->Mcapacity=capacity;
        this-> size=0;
        //申请内存
        this->pArr=new T[this->Mcapacity];

    }
    MyArray(const MyArray<T>& arr){
        this->size=arr.szie;
        this->Mcapacity=arr.Mcapacity;
        //申请内存空间
        this->pArr=new T[this->Mcapacity];
        //数据拷贝
        for(int i=0;i<this->size;i++)
        {
            this->pArr[i]=arr.pArr[i];

        }
    }


    T& operator[](int index){//查找index的地址
        return this->pArr[index];

    }
    MyArray< T> operator=(const MyArray<T>& arr){
        if(this->pArr!=NULL)
            delete[]this->pArr;//若以前有空间则释放
        this->size=arr.szie;
        this->Mcapacity=arr.Mcapacity;
        //申请内存空间
        this->pArr=new T[ this->Mcapacity];
        //数据拷贝
        for(int i=0;i<this->size;i++)
        {
            this->pArr[i]=arr.pArr[i];

        }

        return *this;

    }

//向容器中放的都是值寓意 而不是引用，即都是将值拷贝一份放入的
//如果元素的成员有指针，注意前拷贝与深拷贝
    void PushBack(T& data){
        if(this ->size>=this->Mcapacity)
            return;
        this->pArr[this->size]=data;//注意这里的对象是可拷贝的
        this->size++;



    }


    void PushBack(T&& data){//这样就可以对右值去引用

        if(this ->size>=this->Mcapacity)
            return;
        this->pArr[this->size]=data;
        this->size++;
    }
    ~MyArray(){
        if(this->pArr!=NULL)
            delete[]this->pArr;
    }





public:
    int Mcapacity;//可容纳多少元素

    int size;//当前拥有的数据量
    T* pArr;//保存数据的首地址

};

void test1(){
    MyArray<int >marry(20);
    int a=10;
    int b=20,c=3,d=40;

    marry.PushBack(a);
    marry.PushBack(b);marry.PushBack(c);marry.PushBack(d);
    marry.PushBack(100);

    for(int i=0;i<marry.size;i++)
    {
        cout<<marry[i]<<"  ";

    }
    cout<<endl;

}



int main(){
    test1();

    return 0;

