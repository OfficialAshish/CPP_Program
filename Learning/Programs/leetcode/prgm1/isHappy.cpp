#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum = n, digit = 0;
        while (sum != 1)
        {
            digit = sum;
            sum = 0;
            while (digit > 0)
            {
                sum = sum + (digit % 10) * (digit % 10);
                digit /= 10;
            }
            if (!(sum / 10))
            {
                if (sum == 1 or sum == 7)
                    return true;
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    bool res = s.isHappy(19);
    cout << res;
}