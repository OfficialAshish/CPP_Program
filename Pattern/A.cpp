#include <iostream>
using namespace std;

int main()
{
    int height, length;
    cout << "Enter height for A Shape : ";
    cin >> height;
    int mr, ml, shapeMid;

    shapeMid = height / 2;

    length = height * 2;

    if (length % 2 == 0)
    {
        mr = length / 2;
        ml = mr + 1;
    }
    else
    {
        mr = ml = length / 2;
    }

    for (int i = 1; i < shapeMid; ++i)
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

    // cout << mr << "&" << ml;

    for (int i = 1; i <= shapeMid + 1; ++i)
    {
        for (int j = 1; j <= length; ++j)
        {
            if ((j >= mr and j <= ml) and mr == shapeMid + 1)
            {
                cout << "*";
            }
            else if (j == mr or j == ml)
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
    // cout << mr << "&" << ml;
}
