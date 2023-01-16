#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string s1 = "abc";
    string s2 = "hello its me bca";
    vector<string> perm1;
    while (next_permutation(s1.begin(), s1.end()))
    {
        perm1.push_back(s1);
    }
    // for (auto i : perm1)
    // {
    //     cout << i << ", ";
    // }
    cout << endl;
    int ind = -1;
    for (int i = 0; i < perm1.size(); i++)
    {
        ind = s2.find(perm1[i]);
        // cout << ind << ".";
        if (ind != -1)
        {
            cout << "Present";
            return 0;
        }
    }
    cout << "Not Present! ";
}