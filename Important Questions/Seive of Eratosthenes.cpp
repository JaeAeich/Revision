#include <bits/stdc++.h>
using namespace std;

/* REFERENCES:https://youtu.be/4a_zLjG4kXU
 */

// Seive of Eratosthenes
int siz = 1e7;
vector<int> prime(siz, 1);
vector<int> lp(siz, 0), hp(siz, 0); //--->denoting lowest and highest prime factor of a number.

//#1

void seive()
{
    // since 0 and 1 arent prime, marking them false.
    prime[1] = prime[0] = 0;
    for (int i = 2; i <= siz; i++)
    {
        // If any number is prime, marking all its multiple as not prime.
        if (prime[i])
        {
            for (int j = 2 * i; j <= siz; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

//#2
// For lp and hp
void seive_lphp()
{
    prime[1] = prime[0] = 0;

    for (int i = 2; i <= siz; i++)
    {
        // If any number is prime, then its lowest and highest prime factors will be number itself.
        if (prime[i] == 1)
        {
            hp[i] = lp[i] = i;
            for (int j = 2 * i; j <= siz; j += i)
            {
                prime[j] = 0;
                // Marking all the multiples of this prime numbers as having this number as highest prime factor.
                // Note: This will keep changing, eg in first iteration 6 will have 2 as hp, but after that 3.
                hp[j] = i;
                // Marking i as lp of prime[i], if its already marked with some number then we don't need to change it.
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
}

// Driver code

int main()
{
    seive_lphp();
    for (int i = 0; i < 100; i++)
    {
        cout << i << "-->" << lp[i] << " " << hp[i] << endl;
    }
    return 0;
}
// Code By - Jae Aeich