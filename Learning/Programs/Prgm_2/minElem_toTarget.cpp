#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> memo;  // Memoization table to store computed results

int minElementsRecursive(std::vector<int>& arr, int X) {
    // Base case: If X is 0, you don't need any elements.
    if (X == 0) {
        return 0;
    }

    // Check if the result is already computed for the current target sum X.
    if (memo.find(X) != memo.end()) {
        return memo[X];
    }

    int minCount = INT_MAX;

    // Iterate through the elements in the array and consider each element as a choice.
    for (int i = 0; i < arr.size(); i++) {
        int diff = std::abs(arr[i] - X);
        if (diff <= X) {
            int count = minElementsRecursive(arr, diff);
            if (count != INT_MAX) {
                minCount = std::min(minCount, count + 1);
            }
        }
    }

    // Memoize the result for the current target sum X.
    memo[X] = minCount;
    return minCount;
}

int main() {
    std::vector<int> arr = {1, 3, 5};
    int X = 11;
    int result = minElementsRecursive(arr, X);
    std::cout << result << std::endl;  // Output: 3 (1 + 5 + 5)
    return 0;
}



int minimumElements(vector<int> &num, int x) {

  vector<int> dp(x + 1, INT_MAX);

  dp[0] = 0;

  for (int amt = 1; amt <= x; amt++) {
    for (int i = 0; i < num.size(); i++) {
      if (amt - num[i] >= 0 and dp[amt - num[i]] != INT_MAX) {
        dp[amt] = min(dp[amt], 1 + dp[amt - num[i]]);
      }
    }
  }

  if (dp[x] == INT_MAX)
    return -1;
  return dp[x];
}

/* int minimumElements(vector<int> &num, int x)
{
    sort(num.begin(), num.end(), greater<int>()); // Sort the array in
descending order int count = 0; int sum = 0;

    for (int i = 0; i < num.size(); i++) {
        while (sum + num[i] <= x) {
            sum += num[i];
            count++;
            if (sum == x) {
                return count;
            }
        }
    }

    return -1;
} */