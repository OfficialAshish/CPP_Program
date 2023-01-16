#include <iostream>

using namespace std;

int main()
{
    int i = 1;
    // cout << (i++) << "and" << (i++) << "&" << i;
    cout << i++ << " a, " << i++ << " b, " << i << " c, " << i++ << endl;
    printf("%d,%d,%d,%d", i++, i++, i, i++);
    printf("%d,%d,%d,%d,%d,%d,%d,%d", i++, i++, i, i++, i++, i++, i, i++);
}