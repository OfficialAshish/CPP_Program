#include <iostream>
using namespace std;

int main()
{
    int height;
    cout << "\nEnter height: ";
    cin >> height;

    cout << endl;
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1, k = 1, mid = 1 + (height / 2); j <= height; ++j)
        {
            // cout<<mid<<endl;
            if (j >= mid + i -3)
            {
                cout << " " << k;
                k++;
            }
            else cout<<" ";
        }
        cout << endl;
    }
    return 0;
}