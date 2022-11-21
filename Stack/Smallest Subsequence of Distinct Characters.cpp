#include <bits/stdc++.h>
using namespace std;
/*
Problem link:https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
Problem statement:Given a string s, return the lexicographically smallest subsequence
                  of s that contains all the distinct characters of s exactly once.

                  eg:Input: s = "bcabc"
                     Output: "abc"

REFERENCE LINK:https://youtu.be/j313ttNJjo0
*/
string smallestSubsequence(string s)
{
    // keeping a frequency array and a isIn array to check if the char is in stack or not.
    vector<int> f(26, 0);
    vector<bool> isIn(26, 0);
    /*stack is used because we want the string to be in increaing order, ie the most significant char
    should be of least value, this is like nge problem.*/
    stack<char> st;
    for (char c : s)
    {
        f[c - 'a'] += 1;
    }
    for (int i = 0; i < s.length(); i++)
    {
        /*if we have already pushed a char in stack we should operate on it because,
        case 1: lets say the string is "dab" and s[i]=d, we know pustting d afterwards would be
                benifitial but note such a senario of "dab" will never occur as in this case a would
                already popped this ele and d would never have been in stack so this conditional statement
                would never have executed.
        case 2: lets say the string in stack is "abc", if s[i] is a then pushing is on top of stack would
                make is lexicographically larger,so its better to not operrate on it.*/
        if (isIn[s[i] - 'a'] == true)
        {
            // decreasing the frequency as we have visitied this char.
            f[s[i] - 'a']--;
            continue;
        }
        while (!st.empty() && st.top() > s[i] && f[st.top() - 'a'] > 0)
        {
            // popping larger ele from the stack if the are in the string afterwards.
            isIn[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(s[i]);
        isIn[s[i] - 'a'] = true;
        f[s[i] - 'a'] -= 1;
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(begin(ans), end(ans));
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << smallestSubsequence(s) << endl;
    return 0;
}
// Code By - Jae Aeich