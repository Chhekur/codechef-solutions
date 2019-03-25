#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int maxOf(vector<int > v){
	int m = 0;
	for(int i = 0; i < v.size(); i++){
		m = max(v[i],m);
	}
	return m;
}


int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		long k;cin>>k;
		int a[n];
		long count = 0;
		for(int i = 0; i < n; i++)cin>>a[i];
		for(int i = 0; i < n; i++){
			// map<int, int > dp;
			int dp[2001] = {};
			vector <int > nu;
			// for(int j = i; j < n; j++){
			// 	dp[a[j]] += 1;
			// 	nu.push_back(a[j]);
			// }
			// sort(nu.begin(), nu.end());
			// for(int j = 0; j < nu.size(); j++){
			// 	cout<<nu[j]<<" ";
			// }
			// cout<<"\n";
				// int x = 0;
			for(int j = i; j < n; j++){
				dp[a[j]] += 1;
				if(nu.size() > 0){
					if(nu[nu.size() - 1] > a[j]){
						// nu.push_back(a[j]);
					vector<int >::iterator lower;
						int flag = 0;
					lower = lower_bound(nu.begin(), nu.end(), a[j]);
					// lower = lower - nu.begin();
					int low = lower - nu.begin();
					nu.insert(nu.begin() + low, a[j]);
					// x = max(x, a[j]);
					// cout<<(lower - nu.begin())<<"\n";
						// for(int l = nu.size() - 1; l >= 0; l--){
						// 	if(nu[l] <= a[j]){
						// 		flag = 1;
						// 		nu.insert(nu.begin() + l + 1, a[j]);
						// 		break;
						// 	}
						// }
						// if(flag == 0){
						// 	// cout<<a[j]<<"\n";
						// 	nu.insert(nu.end(), a[j]);
						// }
						// sort(nu.begin(), nu.end());
					}else{
						nu.push_back(a[j]);
						// x = max(x, a[j]);
					}
				}else{
					nu.push_back(a[j]);
					// x = max(x, a[j]);
				}
				// cout<<nu.size()<<"\n";
				// for(int l = 0; l < nu.size(); l++){
				// 	cout<<nu[l]<<" ";
				// }
				// cout<<"\n";
				// vector <int > nu;
				// for(int k = j; k >= i; k--){
				// 	nu.push_back(a[k]);
				// }
				// sort(nu.begin(), nu.end());
				// if(j + 1 < n){
				// 	dp[a[j + 1]] -= 1;
				// 	nu.pop_back();
				// 	sort(nu.begin(), nu.end());
				// }
				int x;
				// auto x;
				if(nu.size() >= k){
					x = nu[k - 1];
					// x = maxOf(nu);
				}else{
					int m = ceil(k / double(nu.size()));
					int new_k = ceil(k / double(m)) - 1;
					// cout<<new_k<<"\n";
					x = nu[new_k];
					// x = maxOf(nu);
				}
				int f = dp[x];
				if(dp[f] != 0) count += 1;
				// cout<<i<<" "<<j<<" "<<x<<" "<<f<<"\n";
			}
		}
		cout<<count <<"\n";
	}
}