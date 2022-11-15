/*
  Sheet 2
  Problem: J - King's Path 
  Link: https://codeforces.com/contest/242/problem/C
  Algorithm: BFS
  Verdict: Accepted
*/

#include <bits/stdc++.h>
using namespace std;
int xo, yo, xf, yf, n;
 
set<pair<int, int>> pts;
 
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
 
int bfs(int xo, int yo) {
    map<pair<int,int>, int> len;
    queue<pair<int, int>> q;
    
    pair<int, int> s = {xo, yo};
    pair<int, int> cur;
    
    q.push(s);
    len[s] = 0;
    
    int dep = 0, sz = 1;
    for(; !q.empty(); dep = dep + 1, sz = q.size()) {
        while(sz--){
            cur = q.front(), q.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            for(int i = 0 ; i < 8; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                pair<int, int> newp = { nx, ny };
                
                if  (pts.count(newp) == 0 || len.count(newp)!=0) {
                    continue;
                }
                
                q.push(newp);
                len[newp] = dep + 1;
                if (newp.first == xf && newp.second == yf){
                    return dep + 1;
                }
                
            }
        }
    }
    return -1;
}
 
int main() {
    
    cin >> xo >> yo >> xf >> yf;
    cin >> n;
    int r, a, b;
    while(n--){
        cin >> r >> a >> b;
        for(int i = a; i <= b; i++){
            pts.insert(make_pair(r, i));
        }
        
 
 
    }
    int res = bfs(xo, yo);
    cout << res;
    return 0;
}
