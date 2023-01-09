
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> cot;
    int maxFrq = 0, maxAns = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        cot[arr[i]]++;
        maxFrq = max(maxFrq, cot[arr[i]]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFrq == cot[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(int argc, char const *argv[])
{
    vector<int> a = {2, 3, 3, 4, 4};
    cout << maximumFrequency(a, 3);

    return 0;
}
