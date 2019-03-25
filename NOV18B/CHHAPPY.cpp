#include<iostream>
#include<map>
#include<vector>
#include<iterator>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		map <int, vector<int> > a;
		map <int, bool >a1;
		for(int i = 0; i < n; i++){
			int x;cin>>x;
			a[x].push_back(i + 1);
			a1[x] = 1;
		}
		// for(map<int, vector<int> >::iterator i = a.begin(); i != a.end(); i++){
		// 	cout<<i->first<<" : ";
		// 	for(int j = 0; j < i->second.size(); j++){
		// 		cout<<i->second[j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		int f = 0;
		for(map<int, vector<int> >::iterator i = a.begin(); i != a.end(); i++){
			if(i->second.size() > 1){
				int count = 0;
				for(int j = 0; j < i->second.size(); j++){
					if(a1[i->second[j]]) count++;
					if(count > 1) {
						f = 1;
						break;
					}
				}
				if(f) break;
			}
		}
		// cout<<f<<"\n";
		cout<<(f ? "Truly Happy\n" : "Poor Chef\n");
	}
}
