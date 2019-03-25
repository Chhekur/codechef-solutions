#include<iostream>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n][n] = {};
		int x = 1;
		for(int j = 0; j < n; j++){
			int y = j;
			for(int k = 0; k <= j; k++){
				a[k][y--] = x;
				x++;
			}
		}
		x = n * n;
		for(int j = n - 1; j >= 0; j--){
			int y = j;
			for(int k = n - 1; k >= j ; k--){
				a[k][y++] = x;
				x--;
			}
		}
// 		for(int i = 0; i < n; i++){
			
// 		}
		// for(int i = 1; i < n; i++){
		// 	for(int j = 0; j <= i; j++){
		// 		a[i - 1][j] = x;
		// 		// cout<<x<<" ";
		// 		x++;
		// 	}
		// }
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}