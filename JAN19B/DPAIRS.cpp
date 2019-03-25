#include<iostream>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	// long a[n],b[m];
	map<long, bool> na, nb,pa,pb;
	vector<pair<long, int> > a, b;
	for(int i = 0; i < n; i++){
		long t;cin>>t;
		if(t < 0){
			if(na[t*-1] == 0){
				na[t*-1] = 1;
				a.push_back(make_pair(t, i));
			}
		}else{
			if(pa[t] == 0){
				pa[t] = 1;
				a.push_back(make_pair(t, i));
			}
		}
	}
	for(int i = 0; i < m; i++){
		long t;cin>>t;
		if(t < 0){
			if(nb[t*-1] == 0){
				nb[t*-1] = 1;
				b.push_back(make_pair(t, i));
			}
		}else{
			if(pb[t] == 0){
				pb[t] = 1;
				b.push_back(make_pair(t, i));
			}
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(), b.end());
// 	for(int i = 0; i < a.size(); i++){
// 		cout<<a[i].first<<" "<<a[i].second<<" | ";

// 	}
// 	cout<<"\n";
// 	for(int i = 0; i < b.size(); i++){
// 		cout<<b[i].first<<" "<<b[i].second<<" | ";
// 	}
// 	cout<<"\n";
	// map <long, bool> sump, sumn;
	vector <pair <int , int> > ans;
	int x = 0;
	for(int i = 0; i < b.size(); i++){
		long s = a[0].first + b[i].first;
		// if(s < 0){
		// 	sumn[s*-1] = 1;
		// 	x ++;
		// 	ans.push_back(make_pair(a[0].second, b[i].second));
		// }else{
		// 	sump[s] = 1;
		// 	x ++;
		// 	ans.push_back(make_pair(a[0].second, b[i].second));
		// }
		x ++;
		ans.push_back(make_pair(a[0].second, b[i].second));
		if(x >= n + m - 1) break;
	}
	for(int i = 1; i < a.size(); i++){
			long temp = a[i - 1].first + b[b.size() - 1].first;
			temp = temp - a[i].first;
		for(int j = b.size() - 1; j > -1; j--){
			if(b[j].first <= temp) break;
			ans.push_back(make_pair(a[i].second, b[j].second));
			x ++;
			if(x >= n + m - 1) break;
		}
		// for(int j = 0; j < b.size(); j++){
		// 	if(b[j].first <= temp){
		// 		long s = a[i].first + b[j].first;
		// 		if(s < 0){
		// 			if(sumn[s*-1] == 0){
		// 				sumn[s*-1] = 1;
		// 				x ++;
		// 				ans.push_back(make_pair(a[i].second, b[j].second));
		// 			}
		// 			if(x >= n + m - 1) break;
		// 		}else{
		// 			if(sump[s] == 0){
		// 				// cout<<s<<"\n";
		// 				sump[s] = 1;
		// 				x ++;
		// 				ans.push_back(make_pair(a[i].second, b[j].second));
		// 			}
		// 			if(x >= n + m - 1) break;
		// 		}
		// 	}else{
		// 		for(int k = j; k < b.size(); k++){
		// 			ans.push_back(make_pair(a[i].second, b[k].second));
		// 			x ++;
		// 			if(x >= n + m - 1) break;
		// 		}
		// 		break;
		// 	}
		// }
	}
	for(int i = 0; i < ans.size() && i < n + m - 1; i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	// for(int i = 0; i < a.size(); i++){
	// 	for(int j = 0; j < b.size(); j++){
	// 		long s = a[i].first + b[j].first;
	// 		// cout<<s<<"\n";
	// 		if(s < 0){
	// 			if(sumn[s*-1] == 0){
	// 				sumn[s*-1] = 1;
	// 				x ++;
	// 				ans.push_back(make_pair(a[i].second, b[j].second));
	// 			}
	// 			if(x >= n + m - 1) break;
	// 		}else{
	// 			if(sump[s] == 0){
	// 				// cout<<s<<"\n";
	// 				sump[s] = 1;
	// 				x ++;
	// 				ans.push_back(make_pair(a[i].second, b[j].second));
	// 			}
	// 			if(x >= n + m - 1) break;
	// 		}
	// 	}
	// }
	// for(int i = 0; i < ans.size() && i < n + m - 1; i++){
	// 	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	// }
}
