#include <bits/stdc++.h>
using namespace std;

/* Its like whenever greater ele in stack comes it starts eating the smaller element till it can't.
Cosidering only larger ele can eat smaller ele.
*/

vector<int> NextGreatestElement(vector<int> &v)
{
    vector<int> nge(v.size());
    stack<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        // If stack is not empty, then it is filled with non decreasing sequence.
        // If these ele are smaller than v[i], we will start popping indexes from stack.
        // This will be done till we either exaust the stack ot reach an index whose value is greater than v[i].
        while (!s.empty() && v[i] > v[s.top()])
        {
            nge[s.top()] = i;
            s.pop();
        }
        // v[i] will never have "next" greatest ele index in stack as these indexes are from back of i.
        // Hence no matter what we will push it into the stack.
        s.push(i);
    }

    // Element left in the stack have no next greatest ele, i.e stack has indexes of increasing ele.
    // We will assign them to -1.
    while (!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }

    return nge;
}

// Driver code

int main()
{
    int n;
    cin >> n;
    vector<int> v = {};
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> nge = NextGreatestElement(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "nge of " << v[i] << " is " << v[nge[i]] << endl;
    }
    return 0;
}