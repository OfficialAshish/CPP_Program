#include <iostream>
#include <cmath>
// #include <bits/stdc++.h>
#include "Complex.h"
using namespace std;
using namespace complex_lrn;
/*
class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double re_ = 0, double im_ = 0) : real(re_), imag(im_)
    {
        cout << "\nInside Constructor.\n";
    }
    Complex(const Complex &sourceObj) : real(sourceObj.real), imag(sourceObj.imag)
    {
        cout << "\nInside C_cons\n";
    }

    ~Complex()
    {
        cout << "\nInside Destructor.\n";
    }

    void setComplex(double re_ = 1.0, double im_ = 1)
    {
        real = re_;
        imag = im_;
    }
    void print()
    {
        cout << "\n Complex NO. : " << real << " + j" << imag << endl;
    }

    int modulus()
    {
        int mod = sqrt(pow(real, 2) + pow(imag, 2));
        return mod;
    }
};
*/

int main()
{
    Complex a(3.4, 5.4);
    a.modulus();
    a.print();

    a.setComplex(5, 5);
    a.print();
    // cout << "\nSQRT( x^2 + y^2 ) = " << a.modulus() << endl;
    cout << endl;

    Complex b;
    cout << "\n1-Complex b; : ";
    b.print();
    cout << endl;

    Complex c(2.3, 4.5);

    cout << "\nComplex c(.,.) : ";
    c.print();
    cout << endl;

    Complex d = c;

    cout << "\nComplex d=c(.,.) @definn. : ";
    d.print();
    cout << endl;

    
    b = a;
    cout << "\n2-Complex b=a (updt frm deflt): ";
    b.print();
    cout << endl;

    return 0;
}