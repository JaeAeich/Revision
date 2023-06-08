#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/powx-n/

Remember fastPow/binaryPow method to calculate pow(a,b) in log(b) time and take care of the edge case specially abs(INT_MIN) can be contained in 
int due to overflow so better to operate using long long int.

TC : O(logn)
SC : O(1)

*/

// Assume only accepts pos n and x
double fastPow(double x, long long int n)
{
    double res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= x;
        }
        x *= x;
        n >>= 1;
    }
    return res;
}

double myPow(double x, long long int n)
{
    // Obvious case
    if (x == 1 or n == 0)
        return 1;

    if (n < 0)
        x = 1 / x;
    n = abs(n);

    if (x < 0)
    {
        x = abs(x);
        if (n % 2)
            return -fastPow(x, n);
        return fastPow(x, n);
    }

    return fastPow(x, n);
}

// Code By - Jae Aeich