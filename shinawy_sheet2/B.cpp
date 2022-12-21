/*

Status: Accepted

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int num_visited=0;
bool vis[10009]={false};


void dfs( int node){
	if (vis[node]) return;
	vis[node]= true;
	num_visited+=1;

	for (int i=0; i<graph[node].size(); i++){
		 dfs(graph[node][i]); 
	}

	
	
	
}


int main() {
	 
	int n, m;
	cin>>n>>m; 
	
	if (m+1 !=n) {
		
		cout<<"NO"<<endl;
		return 0; 
		
	} 
	
	
	graph.resize(n);
	int f,t; 
	for (int i=0; i<m; i++){
		cin>>f>>t; 
		graph[f-1].push_back(t-1); 
		graph[t-1].push_back(f-1); 
	}
	
	dfs(0);
	
	if (num_visited == n)
		cout<<"YES"<<endl;
		
	else 
		cout<<"NO"<<endl; 
	
	// your code goes here
	return 0;
}