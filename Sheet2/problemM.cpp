
/*
  Sheet 2
  Problem:  M - Easy Longest Common Subsequence
  Link: https://vjudge.net/problem/SPOJ-EELCS
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
     
    string str1, str2;
    int LCS(int i , int j){
        if(i == sz(str1) || j == sz(str2)){
            return 0;
        }
     
        //if match
        if(str1[i] == str2[j]){
            return LCS(i+1, j+1) + 1;
        }
     
        int op1 = LCS(i+1, j);
        int op2 = LCS(i, j+1);

        return max(op1, op2);
     
    }
     
    int main()
    {
        fast;
        
        cin >> str1 >> str2;
        cout << LCS(0, 0);
     
        return 0;
    }
