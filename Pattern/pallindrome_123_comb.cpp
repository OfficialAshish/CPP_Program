#include <iostream>
using namespace std;

int main()
{
    int length, height;
    cout << "\nEnter height: ";
    cin >> height;
    length = height * 2;

    cout << endl;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < i; ++j)
        {
            cout << "  ";
        }
        for (int k = height - i; k >= 2; --k)
        {
            cout << k << " ";
        }
        for (int l = 1; l <= height - i; ++l)
        {
            cout << l << " ";
        }
        cout << endl;
    }

    // reverse
    for (int i = 0; i < height; i++)
    {
        for (int j = height - i - 1; j > 0; --j)
        {
            cout << "  ";
        }
        for (int k = i + 1; k >= 2; --k)
        {
            cout << k << " ";
        }
        for (int l = 1; l <= i + 1; ++l)
        {
            cout << l << " ";
        }
        cout << endl;
    }

    return 0;
}