#include <iostream>
using namespace std;

int main()
{
    int length;
    cout << "\nEnter length: ";
    cin >> length;

    cout << endl;
    for (int i = 1; i <= length; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                cout << 0 << " ";
            }
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}