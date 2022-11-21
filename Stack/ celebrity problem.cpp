#include <bits/stdc++.h>
using namespace std;

/*
REFERENCE LINK:
                https://youtu.be/9u2BJfmWNEg

Problem :       https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
                https://leetcode.com/problems/find-the-town-judge/


problem statement:

In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        stack<int> s;
        // pushing everyone onto the the stack.
        for (int i = 1; i <= n; i++)
        {
            s.push(i);
        }
        // creating an adgecency matrix for trust among people.
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        for (int i = 0; i < trust.size(); i++)
        {
            v[trust[i][0]][trust[i][1]] = 1;
        }
        // popping two people at once till the stack size becomes one.
        while (s.size() != 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            // comparing both people's relations, if the a trusts b then a isn't the judge.
            if (v[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        // person who is left is a potential judge given he doesn't trust anyone and evryone trusts him.
        int judge = s.top();
        // bool flag=true;
        for (int i = 0; i < n + 1; i++)
        {
            if (v[judge][i] == 1)
            {
                return -1;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (i != judge && v[i][judge] == 0)
                return -1;
        }
        return judge;
    }
};
// Code By - Jae Aeich