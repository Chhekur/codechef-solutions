#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(void){
	int n,k;cin>>n>>k;
	int b[n];
	vector<long>a;
	int ans[n + 1] = {};
	for(int i = 0; i < n; i++){
		cin>>b[i];
		// long g;cin>>g;
		a.push_back(b[i]);
	}
	sort(a.begin(), a.end());
	// for(int i = 0; i < a.size(); i++){
	// 	cout<<a[i] <<" ";
	// }
	// cout<<"\n";
	map <int, vector<int> > pairs;
	// int ka[n] = {0};
	while(k --){
		int x,y;cin>>x>>y;
		pairs[x - 1].push_back(y - 1);
		pairs[y - 1].push_back(x - 1);
		// ka[x - 1] = 1;
		// ka[y - 1] = 1;
		// cout<<b[x - 1]<<" "<<"\n";
		// long a1 = lower_bound(a.begin(), a.end(), b[x - 1]) - a.begin();
		// long a2 = lower_bound(a.begin(), a.end(), b[y - 1]) - a.begin();
		// long e1 = a1;
		// if(b[y - 1] < b[x - 1]) e1 --;
		// long e2 = a2;
		// if(b[x - 1] < b[y - 1]) e2 --;
		// // cout<<e1<<" "<<e2<<" ";
		// ans[x - 1] = e1;
		// ans[y - 1] = e2;
		// if(b[x - 1] == a[a1 - 1]){
		// 	a1 --;
		// }
		// if()
		// cout<<a1<<" "<<a2<<"\n";
	}
	// for(int i = 0; i < n; i++){
	// 	cout<<i + 1<<":";
	// 	for(int j = 0; j < pairs[i].size(); j++){
	// 		cout<<pairs[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(int i = 0; i < n; i++){
		long a1 = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
		for(int j = 0; j < pairs[i].size(); j++){
			if(b[pairs[i][j]] < b[i]){
				a1 --;
			}
		}
		cout<<a1 <<" ";
		// if(pairs[i].size() > 0){
		// 	long a1 = lower_bound(a.begin(), a.end(), b[pairs[i]]) - a.begin();
		// }else{
		// 	long p1 = lower_bound(a.begin(), a.end(), b[pairs[i]]) - a.begin();
		// 	cout<<p1<<" ";
		// }
	}
	// for(int i = 0; i < n ; i++){
	// 	// cout<<ans[i]<<" ";
	// 	if(ka[i] == 0){
	// 		long p1 = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
	// 		cout<<p1<<" ";
	// 	}else{
	// 		cout<<ans[i]<<" ";
	// 	}
	// }
}