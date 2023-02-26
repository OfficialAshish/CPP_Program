#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "codeleet";
    string suffle = s;
    int indices[] = {4, 5, 6, 7, 0, 2, 1, 3};

    for (int i = 0; i < 8; i++)
    {
        int index = indices[i];
        suffle[index] = s[i];
    }
    cout << suffle << endl;
}