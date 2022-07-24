#include <iostream>
using namespace std;

int main()
{
    int length, height;
    cout << "\nEnter length: ";
    cin >> length;
    // cout << "\nEnter height: ";
    // cin >> height;
    int mid ;

    char ml, mr;
    if (length % 2 == 0)
    {
        mr = length / 2;
        ml = mr + 1;
        mid = mr;
    }
    else
    {
        mr = (length / 2) + 1; //+1 for 2.5 to 3
        ml = mr;
        mid = mr;
    }

    // updating to char
    mr += 64;
    ml += 64;
    length += 64;

    // cout << mr << "&" << ml << endl;
    cout << endl;
    for (int i = 1; i <= mid; i++) //+1for both even/odd
    {
        for (char ch = 'A'; ch <= length; ch++)
        {
            if (ch > mr and ch < ml)
            {
                cout << " ";
            }
            else
            {
                cout << ch;
            }
        }
        mr--;
        ml++;
        cout << endl;
    }
    return 0;
}