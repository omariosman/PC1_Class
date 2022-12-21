/*

Status: Accepted

*/
#include <bits/stdc++.h>
using namespace std;

map <int, long long> memo;
long long byte_land(int n){
	if (n==0) return 0; 
	if (memo[n] !=0) return memo[n];
	
	long long scatter= byte_land(n/2)+byte_land(n/3)+byte_land(n/4); 
	return  memo[n]= scatter>n ? scatter: n;
	
	
	
}

int main() {
	
	int coin; 
	while (cin>>coin){
		
		cout<< byte_land(coin)<<endl;
		
		
	} 
	
	return 0;
}