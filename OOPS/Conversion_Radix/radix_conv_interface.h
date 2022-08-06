
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
        // void reverse(vector<int>&);
        void reverse(vector<int> &arr)
        {
            int length = arr.size();
            for (int i = 0; i < length / 2; i++)
            {
                int temp = arr[i];
                arr[i] = arr[length - i - 1];
                arr[length - i - 1] = temp;
            }
        }

    public:
        conversion();

        ~conversion();

        int getAns(); // { return answer; }

        int binaryToDecimal(int bin);

        int octalToDecimal(int oct);

        int hexadecimalToDecimal(string hex);

        int decimalToBinary(int dec);

        int decimalToOctal(int dec);
    };
}
