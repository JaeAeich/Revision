#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int helper(vector<int> &dp, vector<int> &v, int k)
{
    if (k == 0)
        return 1;

    if (dp[k] != -1)
        return dp[k];

    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= k)
        {
            ans = ((ans % m) + (helper(dp, v, k - v[i]) % m)) % m;
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
    // int ans = helper(dp, v, k);
    // cout << ans;

    for(int i = 0; i < n; i++){
        
    }
    return 0;
}
// Code By - Jae Aeich