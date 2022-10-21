#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
void substring(string st, string ans)
{
    if (st.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = st[0];
    substring(st.substr(1), ans + ch);
    substring(st.substr(1), ans);
}
*/
/*
//combination...
void substring(string st)
{
    if (st == "")
    {
        cout << st << endl;
        return;
    }
    string ans = "";
    int i = 0, j = st.length();
    while (i != j)
    {
        ans = ans + st[i++];
        cout << ans << endl;
    }
    substring(st.substr(1));
}
 */

// permutation...
void substring(string st)
{
    do
    {
        cout << st << "\n";
    } while (next_permutation(st.begin(), st.end()));
}

int main(int argc, char const *argv[])
{
    string str = "ABC";
    // substring(str, "");
    substring(str);
    return 0;
}
