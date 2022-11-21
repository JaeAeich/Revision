#include <bits/stdc++.h>
using namespace std;
/*
Problem Link:https://leetcode.com/problems/sum-of-subarray-minimums/

Problem :Given an array of integers arr, find the sum of min(b), where b ranges over every
        (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

eg:
    Input: arr = [3,1,2,4]
    Output: 17
    Explanation:
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.
*/

int m = 1e9 + 7;

////brute force O(N^2)
// int sumSubarrayMins(vector<int>& v) {
//     int n=v.size();
//     long long int ans=0;
//     for(int i=0;i<n;i++){
//         int minn=INT_MAX;
//         for(int j=i;j<v.size();j++){
//             minn=min(minn,v[j]);
//             ans+=minn;
//             ans%=m;
//         }
//     }
//     return ans;
// }

// TC:O(N),SC:O(N)
// Stacks
int sumSubarrayMins(vector<int> &v)
{
    int n = v.size();
    long long int ans = 0;
    stack<int> s;
    // if nse doesn't exist imagine ne to be at an imaginary idx n, similarly for pse.
    vector<int> nse(n, n);
    vector<int> pse(n, -1);
    // finding pse and nse.
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {
            nse[s.top()] = i;
            s.pop();
        }
        if (s.size())
            pse[i] = s.top();
        s.push(i);
    }
    /*Note: Num of subarray containing an ele x can be found by:
            if array is: a b c x d e
                        right side brace can be at 4 pos.
                        similarly left side braces can be in  3 pos.
                        for eg: a b (c x d) e  etc etc

                        hence tot subarray = 4*3 = 12
    */

    // Using the same logic above we can find in how many subarray ith ele is min.
    for (int i = 0; i < v.size(); i++)
    {
        int j = pse[i], k = nse[i];
        /*ith ele is min in f subarrays, hence its contribution to ans will be v[i]*f.
            i.e. for ele 1 in : _ 3,1,2,4 _(see test case eg)
                                ^         ^
                                |         |
                        img idx -1      img idx n

                        right brace can be in space b/w right arrow and ele 1,
                                            totol right braces=2
                        similarly total left braces can be b/w left arrow and ele 1,
                                            total left braces=3

                                            so f=2*3.
        */
        int f = (i - j) * (k - i);
        ans += (v[i] * 1LL * f) % m;
        ans %= m;
    }
    return ans;
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << sumSubarrayMins(v);
    return 0;
}
// Code By - Jae Aeich