#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
Create a window with non repeating characters, lets that window be j .. i, len of this window will be
i-j+1, now if we encounter a repeating character in this window then we will remove all the characters
from the window till the repeating character is removed, and then we will add the repeating character.

TC : O(N)
SC : O(N)
*/

int lengthOfLongestSubstring(string s)
{
    if (s.length() <= 1)
        return s.length();
    unordered_map<char, int> m;
    // Atleast len will be 1
    int len = 1;
    int j = 0;

    // Go through all the characters
    for (int i = 0; i < s.length(); i++)
    {

        // If this ele has been see in this window of j..i
        if (m.find(s[i]) != m.end())
        {
            int tempJ = m[s[i]] + 1;

            // Shorten the window by removing all the ele  till the one visited
            for (int k = j; k < tempJ; k++)
            {
                m.erase(s[k]);
            }
            j = tempJ;
        }

        // Update len
        len = max(len, i - j + 1);

        // Hash this ele
        m[s[i]] = i;
    }
    return len;
}
// Code By - Jae Aeich