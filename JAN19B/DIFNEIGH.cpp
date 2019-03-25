#include<iostream>
#include<algorithm>
using namespace std;
int a[50][50] = {};
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int dx1[] = {0, 0, 2, -2, -1, 1, -1, 1}, dy1[] = {-2, 2, 0, 0, -1, 1, 1, -1};

void gen(int a[50][50], int n, int m){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 1; k < 10000; k++){
				a[i][j] = k;
				int c = 0;
				for(int l = 0; l < 4; l++){
					int x,y;
					x = i + dx[l];
					y = j + dy[l];
					if(x >= 0 && y >= 0 && x < n && y < m){
						if(a[i][j] == a[x][y]) c ++;
					}
				}
				if(c < 2){
					int d = 0;
					for(int l = 0; l < 8; l++){
						int x,y;
						x = i + dx1[l];
						y = j + dy1[l];
						if(x >= 0 && y >= 0 && x < n && y < m){
							if(a[i][j] == a[x][y]){
								d ++;
								break;
							}
						}
					}
					if(d == 0){
						break;
					}
				}
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	gen(a, 50, 50);
	while(t--){
		int n,m;cin>>n>>m;
		int ma = 0,ma1 = 0;
		int a1[50][50] = {};
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ma = max(ma, a[i][j]);
			}
			// cout<<"\n";
		}
		if(n == 2){
			gen(a1,m,n);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					ma1 = max(ma1, a1[j][i]);
				}
				// cout<<"\n";
			}
		}else{
			gen(a1, n,m);
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					ma1 = max(ma1, a1[i][j]);
				}
				// cout<<"\n";
			}
		}
		
		if(ma < ma1){
			cout<<ma<<"\n";
			if(n == 2){
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++){
						cout<<a[j][i]<<" ";
					}
					cout<<"\n";
				}
			}else{
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++){
						cout<<a[i][j]<<" ";
					}
					cout<<"\n";
				}
			}
		}else{
			cout<<ma1<<"\n";
			if(n == 2){
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++){
						cout<<a1[j][i]<<" ";
					}
					cout<<"\n";
				}
			}else{
				for(int i = 0; i < n; i++){
					for(int j = 0; j < m; j++){
						cout<<a1[i][j]<<" ";
					}
					cout<<"\n";
				}
			}
		}
	}
}
