#include <bits/stdc++.h>
using namespace std;

// Next smallest element NSE

/*exactly like nge just a lil modificationt to comparitive condition in the stack loop*/

vector<int> nsetr(vector<int> v)
{ //-->nsetr = next smaller element to right.
    int n = v.size();
    stack<int> s;
    vector<int> nsetr(n, -1); //--> making a vector of size v and initialising all its ele to -1.
    for (int i = 0; i < n; i++)
    {
        // while ith ele is smaller than present ele in stack assigning them nse value as i.
        while (!s.empty() && v[s.top()] > v[i])
        {
            nsetr[i] = s.top();
            s.pop();
        }
        // psuhing i to the stack.
        s.push(i);
    }
    return nsetr;
}

vector<int> nsetr(vector<int> v)
{ //-->nsetr = next smaller element to left.
    int n = v.size();
    stack<int> s;
    vector<int> nsetl(n, -1); //--> making a vector of size v and initialising all its ele to -1.
    for (int i = n - 1; i >= 0; i--)
    {
        // while ith ele is smaller than present ele in stack assigning them nse value as i.
        while (!s.empty() && v[s.top()] > v[i])
        {
            nsetl[i] = s.top();
            s.pop();
        }
        // psuhing i to the stack.
        s.push(i);
    }
    return nsetl;
}

// Code By - Jae Aeich