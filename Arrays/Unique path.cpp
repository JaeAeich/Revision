#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : 

Simple PnC question, in how maky ways can you arrange n R's and m D's.

TC : O(min(m,n))
SC : O(1)
*/

// calculating nCr
long long C(int n, int r)
{
    if (r > n - r)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

int uniquePaths(int m, int n)
{
    // to traverse this matrix, m-1 Downs and n-1 Rights are needed
    // so in total m+n-2 places ans m-1 one kind of thing ans n-1 other things need to be arranged
    // ie C((m+n-1),(m-1))
    int a = m + n - 2;
    int b = m - 1;
    return C(a, b);
}
// Code By - Jae Aeich