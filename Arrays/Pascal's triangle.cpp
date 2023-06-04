#include<bits/stdc++.h>
using namespace std;

/*
TC: O(n^3)

The trick is to know that the ith row of the pascals triangle is just a series of nCr.
*/


// aCb = (a!)/((a-b)!*(b!)) = ((a)*(a-1)*...*(a-b+1))/((b)*(b-1)*(b-2)*...*(1));
long ncr(long a, long b){
  // nCr = nC(n-r)
  if(b>a-b) b=a-b;
  long res = 1;

  for(int i=0;i<b;i++){
    res*=a-i;
    //  Note: devide the res with i+1 not a-i
    res/=i+1;
  }
  return res;
}



vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans = {};

  // we know that ith row of pascal triangle will be series of iCr, 0<=r<=i;
  for(int i=0;i<n;i++){
    vector<long long int> temp={};
    for(int j=0;j<=i;j++){
      long val = ncr(i,j);
      temp.push_back(val);
    }
    ans.push_back(temp);
  }

  return ans;

}
// Code By - Jae Aeich
