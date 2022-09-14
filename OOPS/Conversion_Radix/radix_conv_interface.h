
#if !defined(_Radix_Interface_)
#define _Radix_Interface_

// #include "radix_conv_implement.h"

namespace nm_Radix
{
    class conversion
    {
    protected:
        int answer;
        string answerHex;

    public:
        conversion();

        ~conversion();

        int getAns();

        void reverse(auto &);

        int binaryToDecimal(int bin);

        int octalToDecimal(int oct);

        int hexadecimalToDecimal(string hex);

        // decimal to ...

        int decimalToBinary(int dec);

        int decimalToOctal(int dec);

        string decimalToHexadecimal(int dec);
    };
}
#endif