#include <vector>

#define MOD 1000000007

long long int solveM(int n, vector<long long int> &dp) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = ((n - 1) * (solveM(n - 1, dp) + solveM(n - 2, dp))) % MOD;
  return dp[n];
}

long long int countDerangements(int n) {
  vector<long long int> dp(n + 1, -1);
  return solveM(n, dp);
}