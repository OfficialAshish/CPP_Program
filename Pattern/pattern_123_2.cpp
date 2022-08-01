#include <iostream>
using namespace std;

int main()
{
    int height;
    cout << "\nEnter height: ";
    cin >> height;

    cout << endl;
    for (int i = 0; i <= height; ++i)
    {
        for (int j = 1, k = 1, mid = height / 2; j <= height; ++j, ++k)
        {
            // cout<<mid<<endl;
            if (j >= mid + i-1)
            {
                cout << " " << k;
            }
            else cout<<" ";
        }
        cout << endl;
    }
    return 0;
}