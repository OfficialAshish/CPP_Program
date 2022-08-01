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
        for (int j = 1, right = 1, mid = height; j <= length; j++)
        {
            if (j >= mid)
            {
                cout << right++ << " ";
                if (right -1== height - i+1)
                {
                    break;
                }
            }
            else if (j < mid && j > i-1)
            {
                cout << (height - j + 1) << " ";
                if (height - j == 2)
                {
                    continue;
                }
            }
            else if (j <= i)
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}