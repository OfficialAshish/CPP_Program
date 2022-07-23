#include <iostream>
using namespace std;

int main()
{
    int length, height;
    cout << "\nEnter length: ";
    cin >> length;
    // cout << "\nEnter height: ";
    // cin >> height;
    height = (length / 2)+1;
    int mr, ml;

    if (length % 2 == 0)
    {
        mr = length / 2;
        ml = mr + 1;
    }
    else
    {
        mr =1 +( length / 2);
        ml = mr;
    }
    cout << mr << "&" << ml << endl;
    cout << endl;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if ((j == mr or j == ml) && (j > 1 or j < length - 2))
            {
                cout << "*";
                // cout << mr << "&" << ml << "j: " << j << endl;
            }
            else if (mr == 1 )//and ml < length-1
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        mr--;
        ml++;
        cout << endl;
    }
    return 0;
}