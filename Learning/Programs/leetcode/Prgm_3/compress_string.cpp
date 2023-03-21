#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int compress(vector<char> &chars)
{
    vector<char> tmp;
    int cnt = 1;
    std::string s = "";
    int n = chars.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (chars[i] == chars[i + 1])
        {
            cnt++;
            continue;
        }
        if (cnt > 1 and cnt < 10)
        {
            tmp.push_back(chars[i]);
            tmp.push_back(cnt + '0');
        }
        else if (cnt >= 10)
        {
            s = to_string(cnt);
            tmp.push_back(chars[i]);

            for (int j = 0; j < s.size(); j++)
            {
                tmp.push_back(s[j]);
            }
        }
        else
        {
            tmp.push_back(chars[i]);
        }
        cnt = 0;
    }
    for (auto i : tmp)
    {
        cout << i << ", ";
    }
    swap(tmp, chars);
    return chars.size();
}

int main(int argc, char const *argv[])
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    cout << compress(chars);
    return 0;
}
