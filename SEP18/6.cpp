#include<iostream>
using namespace std;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;cin>>t;
	bool game[1002][1002];
	while(t--){
		string s1,s2; cin>>s1>>s2;
		int n = s2.length();
		int m = s1.length();
		for(int i = 1; i < s1.length() + 1; i++){
			if(s1[i - 1] == '1') game[0][i] = 1;
			else game[0][i] = 0;
		}
		for(int i = 1; i < s2.length() + 1; i++) {
			if(s2[i - 1] == '1') game[i][0] = 1;
			else game[i][0] = 0;
		}
		for(int i = 1; i < 4; i++){
			for(int j = 1; j < m + 1; j++){
				// game[i][j] = ! (game[i - 1][j] & game[i][j - 1];
				if(game[i - 1][j] == 1 && game[i][j - 1] == 1){
					// cout<<i<<" "<<j<<endl;
					game[i][j] = 0;
				}else{
					// cout<<i<<" "<<j<<endl;
					game[i][j] = 1;
				}
			}
		}
		for(int i = 1; i < n + 1; i++){
			for(int j = 1; j < 4; j++){
				// game[i][j] = ! (game[i - 1][j] & game[i][j - 1];
				if(game[i - 1][j] == 1 && game[i][j - 1] == 1){
					// cout<<i<<" "<<j<<endl;
					game[i][j] = 0;
				}else{
					// cout<<i<<" "<<j<<endl;
					game[i][j] = 1;
				}
			}
		}
		for(int i = 0; i < n + 1; i++){
			for(int j = 0; j < m + 1; j++){
				cout<<game[i][j]<<" ";
			}
			cout<<endl;
		}
		int q;cin>>q;
		while(q--){
			int a,b;cin>>a>>b;
			if(a > 2 && b > 2){
				int temp = min(a,b) - 2;
				cout<<game[a - temp][b - temp];
			}else{
				cout<<game[a][b];
			}
		}
		cout<<endl;
	}
}


