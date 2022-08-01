#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "\nEnter length: ";
    cin >> length;

    cout << endl;
    for (int i = length; i > 0; --i)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    // cout << endl;
    for (int i = 1; i <=length; ++i)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}