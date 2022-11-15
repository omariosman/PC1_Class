/*
  Sheet 2
  Problem: I - Apple Catching
  Link: https://vjudge.net/problem/POJ-2385
  Algorithm: DP
  Verdict: Accepted
*/

#include <iostream>
#include <string.h>
using namespace std;
int t;
int arr[1001];
int memo[1001][3][31];
int solve(int state,int tree,int move){
  if(state == t) return 0;
if(memo[state][tree][move] != -1) return (memo[state][tree][move]); 
if(arr[state] == tree) 
    return 1 + solve(state + 1,tree,move);
    
else{
  int op1 = solve(state + 1,tree,move);
  int op2 = 0;
  if(move)
    op2 = 1 + solve(state + 1,3 - tree,move-1);
  return memo[state][tree][move] = max(op1,op2);
}

}

int main() {
  int m;
  memset(memo,-1,sizeof(memo));
  cin>>t>>m;
  for(int i=0;i<t;i++)
    cin>>arr[i];

  cout << solve(0,1,m) << endl;
}
