#include<bits/stdc++.h>
using namespace std;

/*
Problem Link : https://leetcode.com/problems/pascals-triangle/
Reference : https://youtu.be/bR7mQgwQ_o8
*/

// Type 1 
// Given i,j find that element of pascal triangle.
//This simple PNC, the answer will be (i-1)C(j-1).

int type1(int n, int r){
    int ans = 1;
    for(int k = 1; k <= r; k++){
        ans *= (n-k+1);
        ans /= k;
    }
    return ans;   
}


int main()
{
    int n;
    cin >> n;
    cout<<type1(5,3); 
    return 0;
}
// Code By - Jae Aeich