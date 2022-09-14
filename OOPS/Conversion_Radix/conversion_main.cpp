#include <iostream>
// #include "radix_conv_implement.h"
#include "radix_conv_implement_temp.h"

using namespace nm_Radix__;

int main()
{
    // conversion bintodec1;
    // cout << bintodec1.binaryToDecimal(100);
    // cout << endl;

    // conversion octtodec1;
    // cout << octtodec1.octalToDecimal(777);
    // cout << endl;

    // conversion hextodec;
    // cout << hextodec.hexadecimalToDecimal("2Af4");
    cout << endl;
    // printf("\n%X",10996);//o,x,X

    conversion allconv;
    // cout << allconv.decimalToBinaryL(45589) << endl;
    cout << "dec:" << allconv.octalToDecimal(2064) << endl;
    cout << allconv.decimalToBinary((allconv.octalToDecimal(2064))) << endl;
    allconv.anyToBinaryLP(0x434);
    cout << endl;
    allconv.anyToBinaryLP(1076);

    printf("\nOctal: %o \n", 0x434);
    printf("Octal: %X \n", 1076);

    // cout << allconv.decimalToHexadecimal(10996);

    return 0;
}