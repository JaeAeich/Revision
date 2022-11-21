#include <bits/stdc++.h>
using namespace std;

/*Moore's voting algorithm is used to find the majority element in an array given that frequency of it is
more than n/2 +1.

Time complexity:- O(N)
Space complexity :- O(1)

NOTE:-If we used a hash map time complexity would have been the same but the space complexity would be O(N),
      but there we could find all the frequencies butin this algo its essential for majority ele to have freq
      greater than half the size of array.

REFERENCE LINK:-https://youtu.be/7pnhv842keE
                https://youtu.be/AoX3BPWNnoE
QUESTION LINK:-https://leetcode.com/problems/majority-element/submissions/


*/

int FindMajorityEle(vector<int> &v)
{
    int maj_ele = 0, c = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // whenever count becomes zero , we will assume the ith ele to be maj_ele.
        if (c == 0)
        {
            maj_ele = v[i];
        }
        // If the ith ele is same as assumed maj_ele, increase the cout or vice-versa.
        if (v[i] == maj_ele)
        {
            c++;
        }
        else
        {
            c--;
        }
    }
    return maj_ele;
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
    int ans = FindMajorityEle(v);
    return 0;
}
// Code By - Jae Aeich