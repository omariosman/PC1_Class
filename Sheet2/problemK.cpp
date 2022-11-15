/*
  Sheet 2
  Problem: K - Bytelandian gold coins
  Link: https://vjudge.net/problem/SPOJ-COINS
  Algorithm: DP
  Verdict: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<int, ll>mp;
ll solve(ll n){
    if (n <= 0){
        return 0;
    }
    if(mp.count(n)){
        return mp[n];
    }
    return mp[n] = max(n, solve(n/2) + solve(n/3) + solve(n/4));
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
   while(cin >> n){
       cout << solve(n) << "\n";
   }
}
