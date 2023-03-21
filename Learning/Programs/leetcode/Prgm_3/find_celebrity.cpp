//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

private:
    bool knows(int a, int b, vector<vector<int>> &M)
    {
        if (M[a][b] == 1 && a != b)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s1;
        for (int i = 0; i < n; i++)
        {
            s1.push(i);
        }

        while (s1.size() > 1)
        {
            int A, B;
            A = s1.top();
            s1.pop();
            B = s1.top();
            s1.pop();
            if (knows(A, B, M))
            {
                s1.push(B);
            }
            else if (knows(B, A, M))
            {
                s1.push(A);
            }
            // else

            // verify
            bool chk = false;
            // for(int i = 0; i<n; i++)
            // {
            bool rc = true, cc = true;
            for (int j = 0; j < n; j++)
            {
                if (M[s1.top()][j] != 0)
                    rc = false;
            }
            for (int j = 0; j < n; j++)
            {
                if (M[j][s1.top()] != 1 && s1.top() == j)
                    cc = false;
            }

            // }
            if (rc == true && cc == true)
            {
                return s1.top();
            }
            else
                return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

private:
    bool knows(int a, int b, vector<vector<int>> &M)
    {
        if (M[a][b] == 1 && a != b)
            return true;
        else
            return false;
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s1;
        for (int i = 0; i < n; i++)
        {
            s1.push(i);
        }

        while (s1.size() > 1)
        {
            int A, B;
            A = s1.top();
            s1.pop();
            B = s1.top();
            s1.pop();
            if (knows(A, B, M))
            {
                s1.push(B);
            }
            else if (knows(B, A, M))
            {
                s1.push(A);
            }
            // else

            // verify
            bool chk = false;
            // for(int i = 0; i<n; i++)
            // {
            bool rc = true, cc = true;
            for (int j = 0; j < n; j++)
            {
                if (M[s1.top()][j] != 0)
                    rc = false;
            }
            // for (int j = 0; j < n; j++)
            // {
            //     if (M[j][s1.top()] != 1 && s1.top() == j)
            //         cc = false;
            // }

            // }
            if (rc == true && cc == true)
            {
                return s1.top();
            }
            else
                return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends