#include <iostream>
using namespace std;

int main()
{
    int length, height;
    cout << "\nEnter height: ";
    cin >> height;
    length = height * 2;

    cout << endl;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1, right = 1, left = i, mid = height; j <= length; j++)
        {
            if (j >= mid)
            {
                cout << right++ << " ";
                if (right - 1 == i)
                {
                    break;
                }
            }
            else if (j < mid && (j > mid - i))
            {
                cout << (left--) << " ";
                /* if (left + 1 == 2)
                {
                    continue;
                } */
            }
            else if (j < mid)
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}