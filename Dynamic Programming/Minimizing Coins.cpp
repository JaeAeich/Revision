#include <bits/stdc++.h>
using namespace std;

long long int helper(vector<int> &dp, vector<int> &v, int k)
{
    if (k == 0)
        return 0;

    if (dp[k] != -1)
        return dp[k];

    long long int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= k)
        {
            ans = min(ans, 1 + helper(dp, v, k - v[i]));
        }
    }

    return dp[k] = ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> dp(k + 1, -1);
    int ans = helper(dp, v, k);
    ans = ans == INT_MAX ? -1 : ans;
    cout << ans;
    return 0;
}

// Code By - Jae Aeich