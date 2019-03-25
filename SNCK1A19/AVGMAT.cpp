#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		vector <pair<int,int> > a;
		map <int, int> dp;
		int n,m;cin>>n>>m;
		for(int i = 0; i < n; i++){
			string s;cin>>s;
			// cout<<s;
			for(int j = 0; j < m; j++){
				if(s[j] == '1'){
					// cout<<'Hello';
					a.push_back(make_pair(i,j));
				}
			}
		}
		for(int i = 0; i < a.size(); i++){
			// cout<<a[i].first<<" "<<a[i].second<<"\n";
			for(int j = i + 1; j < a.size(); j++){
				int d = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
				dp[d] ++;
			}
		}
		for(int i = 1; i < n + m - 1; i++){
			cout<<dp[i]<<" ";
		}
		cout<<"\n";
	}
}
