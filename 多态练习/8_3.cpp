
#include <iostream>

using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}//构造函数声明；
    friend Complex operator+(const Complex &c1, const Complex &c2);//以非成员函数的形式重载Complex的加减法运算和<<;
//若需要访问参数对象类的私有成员，可将该函数定义为类的友元函数


    friend Complex operator-(const Complex &c1, const Complex &c2);

    friend ostream &operator<<(ostream &out, const Complex &c);
private:
    double real;
    double imag;


};


Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);

}

Complex operator-(const Complex &c1,const Complex &c2
)
{
return Complex(c1.real-c2.real,c1.imag-c2.imag);

}

ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.real << "," << c.imag << ")";
    return out;

}

int main() {
    Complex c1(5, 3), c2(10, 10), c3;
    cout << c1 << endl;
    cout << c2 << endl;
    c3 = c2 - c1;
    cout << "c3=c2-c1=" << c3 << endl;
    c3 = c1 + c2;
    cout << "c3=c2-c1=" << c3 << endl;
    return 0;

}