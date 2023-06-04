#include <bits/stdc++.h>
using namespace std;

/*
The idea is to keep track of the smallest stock price so far and keep updating whenever we find a greater profit.
*/

int maxProfit(vector<int> &v)
{
    // Profit will atleast be 0, sell on the same day
    int ans = 0;

    // We to keep track of the lowest price on the prev days.
    int prev = v[0];

    // Iterate
    for (int i = 1; i < v.size(); i++)
    {
        // If the profit from buying on the prev lowest val
        // and selling today is greater than other, update the ans.
        ans = max(v[i] - prev, ans);

        // If price of this day is smaller that prev, update.
        if (v[i] < prev)
            prev = v[i];
    }
    return ans;
}

// Code By - Jae Aeich
