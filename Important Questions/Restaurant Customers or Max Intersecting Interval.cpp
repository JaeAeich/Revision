#include <bits/stdc++.h>
using namespace std;
/* REFERENCE LINK :-     https://youtu.be/c_EGGhJBPPc         */

// // Solution 1
// // TLE solution , using alot of auxilary space = max(entering time), time complexity=O(n^2).

// vector<int> v;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> enter, leave;
//     int maxleave = -1;
//     int loop = n;
//     while (loop--)
//     {
//         int e, l;
//         cin >> e >> l;
//         enter.push_back(e);
//         leave.push_back(l);
//         maxleave = max(maxleave, l);
//     }
//     v.resize(maxleave + 1);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = enter[i]; j <= leave[i]; j++)
//         {
//             v[j] += 1;
//         }
//     }
//     int ans = 0;
//     for (int val : v)
//         ans = max(ans, val);
//     cout << ans;
//     return 0;
// }

// // Solution 2
// // store arrival and departure in one vector of pair with arrival denoted by 1 and departure by -1.
// int main()
// {
//     int n;
//     cin >> n;
//     vector<pair<int, int>> v;
//     for (int i = 0; i < n; i++)
//     {
//         int a, d;
//         cin >> a >> d;
//         v.push_back({a, 1});
//         v.push_back({d, -1});
//     }
//     // sorting so the we can check who came first and left first.
//     sort(begin(v), end(v));
//     // for (pair<int, int> p : v)
//     //     cout << p.second << endl;
//     int ans = INT_MIN, c = 0;
//     for (pair<int, int> p : v)
//     {
//         // If a person comes we increase the count of # of person at that time in restraunt.
//         if (p.second == 1)
//         {
//             c++;
//         }
//         // else we decrement.
//         else
//             c--;
//         // keeping the max of # of person in restraunt in the same time.
//         ans = max(ans, c);
//     }
//     cout << ans;
//     return 0;
// }

// Solution 3
int main()
{
    int n;
    cin >> n;
    vector<int> entr, ext;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        entr.push_back(a);
        ext.push_back(b);
    }
    sort(entr.begin(), entr.end());
    sort(ext.begin(), ext.end());
    // atleast one person has to be there so mxPrsn is one and person at the moment(Atm) is also 1.
    int mxPrsn = 1, i = 1, j = 0, prsnAtm = 1;
    while (i < n && j < n)
    {
        // if next person has entered but next hasnt left then we will increase count and check for next entered person.
        if (entr[i] <= ext[j])
        {
            prsnAtm++;
            mxPrsn = max(mxPrsn, prsnAtm);
            i++;
        }
        else
        {
            prsnAtm--;
            j++;
        }
    }
    cout << mxPrsn << endl;
    return 0;
}