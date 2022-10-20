#include <iostream>

using namespace std;
/*
string moveallx(string s)
{
    if (s == "")
    {
        return "";
    }

    char a = s[0];
    string ans = moveallx(s.substr(1));

    if (a == 'x')
    {
        return ans + a;
    }
    else if (a == ans[0]) // removes repetition
    {
        return ans;
    }
    else
        return (a + ans);
}
*/

void moveallx(string s)
{
    if (s == "")
        return;
    int i = 0;
    while (s[i++] != 'x')
        cout << s[i - 1];
    moveallx(s.substr(i));
    cout << "x";
}

int main(int argc, char const *argv[])
{
    string s = "aaasssxsddxkfxerxtx";
    // cin >> s;
    // cout << moveallx(s);
    moveallx(s);
    return 0;
}
