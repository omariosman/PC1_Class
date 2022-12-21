
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int num_visited=0;
bool vis[10009]={false};

int dfs_dr( int u){
  if(vis[u] == true) return 0;
  vis[u] = true;
  int ret = 1;
  for(int v:graph[u])
    ret += dfs_dr(v);
  return ret;
}


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
	
	
	// cout<< "num_visited: "<<num_visited<< "\t"
	// << "ret: "<< dfs_dr(0);
	// for (int i=0; i<graph.size(); i++){
	// 	for (int j=0; j<graph[i].size(); j++)
	// 		cout<< graph[i][j]<<"\t"; 
	// 	cout<<endl; 
	// }
	
	// for (int i=0; i<vis.size(); i++)
	// 	cout<< vis[i]<<"\t"; 
	 
	// cout<<endl;

	// your code goes here
	return 0;
}