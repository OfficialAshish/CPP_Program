#include <iostream>
#include <string>
using namespace std;

void compressStr(string &s)
{
    int i = 0, j = 1;
    string tmp = "";

    while (i < s.length())
    {
        if (s[i] == s[j])
        {
            j++;
            continue;
        }
        else
        {
            if (j - i > 1)
            {
                string t = to_string((j - i));
                tmp += s[i];
                tmp += t;
                i = j;
                j = i + 1;
            }
            else

                tmp += s[i++];
        }
    }
    s = tmp;
}

int main()
{
    string st = "abbbcccccccccccccccccccccccccccdee";
    compressStr(st);

    cout << st;
}