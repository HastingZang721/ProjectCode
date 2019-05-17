#include<cassert>

#ifndef STACK_H

#define STACK_H

template<class T, int size = 50>//使用模版类定义，size为stack的大小
class Stack {
private:

    T list[size];
    int top;
public:
    Stack();//初始化

    void push(const T &item);//压棧

    T pop();//出棧

    void clear();//清棧

    const T &peek const ();//访问棧顶元素
    bool isempty() const;
    bool isfull() const;


};
template<class T,int size>//初始棧
Stack <T,size>::Stack(): top(-1) {}

template<class T,int size>
void Stack<T,size>::push (const T &item)
{
    assert(! isfull());//若棧满则报错
    list[++top]=item;  //将新元素压入棧顶

}

template<class T,int size>//出棧
void Stack <T,size>::pop() {
    assert(! isempty());
    return list[top--];

}

template<class T,int size>//访问棧顶的元素
const T&  Stack<T,size>::peek() const{
    assert(! isempty());
    return list[top];

}

template<class T,int size>//判断是否为空
bool Stack(T,size):: isempty() const{
    return top==-1;

}

template <class T,int size>//判断是否棧满
bool Stack(T,size)::isfull() const{
    return top=size-1;
    
}

template<class T,int size>
dool Stack(T,size)::clear(){
    top=-1;
    
}

