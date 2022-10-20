#include <iostream>
#include <string>

using namespace std;

void permuteStr(string st)
{
    int i = 0;
    char strArr[st.size() + 1];
    for (i; i < st.size(); i++)
    {
        strArr[i] = st.at(i);
    }
    strArr[i] = '\0';

    // permt...
    int j1, j2, j3, j4, j5, j6;
    j1 = j2 = j3 = j4 = j5 = j6 = 0;
    for (int i = 0; i <= 100000; i++)
    {
        for (int j = 0; j < st.size(); j++)
        {
            cout << strArr[j1] << strArr[j2] << strArr[j3] << strArr[j4] << strArr[j5] << strArr[j6] << endl;
            j6++;
            if (j6 > 5)
            {
                j5++;
                j6 = 0;
            }
            else if (j5 > 5)
            {
                j4++;
                j5 = 0;
            }
            else if (j4 > 5)
            {
                j3++;
                j4 = 0;
            }
            else if (j3 > 5)
            {
                j2++;
                j3 = 0;
            }
            else if (j2 > 5)
            {
                j1++;
                j2 = 0;
            }
            else if (j1 > 5)
            {
                cout << "\nPrinted all! \n";
                exit(0);
            }
        }
    }

    // printf("%s", strArr);
}

int main(int argc, char const *argv[])
{
    string strr = "ASHISH";
    permuteStr(strr);
    return 0;
}
