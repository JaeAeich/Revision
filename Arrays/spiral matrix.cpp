#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &v)
{
    // top, left , bottom, right pointer to make matrix smaller .
    int t = 0, b = v.size() - 1, l = 0, r = v[0].size() - 1;
    vector<int> ans;
    int c = 1;
    // direction variable
    int dir = 0;
    while (t <= b && l <= r)
    {
        // left to right traversal
        if (dir == 0)
        {
            for (int i = l; i <= r; i++)
            {
                ans.push_back(v[t][i]);
            }
            // increasing top var so that , that row is not visited again.
            t++;
        }
        // for top to bottom
        if (dir == 1)
        {
            for (int i = t; i <= b; i++)
            {
                ans.push_back(v[i][r]);
            }
            r--;
        }
        // for right to left
        if (dir == 2)
        {
            for (int i = r; i >= l; i--)
            {
                ans.push_back(v[b][i]);
            }
            b--;
        }
        // for bottom to top
        if (dir == 3)
        {
            for (int i = b; i >= t; i--)
            {
                ans.push_back(v[i][l]);
            }
            l++;
        }
        dir = (++dir) % 4;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> M[i][j];
        }
    }
    vector<int> ans = spiralOrder(M);
    for (auto val : ans)
    {
        cout << val << " ";
    }
    return 0;
}

////Similarly a program to make a matrix in spiral order filling with squares of numbers

// int pow(int a){
//     return a*a;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<vector<int>> v(n,vector<int>(n));

//     int t=0,l=0,r=n-1,b=n-1;
//     int dir=0;

//     int val=1;
//     while (t <= b && l <= r)
//     {
//         // left to right traversal
//         if (dir == 0)
//         {
//             for (int i = l; i <= r; i++)
//             {
//                 v[t][i]=pow(val++);
//             }
//             // increasing top var so that , that row is not visited again.
//             t++;
//         }
//         // for top to bottom
//         if (dir == 1)
//         {
//             for (int i = t; i <= b; i++)
//             {
//                 v[i][r]=pow(val++);
//             }
//             r--;
//         }
//         // for right to left
//         if (dir == 2)
//         {
//             for (int i = r; i >= l; i--)
//             {
//                 v[b][i]=pow(val++);
//             }
//             b--;
//         }
//         // for bottom to top
//         if (dir == 3)
//         {
//             for (int i = b; i >= t; i--)
//             {
//                 v[i][l]=pow(val++);
//             }
//             l++;
//         }
//         dir = (++dir) % 4;
//     }

//     for (auto vec : v)
//     {
//         for (auto val : vec)
//         {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// Code By - Jae Aeich