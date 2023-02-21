#include <iostream>
#include <vector>
#include "polynomial.h"
// #include "./Fraction/fraction_v2_impl.h"

using namespace std;
using namespace polynomial_nm;
// using namespace fraction_nm;

int main()
{
    vector<int> v = {1, 2, 3};
    Polyn<int> p1(v);

    //     Polyn f1(1, 4);
    // cout << "Polyn f1(1, 4) = " << f1 << endl;
    // Polyn f2(3, 6);
    // cout << "Polyn f2(3, 6) = " << f2 << endl;
    // Polyn f3(f2);
    // cout << "Polyn f3(f2) = " << f3 << endl;
    // Polyn f4;
    // cout << "Polyn f4 = " << f4 << endl;
    // Polyn f5(4);
    // cout << "Polyn f5(4) = " << f5 << endl;
    // cout << "Assignment (f4 = f2) so now, f4 = " << (f4 = f2) << endl
    //      << endl;

    cout << p1;
    cout << "Read test\nEnter : ";
    // cin >> p1;
    // cout << "input f5 = " << p1 << endl;

    // cout << "\nsum = " << f1 << "+" << f2 << " : " << f1 + f2 << endl;
    // cout << "divide = " << f1 << "/" << f2 << " : " << f1 / f2 << endl;
    // cout << "modulus = " << f1 << "%" << f2 << " : " << f1 % f2 << endl;
}
