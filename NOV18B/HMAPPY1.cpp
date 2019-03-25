#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compa(vector<vector<int> > &a, vector<vector<int> > &b){
	return a[0] > b[0];
}


int main(void){
	int n,q,k;cin>>n>>q>>k;
	int a[n];
	int ans[n];
	vector<vector <int > > pq;
	for(int i = 0; i < n; i++)cin>>a[i];
	int pre = a[0], count = 0, l,r;
	if(pre == 1){
		count = 1;
		l = 0;
		r = 0;
	}
	for(int i = 1; i < n; i++){
		if(a[i] == pre && a[i] == 1) {
			count ++;
			r++;
		}
		else{
			// cout<<"hello";
			if(count > 0){
				vector <int> v;
				v.push_back(count);
				v.push_back(l);
				v.push_back(r);
				pq.push_back(v);
			}
			if(a[i] == 1){
				count = 1;
				l = r = i;
				// cout<<count<<" "<<l<<" "<<r<<"\n";
			}
			else {
				count = 0;
				// l = r = 
			}
			pre = a[i];
		}
	}
	// cout<<count<<"\n";
	if(count > 0){
		vector <int> v;
		v.push_back(count);
		v.push_back(l);
		v.push_back(r);
		pq.push_back(v);
	}
	// for(int i = 0; i < pq.size(); i++){
	// 	cout<<pq[i][0]<<" "<<pq[i][1]<<" "<<pq[i][2]<<"\n" ;
	// }
	if(a[0] == 1 && a[n - 1] == 1 && pq.size() > 1){
		pq[0][0] += pq[pq.size() - 1][0];
		pq[0][1] = pq[pq.size() - 1][1];
		pq[0][2] = pq[0][2];
		// vector <int> v;
		// v.push_back(v[0][0] + v[v.size() - 1][0]);
		// v.push_back( v[v.size() - 1][1]);v.push_back(v[0][2]);
		pq.pop_back();
		// pq.pop_front();
		// pq.push_back(v);
	}
	sort(pq.begin(), pq.end());
	// for(int i = 0; i < pq.size(); i++){
	// 	cout<<pq[i][0]<<" "<<pq[i][1]<<" "<<pq[i][2]<<"\n" ;
	// }
	// cout<<pq.size();
	string s;cin>>s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '?'){
			if(pq.size() == 0)cout<<0<<"\n";
			else if(pq[pq.size() - 1][1] <= pq[pq.size() - 1][2]){
				cout<<min(pq[pq.size() - 1][0], k)<<"\n";
			}
			else{
				if(pq.size() > 1){
					cout<<min(k, max(pq[pq.size() - 2][0],max(n - pq[pq.size() - 1][1], pq[pq.size() - 1][2] + 1)))<<"\n";
				}else{
				cout<<min(k,max(n - pq[pq.size() - 1][1], pq[pq.size() - 1][2] + 1))<<"\n";
				}
			}
		}else{
			if(pq.size() > 0){
				pq[pq.size() - 1][1] = (pq[pq.size() - 1][1] + 1 ) % n;
				pq[pq.size() - 1][2] = (pq[pq.size() - 1][2] + 1 ) % n;
				// cout<<pq[pq.size() - 1][1] <<" "<<pq[pq.size() - 1][2]<<"\n";
			}
		}
	}
}
