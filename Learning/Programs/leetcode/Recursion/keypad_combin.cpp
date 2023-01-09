#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> keypad = {",", ".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combKey(string digit, vector<string> &ans, string output = "", int i = 0)
{
    if (i >= digit.size())
    {
        ans.push_back(output);
        return;
    }
    int num1 = digit[i] - '0';
    string tmp = keypad[num1];

    for (int j = 0; j < tmp.size(); j++)
    {
        output.push_back(tmp[j]);
        combKey(digit, ans, output, i + 1);
        output.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    string press = "24";
    vector<string> ans;
    combKey(press, ans);

    for (auto i : ans)
    {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
