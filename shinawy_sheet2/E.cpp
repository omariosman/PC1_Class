/*

Status: Accepted
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mon[10005];
ll memo [10005]; 
ll t,c; 

ll max_coin(ll idx){
	
	if (idx>=c) return 0; 
	if (memo[idx]!=-1)
		return memo[idx]; 
	
	ll with= mon[idx] + max_coin(idx+2); 
	ll without = max_coin(idx+1); 
	
	return memo[idx]=max(with, without);
	

}


int main() {

	cin>>t; 
	
	for (ll i=0; i<t; i++){
		
		cin>>c;
		for (ll i=0; i<c; i++ )
			cin>>mon[i]; 
			
		memset(memo, -1, sizeof (memo)); 
		printf("Case %lld: %lld\n", i+1, max_coin(0)); 
		// cout << "Case " << i+1 << ": " << max_coin(0) << "\n";
	}


	return 0;
}