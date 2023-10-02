
#include <iostream>
using namespace std;

int getSteps(int n, int i, vector<int> &dp)
{

    if (i > n)
        return 0;
    if (i == n)
        return 1;

    if (dp[i] != -1)
        return dp[i];

    dp[i] = getSteps(n, i + 1, dp) + getSteps(n, i + 2, dp);
    return dp[i];
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    //  return getSteps(n,0, dp );

    // /bottom up appr
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

int countDistinctWays(int n) {
    vector<int> dp(n + 1, -1);

    // /bottom up appr
    dp[0] =1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] =( dp[i - 1] + dp[i - 2]) % 1000000007 ;
    return dp[n] ;
}
