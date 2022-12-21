/*

Status: Accepted

*/

#include <iostream>
using namespace std;

int T[1001];
int n, w;

int tot=0;

int memo [1000][3][31];
int apple(int idx, int tree, int rem){
	
	
	if (idx==n) return 0;
	if (memo[idx][tree][rem]!=-1) 
		return memo[idx][tree][rem];
	
	if (T[idx] == tree) 
		return memo[idx][tree][rem]= 1+ apple(idx+1, tree, rem);
	
	else {
		
		int no_move= apple(idx+1, tree, rem);
		int move=0; 
		if (rem !=0)
			move = 1+apple(idx+1, !tree, rem-1 ); 
				
		return memo[idx][tree][rem]=max(no_move, move);
		
	}


		
}
		
	


int main() {
	
	memset(memo, -1, sizeof(memo));
	cin>>n>>w;
	
	int temp;
	for (int i=0; i<n; i++){
		cin>>temp; T[i]= temp-1; 
		
	}
	
	cout<< apple(0,0, w )<<endl;
	
	
	return 0;
}