#include<iostream>
#include<vector>
using namespace std;

int main(void){
	int n,m;cin>>n>>m;
	int a[n][n] = {};
	for(int i = 0; i < 2 * m; i++){
		int x,y;cin>>x>>y;
		a[x - 1][y - 1] = -1;
	}
	int c = 1, f = 0;
	vector<int> ans;
	int i = 0;
	int j = n - 1;
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < n; j++){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	while(i < n){
		// cout<<i<<"\n";
		if(i % 2 == 0) c = -1;
		else c = 1;
		if(j == n){
			j = n - 1;
			c = -1;
			i++;
		}else if(j == -1){
			j = 0;
			c = 1;
			i++;
		}
		while(j < n && j > -1 && i < n){
			// cout<<i<<" "<<j<<"\n";
			if(a[i][j] == -1){
					// cout<<i<<" "<<j<<"\n";
				if(f == 0){
					ans.clear();
					f = 1;
					ans.push_back(i);
					ans.push_back(j);
				}else{
					ans.push_back(i);
					ans.push_back(j);
					cout<<ans.size() / 2<<" ";
					for(int k = 0; k < ans.size(); k++){
						cout<<ans[k] + 1<<" ";
					}
					cout<<"\n";
					f = 0;
				}
			}else{
				ans.push_back(i);
				ans.push_back(j);
			}
			j += c;
		}
	}
}