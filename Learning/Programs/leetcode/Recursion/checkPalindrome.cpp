#include <iostream>
using namespace std;

/* bool isPalindrome(string s, int t = 0)
{
    if (t >= s.size() / 2)
    {
        return true;
    }
    if (s[t] != s[s.size() - 1 - t])
    {
        return false;
    }
    return isPalindrome(s, t + 1);
}
 */

bool isPalindrome(string s, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}

int main(int argc, char const *argv[])
{
    string st = "nayyan";

    cout << isPalindrome(st, 0, st.size() - 1);

    return 0;
}
