
#if !defined(_Radix_Implementation_)
#define _Radix_Implementation_
#define DEBUG true

#include "radix_conv_interface.h"
#pragma once

#include <vector>
#include <string>
using namespace std;

namespace nm_Radix_
{

    using namespace nm_Radix;

    int conversion::getAns()
    {
        return conversion::answer;
    }

    void conversion::reverse(auto &arr)
    {
        int length = arr.size();

        for (auto i = 0; i < length / 2; i++)
        {
            auto temp = arr[i];
            arr[i] = arr[length - i - 1];
            arr[length - i - 1] = temp;
        }
    }

    int conversion::binaryToDecimal(int bin)
    {
        for (size_t i = 1; bin != 0; bin = bin / 10, i *= 2)
        {
            conversion::answer += ((bin % 10) * i);
            // cout << i << "&" << bin % 10 << endl;
        }
        return conversion::answer;
    }

    int conversion::octalToDecimal(int oct)
    {
        for (size_t i = 1; oct != 0; oct /= 10, i *= 8)
        {
            conversion::answer += (oct % 10) * i;
            // cout << i << "&" << oct % 10 << endl;
        }
        return conversion::answer;
    }

    int conversion::hexadecimalToDecimal(string hex)
    {
        for (int i = 1, j = hex.size(); j > 0; j--, i *= 16)
        {
            char elem = hex[j - 1];
            if (elem >= '0' and elem <= '9')
            {
                conversion::answer += (elem - '0') * i;
            }
            else if ((elem) >= 'A' and (elem) <= 'F')
            {
                conversion::answer += (elem - 'A' + 10) * i;
                // cout << i << " & elm:" << (elem-'A'+10) << endl;
            }
            else if ((elem) >= 'a' and (elem) <= 'f')
            {
                conversion::answer += (elem - 'a' + 10) * i;
            }
            else
            {
                cout << "\nError!\n";
                return 0;
            }
        }
        return conversion::answer;
    }

    // Decimal to ...

    int conversion::decimalToBinary(int dec)
    {
        conversion::answer = 0;
        vector<int> arr;
        while (dec > 0)
        {
            int rem = 0;
            rem = dec % 2;
            arr.push_back(rem);
            dec /= 2;
        }
        conversion::reverse(arr);
        // converting to int
        for (int i = 0; i < arr.size(); i++)
        {
            conversion::answer = conversion::answer * 10 + arr[i];
        }
        return conversion::answer;
    }

    int conversion::decimalToOctal(int dec)
    {
        conversion::answer = 0;
        vector<int> arr;
        while (dec > 0)
        {
            int rem = 0;
            rem = dec % 8;
            arr.push_back(rem);
            dec /= 8;
        }
        conversion::reverse(arr);
        // converting to int
        for (int i = 0; i < arr.size(); i++)
        {
            conversion::answer = conversion::answer * 10 + arr[i];
        }
        return conversion::answer;
    }

    string conversion::decimalToHexadecimal(int dec)
    {
        answerHex = "";
        string temp = "";
        vector<string> arr;
        int rem = 0;
        while (dec > 0)
        {
            rem = dec % 16;
            if (rem >= 10)
            {
                temp = rem - 10 + 'A';
            }
            else
            {
                temp = to_string(rem);
            }

            arr.push_back(temp);
            dec /= 16;
        }
        reverse(arr);
        // converting to str
        for (int i = 0; i < arr.size(); i++)
        {
            answerHex = answerHex + arr[i];
        }
        return answerHex;
    }
};

conversion::~conversion()
{
    (DEBUG == true) ? cout << "\nInside Destructor. \n" : cout << "";
}
// }
// namespace nm_Radix

#endif // _Radix_Implementation_
