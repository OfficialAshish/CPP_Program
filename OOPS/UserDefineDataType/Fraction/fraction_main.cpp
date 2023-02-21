#include <iostream>
#include "fraction_v2_impl.h"

using namespace std;
using namespace fraction_nm;

int main()
{
    Fraction f1(1, 4);
    cout << "Fraction f1(1, 4) = " << f1 << endl;
    Fraction f2(3, 6);
    cout << "Fraction f2(3, 6) = " << f2 << endl;
    Fraction f3(f2);
    cout << "Fraction f3(f2) = " << f3 << endl;
    Fraction f4;
    cout << "Fraction f4 = " << f4 << endl;
    Fraction f5(4);
    cout << "Fraction f5(4) = " << f5 << endl;
    cout << "Assignment (f4 = f2) so now, f4 = " << (f4 = f2) << endl
         << endl;

    cout << "Read test\nEnter : ";
    // cin >> f5;
    cout << "input f5 = " << f5 << endl;

    cout << "\nsum = " << f1 << "+" << f2 << " : " << f1 + f2 << endl;
    cout << "divide = " << f1 << "/" << f2 << " : " << f1 / f2 << endl;
    cout << "modulus = " << f1 << "%" << f2 << " : " << f1 % f2 << endl;
}
