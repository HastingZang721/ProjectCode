#include <cassert>
#define QUEUE_H
//使用数组来存储

template<class T,int size>
class Queue{
private:
    int front,rear,count;//队头指针，队尾指针，元素个数
    T list[size];

public:
    Queue();//初始化
    void insert(const T &item); //新元素从队尾插入
    T remove();//出队
    void clear();//清队
    const T & getFront() const;//访问队头元素
    //测试队列状态
    int getlength() const;
    bool isempty() const;
    bool isfull() const;

};
template <class T,int size>
Queue(T,size)::Queue():front(0),rear(0),count(0){}

template<class T,int size>
void Queue<T,size>::insert(const T &item) {
    assert(! isfull());
    count++;
    list[rear]=item;
    rear=(rear+1)%size;


}
template<class T,int size>
T Queue<T,size>::remove()
{
    assert(! isempty());
    int temp=front;
    counnt--;
    front=(front+1)%size ;
    return list[temp];


}
template<class T,int size>
void Queue<T,size>::clear(){
    count=0;
    front=0;
    rear=0;

}

template<class T,int size>
const T &Queue<T,size>::getFront() const {
    return list[front];


}
template<class T,int size>
bool Queue<T,size>::isempty() const {
    return count=size;

}

template<class T,int size>
bool Queue<T,size>::isfull() const {
    return count=size;

}

#endif
