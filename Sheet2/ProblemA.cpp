/*
  Sheet 2
  Problem: A - FOODIE
  Link: https://vjudge.net/problem/SPOJ-FOODIE
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
vi w(1001);
int t, n, k;

ll dp[101][1001];
ll maxUnits(int i, int rem){
    if(i == n) return 0;
    
    ll &ret = dp[i][rem];
    if(~ret){
        return ret;
    }
    
    ll op1 = 0;
    if(rem >= w[i])
        op1 = maxUnits(i+1, rem - w[i]) + w[i];
    ll op2 = maxUnits(i+1, rem) + 0;
    return ret = max(op1, op2);
}


int main()
{
    fast;
    
    cin >> t;
    lp(i, t){
        
        cin >> n >> k;
        ll sum, units;
        ll dishes;
        lp(j, n){
            cin >> dishes;
            sum = 0;
            lp(k, dishes){
                cin >> units;
                sum += units;
            }
            w[j] = sum;
        }
        clr(dp, -1);
        cout << maxUnits(0, k) << " ";
        
    }
    return 0;
}
