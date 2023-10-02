#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, vector<int> &dp, int i = 0) {
  if (i >= nums.size())
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int incl = solve(nums, dp, i + 2);
  int excl = solve(nums, dp, i + 1);

  int ans = max(incl + nums[i], excl + 0);
  dp[i] = ans;
  return ans;

  /*
  // normal recursion
  if(i >= nums.size()) return 0;

   int incl = solve(nums, i+2);

   int excl = solve(nums, i+1);

   int ans = max(incl + nums[i], excl+0);

   return ans; */
}
int maximumNonAdjacentSum(vector<int> &nums) {

  vector<int> dp(nums.size(), -1);

  //   return solve(nums, dp);

  // tabulation
  /*
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1] + 0, dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
   */
  if (nums.size() == 1)
    return nums[0];
  if (nums.size() == 2)
    return max(nums[0], nums[1]);
  int p1 = nums[0];
  int p2 = max(nums[1], p1), curr;

  for (int i = 2; i < nums.size(); i++) {
    curr = max(p1 + nums[i], p2);
    p1 = p2;
    p2 = curr;
  }
  return curr;
}