#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return (n && !(n & n - 1)); // n ,n-1 is having complement bit before first first 1 from right..
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.isPowerOfTwo(16);
    return 0;
}

/*
class Solution {
public:
    bool por(int num) {
        int bit =0;
        while (num != 0 && bit ==0)
        {
            bit = (num >>1) & 1;
            if(num == 1) return true;
            num = num >>1;
        }
        return false;
    }
}; */