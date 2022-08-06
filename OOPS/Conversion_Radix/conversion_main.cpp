#include <iostream>
// #include "radix_conv_interface.h"
#include "radix_conv_implement_temp.h"

using namespace nm_Radix__;

int main()
{
    conversion bintodec1;
    cout << bintodec1.binaryToDecimal(100);
    cout << endl;

    conversion octtodec1;
    cout << octtodec1.octalToDecimal(777);
    cout << endl;

    conversion hextodec;
    cout << hextodec.hexadecimalToDecimal("2Af4");
    cout << endl;
    // printf("\n%X",10996);//o,x,X

    conversion allconv;
    cout << allconv.decimalToBinary(4);

    return 0;
}