#include <bits/stdc++.h>
using namespace std;

/* REFERENCES:-https://youtu.be/K8mJ27S72v0
               https://youtu.be/GApcdkIe9WM
               https://cp-algorithms.com/algebra/phi-function.html
*/

int m = 1e9 + 7;

// Case 1
// This is when the a,b are ranging to 1e9;
int binpow_case1(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        // If exponent is odd, multiply result with number.
        if (b & 1)
        {
            res = (res * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}

// Case 2
// When a is a very large number.
int binpow_case2(int a, int b)
{
    // Then simply modulate is before hand to make the number smaller

    a %= m;
    int res = 1;
    while (b > 0)
    {
        // If exponent is odd, multiply result with number.
        if (b & 1)
        {
            res = (res * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}

// Case 3
// When value of m is bigger.
int binpow_case3(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        // If exponent is odd, multiply result with number.
        if (b & 1)
        {
            res = (res * a) % m;
        }
        // a = (a * a) % m; -->This will give overflow,since a and b are of range 1e9 and m is big so its not lowering them.
        // In such cases we will perform binary multiplication
        b >>= 1;
    }
    return res;
}

int binmult(long long int a, long long int b)
{
    // Note : Code is exactly same as binpow.
    int res = 0;
    while (b > 0)
    {
        // If exponent is odd, multiply result with number.
        if (b & 1)
        {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

// Case 4
// When value of b is greater than 1e9
/* Note: This is considered a different case because we can't store a very bog value of b, ie let
say we have to calculate a^(b^c) in such case we always won't be able to store b^c without overflow. */

int calcexp(int b, int c)
{
    int n = m - 1;
    int res = 1;
    while (c)
    {
        if (c & 1)
        {
            res = (res * b) % n;
        }
        b = (b * b) % n;
        c >>= 1;
    }
    return res;
}

int binpow_case4(int a, int b, int c)
{
    // Using ETF and Euler's theorem
    // ETF or Eulers totient fuction (phi(n)) denotes no. of coprime number wrt n from 1 to n.
    // phi(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)..... where p1,p2,p3...are prime factors of n.
    // This theorem states that a^(b^c) %m = (a^((b^c))%phi(m))%m
    // Note: ususally m is prime, and totient of a prime (p) is always p-1.
    int res = 1;
    // Calculating exponent modulo m-1,cosidering m is prime.
    int e = calcexp(b, c);
    while (e)
    {
        // If exponent is odd, multiply result with number.
        if (e & 1)
        {
            res = (res * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        e >>= 1;
    }
    return res;
}

// Driver code
int main()
{
    int a, b;

    cin >> a >> b;
    // cout << binpow(a, b, m);
    return 0;
}
// Code By - Jae Aeich