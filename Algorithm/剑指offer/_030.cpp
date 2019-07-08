#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>
#include<stack>


using namespace std;
/*
 * 包含min 函数的棧（得到棧的最小元素的min 函数）
 *利用到两个棧（数据棧+辅助棧）
 * 其中辅助棧每次是用来存放最小值
 *
 * 在push-data栈的时候，将当前最小数据压入，

在pop-data栈的时候，将min栈栈顶的最小数据弹出

这样保证min栈中存储着当前现场的最小值，并随着数据栈的更新而更新
 */

template <typename T> class StackwithMin
{
public:
    StackwithMin() {}
    virtual ~StackwithMin() {}

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
    std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};



template<class T>
void StackwithMin<T>::push(const T &value) {
    m_data.push(value);
    if (m_min.size() == 0 || value < m_min.top())//押入的值value若小于当前辅助棧中
        m_min.push(value);
    else
        m_min.push(m_min.top()) ;//否则还是将当前最小值再一次入棧

}

template<class T>
void StackwithMin<T>::pop() {
    bool flag = false;
    if (m_data.size() > 0 && m_min.size() > 0)
        flag = true;
    if (flag == true) {
        m_data.pop();
    }


}

template<class T>
const T &StackwithMin<T>::min() const {
    bool flag = false;
    if (m_data.size() > 0 && m_min.size() > 0)
        flag = true;
    if (flag == true) {
        return m_min.top();//完成在o(1)时间内取出最小值
    }
}


void Test(char *testname, const StackwithMin<int> &stack, int expected) {
    if (testname != nullptr)
        cout << testname << " Begins: " << endl;
    if (stack.min() == expected)
        cout << "passed" << endl;
    else
        cout << "failed" << endl;

}

int main() {
    StackwithMin<int> stack;


    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    return 0;

}