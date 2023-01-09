#include <iostream>
#include <string>
#include <vector>
using namespace std;

void subSequence(string v, vector<string> &as, string output = {}, int i = 0)
{
    if (i >= v.size())
    {
        as.push_back(output);
        return;
    }

    // exld
    subSequence(v, as, output, i + 1);
    // incl
    output.push_back(v[i]);
    subSequence(v, as, output, i + 1);
}

int main(int argc, char const *argv[])
{
    string vc = "ABC";
    vector<string> ans;
    subSequence(vc, ans);

    for (auto i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
