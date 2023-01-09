Solution 1: Sqrt

Since a^2 + b^2 = c => a = sqrt(c - b^2) => a <= sqrt(c).
Traverse a in range [0..sqrt(c)], check if there exists bSquare (where bSquare = c - a^2) and bSquare is a square number then return True.
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        for a in range(int(sqrt(c))+1):
            b = sqrt(c - a*a)
            if b == int(b):
                return True
        return False
Complexity

Time: O(sqrt(c) * logC), where c <= 2^31-1.
The operation sqrt(x) takes O(logX), can check this problem 69. Sqrt(x).
Space: O(1)
✔️ Solution 2: Using HashSet

Pre-compute squares number in range [0...c] and add to our HashSet, let say squareSet.
Iterate aSquare in squareSet, if there exists bSquare (where bSquare = c - aSquare) in the squareSet then return True.
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        squareSet = set()
        for x in range(int(math.sqrt(c)) + 1):
            squareSet.add(x * x)

        for aSquare in squareSet:
            bSquare = c - aSquare
            if bSquare in squareSet:
                return True
        return False
Complexity

Time: O(sqrt(c)), where c <= 2^31-1
Space: O(sqrt(c))
✔️ Solution 3: Two Pointers

We can use Two Pointers to search a pair of (left, right), so that left^2 + right^2 = c.
Start with left = 0, right = int(sqrt(c)).
while left <= right:
Let cur = left^2 + right^2.
If cur == c then we found a perfect match -> return True
Else if cur < c, we need to increase cur, so left += 1.
Else we need to decrease cur, so right -= 1.
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        left = 0
        right = int(sqrt(c))
        while left <= right:
            cur = left * left + right * right
            if cur == c: return True
            if cur < c:
                left += 1
            else:
                right -= 1
        return False
Complexity

Time: O(sqrt(c)), where c <= 2^31-1
Space: O(1)