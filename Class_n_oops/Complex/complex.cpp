#include <iostream>
#include <cmath>
#include "Complex.h"
using namespace std;

int main()
{
    Complex a(3.4, 5.4);
    a.modulus();
    a.print();

    a.setComplex(5, 5);
    a.print();
    cout << endl;

    cout << "\nSQRT( x^2 + y^2 ) = " << a.modulus() << endl;

    return 0;
}