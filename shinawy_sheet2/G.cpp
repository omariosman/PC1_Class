/*

Status: Accepted

*/
#include <bits/stdc++.h>
using namespace std;
#define ROW_NUM 8



vector<int> knight_x={1,1,-1,-1,2,2,-2,-2}; 
vector<int> knight_y={2,-2,2,-2,1,-1,1,-1};

int map_idx(string s){
	int col= s[0] - 'a';
	int row= s[1]-'0'-1; 
	return  row * ROW_NUM + col;  
}


int BFS (int src, int dest){
	if (src==dest) 
		return 0; 
		
		
	vector<int> p_nodes;
	p_nodes.push_back(src); 
	vector<int> c_nodes;
	
	bool found =false; 
	int v; 
	int level=0; 
	while (true){
		level++; 
		
		
		
	
		
		for (int i=0; i<p_nodes.size(); i++){
			v= p_nodes[i]; 
			
			int row= v/8; int col= v%8;
			for (int j=0; j< knight_x.size(); j++){
				int m_row= row+ knight_y[j]; 
				int m_col= col+ knight_x[j];
				if (m_row>=0 && m_row<=7 && m_col>=0 && m_col<=7)
					c_nodes.push_back(m_row * ROW_NUM + m_col); 
			}
		
		}
	
	
		if (find(c_nodes.begin(), c_nodes.end(), dest)!= c_nodes.end())
			break; 
		else{
			p_nodes=c_nodes; 
			c_nodes.clear();
		}
		
		
		
	}
	
	return level; 

	
}











int main() {
	string src, dest; 
	int s,d; 
	while (cin>>src>>dest){
		

		s= map_idx(src); 
		d= map_idx(dest); 
		
		
		int min_steps=  BFS(s,d); 
		
		
		cout<<"To get from "<<src<< " to "<<dest<<" takes "<<min_steps<< " knight moves.\n"; 
		
		
		
		
	}
	
	
	// your code goes here
	return 0;
}