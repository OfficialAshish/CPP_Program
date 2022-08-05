#include <iostream>
#include "radix_conversion.h"

using namespace nm_Radix;

int main()
{
    conversion bintodec1;
    cout<< bintodec1.binaryToDecimal(100);

    conversion octtodec1;
    cout<< octtodec1.octalToDecimal(777);
    return 0;
}