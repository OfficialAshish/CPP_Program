#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> arr(0);
    int elem;
    int n, i = 1;
    cout << "No. of Elem: ";
    cin >> n;
    cout << "\nEnter Elem: ";

    while (i++ <= n)
    {
        cin >> elem;
        arr.push_back(elem);
        // cout << elem;
    }

    int ans = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
        cout << ans << ", ";
    }
    cout << "\nUnique element is: " << ans;

    return 0;
}
