#include <iostream>
#include <string>
using namespace std;

/*
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
 */

/*
void compressStr(string &s)
{

    int i = 0, j = 1;
    while (i < s.length())
    {
        if (s[i] == s[j])
        {
            j++;
            continue;
        }
        // j points to last+1 repeating char
        if (j - i > 1)
        {
            int count = j - i, k = 0;
            string tmp = to_string(count);
            while (k < tmp.length())
            {
                s[i + 1] = tmp[k++];
                i++;
            } // i points to last value index of integer, and k points to num of char of tmp
            s.erase(i + 1, count - (k + 1));
            // its now new string
            i = i + 1;
            j = i + 1;
            continue;
        }
        i++;
        j = i + 1;
    }
} */

void compressStr(string &s)
{
    int i = 0, j = 1, currIdx = 0;

    while (i < s.size())
    {
        while (s[i] == s[j])
        {
            j++;
        }
        s[currIdx++] = s[i];
        int count = j - i;
        if (count > 1)
        {
            string tm = to_string(count);
            for (char c : tm)
            {
                s[currIdx++] = c;
            }
        }
        i = j;
        j = i + 1;
    }
    s.erase(currIdx, s.size() - currIdx);
}

int main()
{
    string st = "abbbcccccccccccccccccccccccccccdee";
    compressStr(st);

    cout << st;
}