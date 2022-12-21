/*

Status: Accepted

*/

#include <bits/stdc++.h>
using namespace std;

int steps=0;
int n;
void two_buttons( int m){
	
	if (n<0) return ;
	if (n == m) return ;
	
	steps++;
	if (n>m || (n<m && m%2 !=0))
		two_buttons(m+1); 
	else 
		two_buttons (m/2); 

}




int main() {
	int m; 
	cin>>n>>m; 
	
	
	two_buttons(m); 
	cout<< steps<<endl;
	
	
	
	
	return 0;
}

