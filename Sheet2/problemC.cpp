
 /*
  Sheet 2
  Problem: C - Wachovia Bank
  Link: https://vjudge.net/problem/SPOJ-WACHOVIA
  Algorithm: DP
  Verdict: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for(int i=0;i<sz(v);++i)
#define lp(i, n)  for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n) for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n) for(int i=(j);i>=(int)(n);--i)
typedef long long ll;
 
const int OO = 1e6;

int t, n, k, m;
vector<int> W(52);
vector<int> V(52);

int dp[52][1002];

int knapsack(int i, int rem){
    if(i >= m || rem == 0){
        return 0;
    }
    
    int &ret = dp[i][rem];
    if(~ret){
        return ret;
    }
    
    //leave it
    int op1 = knapsack(i+1, rem) + 0;
    
    //take it 
    int op2 = 0;
    if(W[i] <= rem){
        op2 = knapsack(i+1, rem - W[i]) + V[i];
    }
    
    return ret = max(op1, op2);
    
    
}    
    
int main()
{
    fast;
    cin >> t;
    while(t--){
        cin >> k >> m;
        
        lp(i, m){
            cin >> W[i] >> V[i];
        }
        clr(dp, -1);
        int ans = knapsack(0, k);
        cout << "Hey stupid robber, you can get " << ans << ".\n";
    }
    
 
}
