#include <bits/stdc++.h>
using namespace std;

/*
REFERENCE LINK :-  1) https://youtu.be/fFVZt-6sgyo
                   2) https://youtu.be/20v8zSo2v18
*/

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
    // This map will store all the frequency of prefix sum.
    map<int, int> m;
    // zero added because we will be incrementing counter if prefixsum-k exists in map.
    // If first element is 1 and k is 1, then we will need zero to be in map as 1-1=0.
    m[0] = 1;
    int sum = 0;
    int c = 0;
    for (int val : v)
    {
        // calculate the prefix sum.
        sum += val;
        int diff = sum - k;
        // Lets say to this point we have created a sum , if we have some diff such that sum -diff=k
        // Then we can say we will be able to create our required sum.
        // If to this index we can create more than one diff , then we can create that many required subarrays.
        if (m.find(diff) != m.end())
        {
            // m[diff] represent frequncy of how many diff we can create till iht index.
            c += m[diff];
        }
        // Push back sum because maybe this can be a possible diff for some other prefix sum.
        if (m.find(sum) == m.end())
        {
            m[sum] = 1;
        }
        else
        {
            m[sum]++;
        }
    }
    return 0;
}
// Code By - Jae Aeich