#include<iostream>
#include<cstring>
#include<math.h>
#include<cstdio>

class CMystring {
public:
    CMystring(char *pData = nullptr);

    CMystring(const CMystring &str);

    void Print();
    CMystring& operator=(const CMystring& str);

    ~CMystring(void);

private:
    char *m_pData;


};

CMystring::CMystring(char *pData) {
    if (pData == nullptr) {
        m_pData = new char[1];
        m_pData[0] = '\0';

    } else {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }


}

CMystring::CMystring(const CMystring &str) {
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMystring::~CMystring() {
    delete[] m_pData;

}


CMystring& CMystring::operator=(const CMystring& str)//返回值的类型声明为该类型的引用，这样才允许连续赋值；
//把传入的参数的类型声明为常量引用，否则会形实结合从而调用一次复制构造函数
{
    if (this == &str)//判断传入的参数和当前的实例（*this ）是否为同一实例
        return *this;
    delete[]m_pData;//在分配新内存前释放实例已有的内存，否则将出现内存泄漏
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    /*  delete []m_pData;//在分配新内存前释放实例已有的内存，否则将出现内存泄漏
      m_pData= nullptr;*/
    return *this;//函数结束前返回实例自身的引用

}


//-------------------------------测试代码---------------------

void CMystring::Print() {
    printf("%s", m_pData);

}

void Test1() {
    printf("Test1 starts:\n");
    char* text = "Hello world";
    CMystring str1(text);
    CMystring str2;
    str2 = str1;


    printf("The expect result is %s.\n", text);
    printf("The actual result is :");
    str2.Print();
    printf(".\n");

}

void Test2(){//赋值给自己
    printf("Teste2 starts:\n");
    char* test="Hello world";
    CMystring str1(test);
    str1=str1;
    printf("The excepted result is %s.\n",test);

    printf("The actual result is :");
    str1.Print();
    printf(".\n");

}
//连续赋值

void Test3(){
    printf("Test3 statrs:\n");
    char* test="Haasting";

    CMystring str1(test);
    CMystring str2,str3;
    str3=str2=str1;
    printf("The except result is :",test);


    printf("The str2 ,str3 actual result is :");
    str2.Print();
    printf(".\n");
    str3.Print();
    printf(".\n");

































