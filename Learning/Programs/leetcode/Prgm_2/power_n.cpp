#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int powerOfN(int x, int n)
    {
        long long unsigned int res = 1;
        // if n is odd
        while (n > 0)
        {
            if (n & 1)
            {
                res = 1LL * (res * x);
            }
            x = 1LL * (x * x);
            cout << "\nn: " << n << " res : " << res << " x: " << x;
            n = n >> 1; // dividing by 2
        }
        cout << endl;
        return 1ll * res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.powerOfN(2, 25);

    return 0;
}
