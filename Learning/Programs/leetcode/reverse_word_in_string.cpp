#include <iostream>
#include <string>
using namespace std;

void reverseWord(string &s)
{
    int i = 0, j = 0, tmp;

    while (i < s.size())
    {
        while (s[j] != ' ' and j < s.size())
            j++;
        tmp = j + 1; // next char after space
        j--;         // before space
        cout << j;
        while (i <= j)
        {
            swap(s[i++], s[j--]);
        }
        i = j = tmp;
    }
}

int main(int argc, char const *argv[])
{
    string st = "Hye its Ashish here !.";
    reverseWord(st);
    cout << st;
    return 0;
}
