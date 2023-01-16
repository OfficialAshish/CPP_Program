#include <iostream>
#include <string>
using namespace std;

void removeOccr(string &s, string part)
{
    string tmp1 = "";
    int res = 1;
    for (int i = 0; i < s.length() - 2; i++)
    {
        // i = s.find(part);//index of first occr
        res = part.compare(s.substr(i, 3));
        if (res == 0)
        {
            while (i < s.length() - 3)
            {
                s[i] = s[i + 3];
                i++;
            }
            s.erase(i, i + 2);
            i = 0;
            res = 1;
        }
    }
    // cout<<s.substr(i,3) <<",  ";
}

int main(int argc, char const *argv[])
{
    string s = "daabcbaabcbc", part = "abc";
    removeOccr(s, part);
    cout << s;

    return 0;
}