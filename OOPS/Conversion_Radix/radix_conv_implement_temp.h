
#if !defined(_Radix_Implementation__)
#define _Radix_Implementation__
#define DEBUG 0

#include <vector>
#include <string>

namespace nm_Radix__
{
    using namespace std;

    class conversion
    {
    protected:
        int_fast64_t answer;
        string answerHex;

        void reverse(auto &arr)
        {
            int length = arr.size();

            for (auto i = 0; i < length / 2; i++)
            {
                auto temp = arr[i];
                arr[i] = arr[length - i - 1];
                arr[length - i - 1] = temp;
            }
        }

    public:
        conversion() : answer(0)
        {
            (DEBUG == true) ? cout << "\nInside Constructor. \n" : cout << "";
        }
        ~conversion()
        {
            (DEBUG == true) ? cout << "\nInside Destructor. \n" : cout << "";
        }

        int getAns() { return answer; }

        // interface

        int binaryToDecimal(int bin)
        {
            for (size_t i = 1; bin != 0; bin /= 10, i *= 2)
            {
                answer += ((bin % 10) * i);
                // cout << i << "&" << bin % 10 << endl;
            }
            return answer;
        }

        int octalToDecimal(int oct)
        {
            answer = 0;
            for (size_t i = 1; oct != 0; i *= 8)
            {
                answer += (oct % 10) * i;
                oct /= 10;
                // cout << i << "&" << oct % 10 << endl;
            }
            return answer;
        }

        int hexadecimalToDecimal(string hex)
        {
            for (int i = 1, j = hex.size(); j > 0; j--, i *= 16)
            {
                char elem = hex[j - 1];
                if (elem >= '0' and elem <= '9')
                {
                    answer += (elem - '0') * i;
                }
                else if ((elem) >= 'A' and (elem) <= 'F')
                {
                    answer += (elem - 'A' + 10) * i;
                    // cout << i << " & elm:" << (elem-'A'+10) << endl;
                }
                else if ((elem) >= 'a' and (elem) <= 'f')
                {
                    answer += (elem - 'a' + 10) * i;
                }
                else
                {
                    cout << "\nError!\n";
                    return 0;
                }
            }
            return answer;
        }

        // Decimal to ...

        int_fast64_t decimalToBinary(int dec)
        {
            answer = 0;
            vector<int> arr;
            while (dec > 0)
            {
                int rem = 0;
                rem = dec % 2;
                arr.push_back(rem);
                dec /= 2;
            }
            // reverse(arr);
            // converting to int
            /* for (int i = 0; i < arr.size(); i++)
            {
                answer = answer * 10 + arr[i];
            } */
            for (auto i = arr.end(); i != arr.begin() - 1; i--)
            {
                answer = (answer * 10) + *i;
            }

            return answer;
        }
        // overloading
        int_fast64_t anyToBinaryL(auto any)
        {
            int bit = 0;
            long long int ans = 0, n_10 = 1;
            while (any != 0)
            {
                bit = any & 1;
                ans = ans + (bit * (n_10 *= 10));
                any = any >> 1;
                // cout << ans << ", " << bit << ", " << any << endl;
            }
            return ans;
        }
        void anyToBinaryLP(auto any)
        {
            if (any == 0)
            {
                return;
            }
            int bit = 0;
            bit = any & 1;
            anyToBinaryLP(any >> 1);
            cout << bit; // backtrack printing
        }

        int decimalToOctal(int dec)
        {
            answer = 0;
            vector<int> arr;
            while (dec > 0)
            {
                int rem = 0;
                rem = dec % 8;
                arr.push_back(rem);
                dec /= 8;
            }
            reverse(arr);
            // converting to int
            for (int i = 0; i < arr.size(); i++)
            {
                answer = answer * 10 + arr[i];
            }
            return answer;
        }

        string decimalToHexadecimal(int dec)
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

            // answerHex = (arr);
            return answerHex;
        }
    };

} // namespace nm_Radix

#endif // _Radix_Implementation_
