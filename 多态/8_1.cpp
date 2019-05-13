#include<iostream>

using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex &c2) const;

    Complex operator-(const Complex &c2) const;

    void display() const;

private:
    double real;
    double imag;

};

Complex Complex::operator+(const Complex &c2) const {
    return Complex(real + c2.real, imag + c2.imag);
}

Complex Complex::operator-(const Complex &c2) const {
    return Complex(real - c2.real, imag - c2.imag);

}

void Complex::display() const {
    cout << "real:" << real << "," << "imag:" << imag << endl;
}

int main() {
    Complex c1(5, 3), c2(2, 10), c3, c4;
    cout << "c1=:" ;c1.display();
    cout << "c2=:" ;c2.display();
    cout << "c3=:" ; c3.display();
    c3 = c1 - c2;
    cout << "After" << endl;
    cout << "c3="; c3.display();
    c4 = c1 + c2;
    cout << "c4=:" ;c4.display();
    return 0;

}
