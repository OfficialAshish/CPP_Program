#include <iostream>
#include <cmath>
#include "complex_single_object.h"

int main()
{
    using std::cout;
    using namespace complex_singleton;

    // not singleton, normal

    Complex obj(3.4, 5.4);
    cout << obj;
    // cout << obj.modulus();

    
    // singleton test...
    // anotherComplex try1(3.3,4.4,'y');//should give error
    anotherComplex &point_to_obj= anotherComplex::genObj(9.8, 9.2, 'f');
    point_to_obj.print();
    point_to_obj.setComplex(34.4,56.5);
    cout << point_to_obj;


    cout << "\nMain End!.\n";
    delete &anotherComplex::genObj(); // must to be given explicitily
    // anotherComplex::~anotherComplex();//will not pass this obj pointer,thus not works implicit
}