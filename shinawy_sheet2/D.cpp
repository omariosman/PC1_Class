/*

Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

int val[55]; 
int wei[55];
int max_w, bags;

int memo [1100][210]; 
int wachovia( int max_wei, int idx){
	
	if (idx<0) 
		return 0; 
		
	if (memo[max_wei][idx] !=-1) 
		return memo[max_wei][idx];
	
	int without = wachovia( max_wei, idx-1);
	int with = 0;
	if (max_wei>= wei[idx])	
		with= val[idx] + wachovia( max_wei-wei[idx], idx-1);
	
	return memo[max_wei][idx]= max(with, without); 

	
	
	
	
	
	
}


int main() {
	
	int t; 
	cin>>t;
	
	
	
	while (t--){
		memset(memo, -1, sizeof (memo));
		cin>> max_w>>bags;
		
	for (int i=0; i< bags; i++){
			cin>>wei[i]>>val[i];
		}
	
	printf("Hey stupid robber, you can get %d.\n",wachovia( max_w, bags-1));


		
		
		
	}
	return 0; 
}