#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &v)
{
    int ans = 0;
    int f = 0;
    for (auto val : v)
    {
        if (val == 1)
        {
            f++;
            ans = max(ans, f);
        }
        else
            f = 0;
    }
    return ans;
}

// Code By - Jae Aeich