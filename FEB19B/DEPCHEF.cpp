#include<iostream>
using namespace std;

int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n], d[n];
		int ans = -1;
		for(int i = 0; i < n; i++)cin>>a[i];
		for(int i = 0; i < n; i++)cin>>d[i];
		for(int i = 1; i < n - 1; i++){
			if((a[i - 1] + a[i + 1]) < d[i]) ans = max(ans, d[i]);
		}
		if((a[1] + a[n - 1]) < d[0]) ans = max(ans, d[0]);
		if((a[n - 2] + a[0]) < d[n - 1]) ans = max(ans, d[n - 1]);
		cout<<ans<<"\n";
	}
}