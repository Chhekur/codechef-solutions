#include<bits/stdc++.h>
using namespace std;
struct day{
	long long c;
	long a;
	long b;
};

bool comp(const day& x, const day& y){
	return x.c > y.c;
}

// class comparator{
// 	public:
// 		bool operator()(const day& x, const day& y){
// 			return x.c < y.c;
// 		}
// };

long long * check(day t[], int n, long long mid){
	// for(int i = 0; i < n; i++){
	// 	cout<<t[i].c<<" "<<t[i].a<<" "<<t[i].b<<"\n";
	// }
	// cout<<mid<<" ";
	long long count = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++){
		if(t[i].c < mid) break;
		long long te = ceil(abs(t[i].c - mid) /(double) t[i].b);
		// cout<<te<<" ";
		count += te;
		ans = max(ans, t[i].c - (te*t[i].b));
	}
	// cout<<count<<"\n";
	long long *r = new long long[2];
	r[0] = count;
	r[1] = ans;
	return r;
}

int main(void){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;long long m,s = 0;cin>>n>>m;
	long a[n];
	day t[n];
	// priority_queue <day, vector<day>, comparator> qu;
	for (int i = 0; i < n; i++){
		cin>>a[i];
		// t[i].a = a[i];
		s += a[i];
	}
	for (int i = 0; i < n; i++){
		// day t;
		cin>>t[i].b;
		t[i].a = a[i];
		t[i].c = t[i].a * t[i].b;
		// qu.push(t);
	}
	sort(t,t+n, comp);
	// for(int i = 0; i < n; i++){
	// 	cout<<t[i].c<<" "<<t[i].a<<" "<<t[i].b<<"\n";
	// }
	// while(!qu.empty()){
	// 	cout<<qu.top().c<<" "<<qu.top().a<<" "<<qu.top().b<<"\n";
	// 	qu.pop();
	// }
	// if(m >= s)cout<<0<<"\n";
	// else{
		long long l = 0, r = t[0].c;
		// cout<<r<<" ";
		long long ans = 1000000000000000000;
		// cout<<ans;
		while(l <= r){
			long long mid = long (l + r)/2;
			// cout<<mid<<" ";
			long long *temp = check(t,n,mid);
			if(temp[0] > m){
				l = mid + 1;
			}else{
				r = mid - 1;
			}
			if(temp[0] <= m)
				ans = min(ans,temp[1]);
			// cout<<temp[0]<<" "<<temp[1]<<"\n";
			// break;
		}
		cout<<ans<<"\n";
		// while(m > 0){
		// 	day d1,d2;
		// 	d1 = qu.top();
		// 	qu.pop();
		// 	d2 = qu.top();
		// 	qu.pop();
		// 	if(d1.a <= 0) break;
		// 	long long temp = d1.a - long (d2.c / d1.b);
		// 	// if(abs(m - temp) >= 2 && ) temp ++;
		// 	if(temp == 0)temp = 1;
		// 	// cout<<temp<<"\n";
		// 	if (temp <= m){
		// 		d1.a -= temp;
		// 		d1.c -= temp * d1.b;
		// 		m -= temp;
		// 	}else{
		// 		d1.a -= m;
		// 		d1.c -= m * d1.b;
		// 		m -= m;
		// 	}
		// 	qu.push(d2);
		// 	qu.push(d1);
		// 	// cout<<m<<"\n";
		// }
		// while(!qu.empty()){
		// 	cout<<qu.top().c<<" "<<qu.top().a<<" "<<qu.top().b<<"\n";
		// 	qu.pop();
		// }
		// cout<<qu.top().c<<"\n";
	// }
}

