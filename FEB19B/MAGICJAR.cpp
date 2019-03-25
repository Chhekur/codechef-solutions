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
		int n;cin>>n;
		long long ans = 0;
		for(int i = 0; i < n; i++){
			long x;cin>>x;
			ans += (x - 1);
		}
		cout<<ans + 1 <<"\n";
	}
}