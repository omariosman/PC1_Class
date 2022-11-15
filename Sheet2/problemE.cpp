/*
  Sheet 2
  Problem: E - Princess Farida
  Link: https://vjudge.net/problem/SPOJ-FARIDA
  Algorithm: DP
  Status: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long dp[(int)1e4+5];
long long W[(int)1e4+5];
ll n, k, d;

long long knapsack(ll i){
    
    if(i >= n){
        return 0;
    }
    
    long long &ret = dp[i];
    if(~ret){
        return ret;
    }
    ret = 0;
    return ret = max(knapsack(i+1) + 0, knapsack(i+2) + W[i]);
    
    
}

int main()
{
    int t;
    cin >> t;
    int ctr=0;
    while(t--){
        ctr++;
        
        memset(dp, -1, sizeof(dp));
        //memset(W, 0, sizeof(W));
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> W[i];
        }
        
        cout << "Case " << ctr << ": " << knapsack(0) << "\n";

        
    }
    
}
