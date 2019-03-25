#include<iostream>
#include<string>
#include<map>
using namespace std;

int a[1001][1001];

long cal_row(int i, int j, int k, int l){
	map<string, int> dp;
	for(int row = i; row < j + 1; row++){
		string s = "";
		for(int col = k; col < l + 1; col++){
			s += to_string(a[row][col]);
			// cout<<a[row][col]<<" ";
		}
		dp[s] ++;
// 		cout<<s;
// 		cout<<"\n";
	}
	cout<<dp.size()<<"\n";
	return 0;
}

int main(void){
	int n,m;cin>>n>>m;
	// int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>a[i][j];
		}
	}
	long count = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			for(int k = 0; k < m; k++){
				for(int l = k; l < m; l++){
					count += cal_row(i,j,k,l);
				}
			}
		}
	}
}