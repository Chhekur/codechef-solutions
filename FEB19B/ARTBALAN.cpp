#include<iostream>
#include<algorithm>
// #include<vector>
// #include<utility>
using namespace std;

bool comp(int &a, int &b){
	return a > b;
}

int main(void){
	int t;cin>>t;
	while(t--){
		int f[26] = {};
		string s;cin>>s;
		for(int i = 0; i < s.length(); i++){
			f[s[i] - 'A'] += 1;
		}
		sort(f,f + 26, comp);
		// for(int i = 0; i < 26; i++){
		// 	cout<<char(i + 'a')<<" "<<f[i]<<"\n";
		// }
		int ans = 999999999;
		for(int i = 1; i < 27 && i < s.length() + 1; i++){
			int nop = 0;
			if(s.length() % i == 0){
				int d = s.length() / i;
				for(int j = 0; j < i ; j++){
					if(f[j] >= d){
						nop += d;
					}else{
						nop += f[j];
					}
				}
			}
			int op = s.length() - nop;
			ans = min(ans, op);
		}
		cout<<ans<<"\n";
	}
}