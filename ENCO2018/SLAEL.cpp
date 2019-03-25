#include<iostream>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		long k;cin>>k;
		long a[n];
		map<long, long >dp;
		for(int i = 0; i < n; i++)cin>>a[i];
		for(int i = 0; i < n; i++){
			long first = 0, second = 0;
			for(int j = i; j < n; j++){
				if (a[j] > first){
					second = first;
					first = a[j];
				}
				else if (a[j] > second && a[j] != first)second = a[j];
				if((j - i) + 1 > dp[second])
				dp[second] = j - i + 1;
			}
		}
		long ans = 0;
		for(map<long,long>::iterator it=dp.begin(); it!=dp.end(); ++it){
			if(k >= it->first) ans = max(ans, it->second);
		}
		cout<<ans<<"\n";
	}
}