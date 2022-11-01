#include <iostream>
using namespace std;

int squareRoot(int n)
{
    int st = 0, en = n; // 0-n
    int mid = n / 2;
    int ans = -1;
    while (st <= en)
    {
        mid = st + (en - st) / 2;
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            en = mid - 1;
        }
        else if (mid * mid < n)
        {
            st = mid + 1;
            ans = mid;
        }
        else
            break;
    }
    return ans;
}

double precn(int &temp, int prc_upto, int orgnl)
{
    double ans = temp;
    double factor = 1;
    for (int i = 1; i <= prc_upto; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < orgnl; j = j + factor)
        {
            ans = j;
            // cout << j << endl;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int a = 53;
    int res = squareRoot(a);
    double ans = precn(res, 6, a); // max 5
    cout << ans;
    return 0;
}
