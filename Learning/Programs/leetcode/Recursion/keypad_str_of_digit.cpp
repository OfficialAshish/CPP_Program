#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> keypad = {"", ",.!?", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void combKey(string digit, string &ans)
{
    if (digit.size() == 0)
        return;
    int count = 0, i = 0;
    while (digit[i] == digit[i + 1])
    {
        count++;
        i++;
    }
    int num = digit[0] - '0';
    string tmp = keypad[num];
    if (num == 9 or num == 7)
    {
        ans += tmp[count % 4];
    }
    else
        ans += tmp[count % 3];
    digit.erase(0, count + 1);
    combKey(digit, ans);
}

int main(int argc, char const *argv[])
{
    string press = "22227777440444777744111";
    string ans;
    combKey(press, ans);
    cout << "Keypad String for numbers (" << press << ") is: " << ans;
    return 0;
}
