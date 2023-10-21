#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1637

map<char, int> m;

long long int helper(vector<int> &dp, int n)
{
    if (n < 0)
        return INT_MAX;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    string s = to_string(n);
    long long int ans = INT_MAX;
    for (auto c : s)
    {
        if (c == '0')
            continue;
        ans = min(ans, 1 + helper(dp, n - m[c]));
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    m['1'] = 1;
    m['2'] = 2;
    m['3'] = 3;
    m['4'] = 4;
    m['5'] = 5;
    m['6'] = 6;
    m['7'] = 7;
    m['8'] = 8;
    m['9'] = 9;
    vector<int> dp(n + 1, -1);
    int ans = helper(dp, n);
    cout << ans;
    return 0;
}

// Code By - Jae Aeich