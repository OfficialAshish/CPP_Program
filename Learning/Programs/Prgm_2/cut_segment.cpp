#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> memo;

int solve(int n, vector<int> &seg) {
    // Base case: If 'n' is negative, return 0
    if (n < 0) return 0;

    // Base case: If 'n' is exactly 0, return 1 (no further cuts needed)
    if (n == 0) return 1;

    // Check if the result for 'n' is already calculated and stored in the memoization table
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int an1 = solve(n - seg[0], seg);
    int an2 = solve(n - seg[1], seg);
    int an3 = solve(n - seg[2], seg);

    // Calculate the maximum number of segments for 'n' by considering all possible combinations
    int max_segments = max(an1, max(an2, an3));

    // Store the result in the memoization table and return it
    memo[n] = max_segments + 1; // Add 1 for the current cut
    return memo[n];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> seg = {x, y, z};

    int ans = solve(n, seg);
    return ans - 1; // Subtract 1 because the initial cut isn't counted

}

int main() {
    // Sample Input
    int n = 2;
    int x = 7;
    int y = 5;
    int z = 2;

    // Calculate the maximum number of segments
    int result = cutSegments(n, x, y, z);
    cout << result << endl;

    return 0;
}
