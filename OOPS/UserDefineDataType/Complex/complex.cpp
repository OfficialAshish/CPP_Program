#include <iostream>
#include <cmath>
#include "Complex.h"
// using namespace std;
using namespace complex_1;

int main()
{
    // Complex a(3.4, 5.4);
    // cout << a;
    // a.print();

    // a.setComplex(5, 5);
    // a.print();
    // cout << endl;

    // cout << "\nSQRT( x^2 + y^2 ) = " << a.modulus() << endl;

    anotherComplex ano_1(5.7,7.4);
    ano_1.print();

    anotherComplex ano_2(1.3,2.9,'v');
    cout << ano_2;
    return 0;
}