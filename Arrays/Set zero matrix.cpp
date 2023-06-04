#include<bits/stdc++.h>
using namespace std;

/*
The basic idea of set zero matrix if to store the (i,j) pair where the ele is zero, then make that entire column and row zero, but instead of 
using O(n) space this can be O(1), since we are either way gonna make the entire row and col zero, why not store the which row we will 
make zero in the first ele of that col and row itself. 
*/

void setZeros(vector<vector<int>> &v)
{
	bool r= false;
	int n=v.size(),m=v[0].size();
	
	// check if the first row has a zero and store it in a flag 
	for(int j=0;j<m;j++){
		if(v[0][j]==0) r=true;
	}

	// For every zero in the matrix make the first ele of the row and col zero
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]==0){
				v[0][j]=0;
				v[i][0]=0;
			}
		}
	}

	// If the first col has a zero make that entire row zero
	for(int i=1;i<n;i++){
		if(v[i][0]==0){
			v[i]=vector<int> (m,0);
		}
	}

	// If the first row has a zero make that entire col zero
	for(int j=1;j<v[0].size();j++){
		if(v[0][j]==0){
			for(int i=0;i<n;i++){
				v[i][j]=0;
			}
		}
	}

	// If the first ele of the matrix is zero make the first col zero
	if(v[0][0]==0){
		for(int i=0;i<v.size();i++){
			v[i][0]=0;
		}
	}

	// If the row contained zero make that entire row zero 
	if(r){
		v[0]=vector<int> (v[0].size(),0);
	}
}

// Code By - Jae Aeich
