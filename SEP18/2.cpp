#include<iostream>
#include<map>
#include <iterator>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		long a[n] = {};
		long e = 0, o = 0;
		map <long , int> dp;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			dp[a[i]] ++;
			if(a[i] % 2 == 0) e ++;
			else o ++;
		}
		long total_pair = e * (e - 1) / 2 + o * (o - 1) / 2;
		long invalid_pair = 0;
		for(map <long, int> :: iterator i = dp.begin(); i != dp.end(); i++){
			// cout<<i->first<<" "<<i->second<<" ";
			// cout<<dp[8];
			if((i->second) > 1) invalid_pair += ((i->second) * ((i->second) - 1)) / 2;
		}
		// cout<<invalid_pair;
		for(int i = 0; i < n; i++){
			if(dp[a[i]] > 0){
				long temp = a[i] ^ 2;
				if(dp[temp] > 0){
					invalid_pair += (dp[temp] * dp[a[i]]);
					dp[temp] = 0;
					dp[a[i]] = 0;
				}
			}
		}
		// cout<<invalid_pair;
		cout<<(total_pair - invalid_pair) <<endl;
	}
}
