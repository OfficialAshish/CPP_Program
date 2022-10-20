#include <iostream>

using namespace std;

/*
string remDup(string s)
{
    if (s == "")
    {
        return "";
    }
    char a = s[0];
    string ans = remDup(s.substr(1));

    if (a == ans[0])
    {
        return ans;
    }
    else
        return (a + ans);
}
 */

void remDup(string s)
{
    char ch = s[0];
    int i = s.length(), j = 1;
    while (i--)
    {
        if (ch == s[j])
        {
            j++;
            continue;
        }
        else
        {
            cout << ch;
            ch = s[j++];
        }
    }
}

int main(int argc, char const *argv[])
{
    string s = "asshhiissshh";
    // cin >> s;
    // cout << remDup(s);
    remDup(s);
    return 0;
}
