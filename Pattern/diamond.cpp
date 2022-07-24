#include <iostream>

using namespace std;

int main()
{
    cout << "Enter length: ";
    int length, mid, mr, ml;
    cin >> length;

    if (length % 2 == 0)
    {
        mid = length / 2;
        mr = mid;
        ml = mid + 1;
    }
    else
    {
        mid = (length / 2) + 1;
        mr = ml = mid;
    }

    cout << endl;
    for (int i = 1; i < mid; ++i)
    {
        for (int j = 1; j <= length; ++j)
        {
            if (j == mr or j == ml)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        mr--;
        ml++;
        cout << endl;
    }

    mr++;
    ml--;

    for (int i = 1; i < mid; ++i)
    {
        for (int j = 1; j <= length; ++j)
        {
            if (j == mr or j == ml)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        mr++;
        ml--;
        cout << endl;
    }
}
