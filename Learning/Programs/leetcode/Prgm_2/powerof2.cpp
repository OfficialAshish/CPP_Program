#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        int p = 1, i = 0;
        while (1)
        {
            if (n == p)
            {
                return true;
                break;
            }
            else if (n < p)
            {
                break;
            }

            p = pow(2, ++i);
            cout << " P:" << p;
            cout << endl;
        }
        cout << endl;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.isPowerOfTwo(10734);
    return 0;
}
