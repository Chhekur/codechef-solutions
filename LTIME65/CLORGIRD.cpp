#include<iostream>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		char a[n][m];
		int f = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)cin>>a[i][j];
		}
// 		for(int i = 0; i < m; i++){
// 			if(a[1][i] == '#')f = 1;
// 		}

// 		for(int i = 0; i < n; i++){
// 			if(a[i][1] == '#')f = 1;
// 		}

// 		for(int i = 0; i < m; i++){
// 			if(a[n - 2][i] == '#')f = 1;
// 		}

// 		for(int i = 0; i < n; i++){
// 			if(a[i][m - 2] == '#')f = 1;
// 		}
// 		// cout<<f<<" ";
// 		// cout<<f<<" ";
		int dx1[] = {0,1,1}, dy1[] = {-1,0,-1};
		int dx2[] = {0,1,1}, dy2[] = {1,0,1};
		int dx3[] = {0,-1,-1}, dy3[] = {-1,0,-1};
		int dx4[] = {0,-1,-1}, dy4[] = {1,0,1};
		long ans = 0,h = 0;
		for(int i = 0; i < n ; i++){
			for(int j = 0; j < m ; j++){
				if(a[i][j] == '#'){
					h++;
					continue;
				}
				int c = 0;
				for(int k = 0; k < 4; k++){
					int f = 0;
					int dire = 0;
					for(int l = 0; l < 3; l++){
						int x,y;
						if(k == 0)x = i + dx1[l], y = j + dy1[l];
						if(k == 1)x = i + dx2[l], y = j + dy2[l];
						if(k == 2)x = i + dx3[l], y = j + dy3[l];
						if(k == 3)x = i + dx4[l], y = j + dy4[l];
						if(x >= 0 && x < n && y >= 0 && y < m){
							// cout<<x<<" "<<y<<" "<<a[x][y]<<"\n";
							dire ++;
							if(a[x][y] == '#') f = 1;
						}
					}
					if(f == 0 && dire == 3)c++;
					// cout<<"f "<<f<<" "<<i<<" "<<j<<"\n";
				}
				if(c > 0)ans++;
			}
		}
		// cout<<ans<<" "<<h<<"\n";
		if(ans == (n*m - h))cout<<"YES\n";
		else cout<<"NO\n";
	}
}