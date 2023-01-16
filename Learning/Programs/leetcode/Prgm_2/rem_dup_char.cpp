#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "aabbbaabbaa";

    int i = 0, j = 1;
    while (j < s.length())
    {
        if (s[i] == s[j])
        {
            s.erase(j,1);
            // cout<<s<<", ";
            continue;
        }
        i++;
        j++;
    }
    cout << s;
}