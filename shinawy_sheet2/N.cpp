/*

Status: wrong answer

*/
#include <iostream>
using namespace std;


int match(string a, string b){
	
	int i=0;
	int steps=0;
	while (i<a.length() && i< b.length()){
		
		if (a[i] != b[i]) steps+=1;
		i++;
	}
	
	int diff= a.length() - b.length();
	steps+=  diff<0 ? -1 * diff : diff; 
	return steps; 
	
}




int main() {
	
	int t; 
	cin>> t;
	string A, B; 
	while (t--){
		cin>> A>> B;
		cout<< match(A, B)<<endl;
	
		
	}
	
	
	
	
	
	return 0;
}