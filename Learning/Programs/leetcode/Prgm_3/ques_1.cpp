
#include <iostream>
using namespace std;

string displayScreen(string &s)
{
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != 'B')
        {
            res += s[i];
        }
        else if (res.length() > 0)
        {
            res.erase(res.length() - 1, 1);
        }
        return res;
    }
}
int main()
{
    string ss = "0011BB11";
    cout << displayScreen(ss);
}
