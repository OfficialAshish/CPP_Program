#include <bits/stdc++.h>
using namespace std;

int largestRectangleAreaTLE(vector<int> &heights)
{
    int area = INT_MIN;

    for (int i = 0; i < heights.size(); i++)
    {
        int right = -1, left = -1;
        int j = i, curr = heights[i];
        while (j != -1 and heights[j--] >= curr)
        {
            left++;
        }
        j = i;
        while (j < heights.size() and heights[j++] >= curr)
        {
            right++;
        }
        area = max(area, (heights[i] * (left + right + 1)));
    }
    return area;
}

vector<int> nextSmallerElem(vector<int> heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElem(vector<int> heights, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> next(n), prev(n);
    next = nextSmallerElem(heights, n);
    prev = prevSmallerElem(heights, n);
    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int newArea, l, b;
        l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        b = next[i] - prev[i] - 1;

        newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(v);
}