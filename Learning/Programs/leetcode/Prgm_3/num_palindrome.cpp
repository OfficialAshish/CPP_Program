#include <iostream>
using namespace std;

bool palin(string s)
{
    bool ans;
    if (s.length() < 2)
    {
        return true;
    }
    if (s.front() == s.back())
    {
        s.erase(s.begin(), s.begin() + 1);
        s.pop_back();
        cout << s << ", ";
        ans = palin(s);
    }
    else
        return false;
    return ans;
}

bool isPalindrome(int x)
{
    string s = to_string(x);
    return palin(s);
}

int main()
{
    cout << isPalindrome(44663644);
    return 0;
}
