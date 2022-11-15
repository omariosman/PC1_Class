/*
  Sheet 2
  Problem: H - Two Buttons
  Link: https://vjudge.net/problem/CodeForces-520B
  Algorithm: BFS
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

int n,m;
queue<int>q;

int vis[20001];

void BFS(){

  vis[n] = 0;
  q.push(n);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    if(u == m){
     cout << vis[u] << "\n";
      return;
    }
    int a = u * 2;
    if(vis[a] == -1){
      q.push(a);
      vis[a] = vis[u] + 1;
    }
    int b = u - 1;
    if(vis[b] == -1){
      q.push(b);
      vis[b] = vis[u] + 1;
    } 
  }
}


int main() {
   cin>>n>>m;
   clr(vis, -1);
    BFS();
    return 0;
}
