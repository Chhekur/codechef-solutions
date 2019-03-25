#include<iostream>
using namespace std;

int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int f[n][26] = {};
		for(int i = 0; i < n; i++){
			string s;cin>>s;
			for(int j = 0; j < s.length(); j++){
				f[i][s[j] - 'a'] += 1;
			}
		}
		int ans = 0;
		for(int i = 0; i < 26; i++){
			bool special = true;
			for(int j = 0; j < n; j++){
				if(f[j][i] == 0) special = false;
			}
			if(special){
				ans += 1;
			}
		}
		cout<<ans <<"\n";
	}
}