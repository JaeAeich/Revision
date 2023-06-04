#include<bits/stdc++.h>
using namespace std;

/*
This is a one pass algorithm to sort array containing only 3 distinct ele, the idea is to use three pointers.
The Dutch National Flag algorithm is used to sort an array of 0s, 1s, and 2s in linear time. It maintains three-pointers, 
lo, mid, and hi, which represent the boundaries of three sub-arrays: the left sub-array contains all 0s, the middle sub-array 
contains all 1s, and the right sub-array contains all 2s. As it iterates through the array, it swaps elements into their respective
 sub-arrays until the entire array is sorted.
*/

void sortColors(vector<int>& v) {
        int lo=0,mid=0,hi=v.size()-1;
        while(mid<=hi){
						//if the mid is 0 that means it need to go to right, ie to lo.
            if(v[mid]==0){
                swap(v[mid],v[lo]);
                lo++;
                mid++;
						}
						//if its 2 it need to go to left most part.
            else if(v[mid]==2){
                swap(v[mid],v[hi]);
                hi--;
            }
            else if(v[mid]==1) mid++;
        }
}

// Code By - Jae Aeich