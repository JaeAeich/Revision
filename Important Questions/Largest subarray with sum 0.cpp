/*
REFERENCE LINK:-https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category[]=Hash&category[]=Hash&company[]=Amazon&company[]=Amazon&page=1&query=category[]Hashcompany[]Amazonpage1company[]Amazoncategory[]Hash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

Statement:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N*log(N)).
Expected Auxiliary Space: O(N).
*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &v, int n)
{
    // Keeping a hash map(But we won't iterate completely through it.).
    map<int, int> m;
    int len = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        // If ith ele itself is zero and maxlen is 0 till now, update len to 1.
        if (v[i] == 0 && len == 0)
            len = 1;
        // If prefix sum itself becomes zero then max len will become i+1, not max(len,i+1) because prefix sum has longest subarray as it starts form idx 0.
        if (sum == 0)
            len = i + 1;
        // If sum already exists in hash map then we can substract that subarray from this one to get sum equal to zero.
        if (m.find(sum) != m.end())
        {
            len = max(len, i - m[sum]);
        }
        // Else push sum into hash map.
        else
        {
            m.insert({sum, i});
        }
    }
    return len;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return 0;
}
// Code By - Jae Aeich