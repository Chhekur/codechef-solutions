#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin >> n;
 
	int h = n/2;

 
	for(int i=2; i<=h; i++){
		cout << i << " ";
	}
	cout << 1 << " ";
 
	for(int i=h+2; i<=n; i++){
		cout << i << " ";
	}
	cout << h+1 << endl;
 
	cout << n << " ";
	for(int i=1; i<n; i++){
		cout << i << " ";
	}
 
 
	return 0;
}




