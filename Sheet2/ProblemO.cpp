#include <bits/stdc++.h>

using namespace std;
#define N 2500


int main() {
	
	vector<int> a,b,c,d;
	vector<int> a_b_sums;
	vector<int> c_d_sums;

	int t;
	int val;
	cin>>t;
	
	for (int i=0; i<t; i++){
		cin>>val; a.push_back(val);
		cin>>val; b.push_back(val);
		cin>>val; c.push_back(val);
		cin>>val; d.push_back(val);
	}
	
	
	for (int i=0; i<t; i++){
		for (int j=0; j<t; j++){
			a_b_sums.push_back(a[i]+b[j]);
			c_d_sums.push_back(-(c[i]+d[j])); // to prepare for equal range 
		}
	}
	
	int quad=0;
	sort (a_b_sums.begin(),a_b_sums.end()); 
	pair<vector<int>::iterator, vector<int>::iterator> bounds;
	for (int i=0; i< t*t; i++){
		
		bounds= equal_range(a_b_sums.begin(), a_b_sums.end(), c_d_sums[i]); 
		quad+= bounds.second - bounds.first; 

	}

	cout<<quad<<endl;
	
	
	
	
	return 0;
}
