#include <bits/stdc++.h>
using namespace std;

// This is linear algorithm to calculate fib.
int fibON(long n)
{
    int prev2 = 0, prev1 = 1;
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        ans = prev1 + prev2;
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    fibON(n);
    return 0;
}
// Code By - Jae Aeich