#include <iostream>
using namespace std;

int main()
{
    int height;
    cout << "\nEnter height: ";
    cin >> height;

    cout << endl;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 1, k = 1; j <= 2*height; ++j)
        {
            // cout<<mid<<endl;
            if (j > i)
            {
                cout << k << " ";
                k++;
                if (k-1==height-i)
                {
                    break;
                }
                
            }
            else cout<<" ";
        }
        cout << endl;
    }
    /*
    //reverse
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1, k = 1; j <= 2*height; ++j)
        {
            if (j > height-i )
            {
                cout << k <<" ";
                k++;
                if (k-1==i)
                {
                    break;
                }
                
            }
            else cout<<" ";//if double spaces new pattern!
        }
        cout << endl;
    }
    */
   
    return 0;
}