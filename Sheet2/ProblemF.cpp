#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree; 

int longest=-1;
int leaf;
int path=0; 
int longest_path(vector<int>& vis, int idx){
	
	if (vis[idx]) return 0;
	else{
	
		vis[idx] = true;
		for (int i=0; i< tree[idx].size(); i++){
			path++; 
			longest_path(vis, tree[idx][i]);
			path--; 
		}
		if (path> longest){
			longest= path; 
			leaf= idx; 
		}
		return longest= max(longest, path); 
	}

	
}


int main() {

	int n;
	int f,t; 
	cin>>n; 
	tree.resize(n);
	vector<int> vis(n,false);
	
	for (int i=0; i< n-1; i++){
		
		cin>>f>>t;
		f--;t--;
		tree[f].push_back(t); 
		tree[t].push_back(f); 
		
	}


	longest_path(vis, 0);
	path=0; 
	longest=-1;
	fill(vis.begin(), vis.end(), 0); 
	longest_path(vis, leaf);
	cout<<longest<<endl;
	

	return 0;
}
