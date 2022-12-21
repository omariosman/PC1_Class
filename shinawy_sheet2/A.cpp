/*

Status: Accepted

*/

#include <bits/stdc++.h>
using namespace std;

int max_foodie (vector<int> all_r, int max_f, int last_idx){
	
	if (last_idx< 0 or max_f == 0)
		return 0; 
	

	if (all_r[last_idx] > max_f)
		return max_foodie(all_r, max_f, last_idx-1); 
	
	else{
		int with_n= all_r[last_idx] + max_foodie(all_r, max_f-all_r[last_idx], last_idx-1); 
		int without_n= max_foodie(all_r, max_f, last_idx-1);
		return max(with_n, without_n);
		
	}
	
	
	
}


int main() {
	
	int t, r, max_f;
	cin>> t; 
	
	int n_dish; 
	
	int sum=0; 
	int dish_athand; 
	while (t--){
		vector <int> all_rack_weight;
		cin>> r>> max_f; 
		while (r--){
			cin>> n_dish; 
			sum=0; 
			while (n_dish--){
				cin>> dish_athand; 
				sum+= dish_athand; 
			}
			all_rack_weight.push_back(sum);
		}
		
		
	cout<< max_foodie(all_rack_weight, max_f, all_rack_weight.size()-1)<<endl; 

		

		
	}
	
	
	
	// your code goes here
	return 0;
}

