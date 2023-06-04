#include<bits/stdc++.h>
using namespace std;

/*
Note the lexicografically smallest perm of [1,2,3] is 123 and largest is 321,
clearly smallest has values arranged in increasing order from right to left and 
vice versa.

To summarize, the steps for finding the next lexicographically greater permutation are:

- Find the pivot position, 
  i.e., the rightmost pair of adjacent digits where the left digit is smaller than the right digit.

- Find the smallest digit larger than the pivot but still greater than all the digits to the right 
  of the pivot.

- Swap the pivot with the smallest digit found in the previous step.

- Reverse the digits to the right of the pivot position.
*/

vector<int> nextPermutation(vector<int> &v, int n)
{
    int piv = -1;
    // 132 -> next -> 213
    // Find the piv, the index before which the perm is inc sorted
    for(int i=n-2;i>=0;i--){
        if(v[i]<v[i+1]){
            piv = i;
            break;
        }
    }

    // If there is no such idx, that means it is the lex largest perm
    if(piv==-1) {
        //return rev to make it smallest
        reverse(begin(v),end(v));
        return v;
    }

    // Find the the element right of piv which is greater than piv
    for(int i = n-1; i>piv;i--){
      if (v[i] > v[piv]) {
        swap(v[i], v[piv]);
        break;
      }
    }

    reverse(begin(v)+piv+1,end(v));

    return v;
}

// Code By - Jae Aeich