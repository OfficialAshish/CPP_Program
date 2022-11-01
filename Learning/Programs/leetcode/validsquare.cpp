#include <bits/stdc++.h>
using namespace std;

double dist(vector<int> pn1, vector<int> pn2)
{
    double ans = (sqrt(pow(pn1[0] - pn2[0], 2) + pow(pn1[1] - pn2[1], 2)));
    return ans;
}
bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    vector<double> lst(6, 0);
    lst[0] = dist(p1, p2);
    lst[1] = dist(p1, p3);
    lst[2] = dist(p1, p4);
    lst[3] = dist(p2, p3);
    lst[4] = dist(p2, p4);
    lst[5] = dist(p3, p4);
    for (auto ls : lst)
    {
        cout << ls << ", ";
    }
    sort(lst.begin(), lst.end());

    if ((lst[0] == lst[1]) && (lst[1] == lst[2]) && (lst[2] == lst[3]) && (lst[4] == lst[5]))
    {
        if (lst[0] == 0)
            return false;
        else
            return true;
    }
    else
        return false;
}

bool sqvl(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) /// diagonals
{
    if (abs(p1[0] - p3[0]) == abs(p3[0] - p4[0]) && abs(p2[1] - p4[1]) == abs(p2[1] - p4[1]))
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    vector<int> p1 = {0, 1};
    vector<int> p2 = {1, 2};
    vector<int> p3 = {0, 2};
    vector<int> p4 = {0, 0};
    cout << validSquare(p1, p2, p3, p4);
    // cout << sqvl(p1, p2, p3, p4);
    return 0;
}
