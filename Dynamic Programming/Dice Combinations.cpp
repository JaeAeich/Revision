#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<int> dp;

int helper(int n)
{
    if (n <= 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = 0;

    for (int i = 1; i <= 6; i++)
    {
        if (i <= n)
            ans = ((ans % mod) + helper(n - i) % mod) % mod;
    }
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    dp.resize(n + 1);
    fill(begin(dp), end(dp), -1);
    int ans = helper(n);
    cout << ans;
    return 0;
}

// Code By - Jae Aeich
