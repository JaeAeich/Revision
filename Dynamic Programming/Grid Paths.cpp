#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1638

int m = 1e9 + 7;

long long int helper(vector<vector<int>> &dp, vector<vector<char>> &v, int i = 0, int j = 0)
{
    if (i >= v.size() || j >= v.size() || v[i][j] == '*')
        return 0;
    if (i == v.size() - 1 && j == v.size() - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    long long int down = helper(dp, v, i + 1, j) % m;
    long long int right = helper(dp, v, i, j + 1) % m;

    return dp[i][j] = (right + down) % m;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> v;
    for (int i = 0; i < n; i++)
    {
        vector<char> temp;
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans = helper(dp, v);
    cout << ans;
    return 0;
}

// Code By - Jae Aeich