#include<bits/stdc++.h>
using namespace std;

// // using sum of natural and square of natural numbers
// pair<int,int> missingAndRepeating(vector<int> &a, int n)
// {
// 	long long int exp = (n*(n+1))/2;
// 	long long int expSq = ((n)*(n+1)*(2*n+1))/6;

// 	long long int calc = accumulate(begin(v),end(v),0);
// 	// long long int calcSq = accumulate(begin(v),end(v),0,[](long long int acc ,long long int val){return acc*1ll + val*val*1ll;});
// 	long long int calcSq = 0;
// 	for(auto val : v){
// 		calcSq += (long long)val*(long long)val*1ll;
// 	}
// 	long long int x = exp - calc;
// 	long long int y = expSq - calcSq;

// 	long long int  miss = (x+y/x)/2;
// 	long long int rep = (y/x - x)/2;

//         return {int(miss), int(rep)};
//         long long n = a.size(); // size of the array

//         Find Sn and S2n:
// }

// using xor
pair<int, int> missingAndRepeating(vector<int> &v, int n)
{
    int xorAll = 0;
    for (auto val : v)
        xorAll ^= val;
    for (int i = 1; i <= n; i++)
        xorAll ^= i;

    int piv = 0;
    while (xorAll)
    {
        if (xorAll & 1)
        {
            break;
        }
        piv++;
    }
    // piv--;
    int ans1 = 0, ans2 = 0;
    for (auto val : v)
    {
        if ((val)&1 << piv)
            ans1 ^= val;
        else
            ans2 ^= val;
    }
    for (int i = 1; i <= n; i++)
    {
        if ((i)&1 << piv)
            ans1 ^= i;
        else
            ans2 ^= i;
    }

    int c = 0;
    for (auto val : v)
    {
        if (val == ans1)
            c++;
    }
    if (c == 2)
        return {ans2, ans1};
    return {ans1, ans2};
}

// Code By - Jae Aeich