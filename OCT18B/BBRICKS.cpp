#include<iostream>
using namespace std;

long long fast_pow(long long x, long long y, long long p) {
    long long res = 1;
    while(y > 0) {
        if( y % 2 != 0) {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        y /= 2;
    }
    return res;
}



long long qwerty1(long long x, long long p) {
    return fast_pow(x, p-2, p);
}

long long qwerty2(long long n, long long k, long long p) {

    long long no = 1;
    for (int i = 0; i < k; i ++) {
        no = (no  * (n-i)) % p;
//        cout<<no<<"\n";
    }
//    cout<<"\n";

    long long don = 1;
    for (int i=1; i <= k; i++) {
        don = (don  * i ) % p;
    }
//	cout<<no<<"\n";
    return ( no * qwerty1(don,p)) % p;
}



int main(void){
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		if(k > n)cout<<0<<"\n";
		else {
			long long final_ans = 0;
			for(int i = 0; i < k; i++){
//				cout<<qwerty2(k - 1, i, 1000000007)<<"\n";
//				cout<<qwerty2(k + 1 + i - k, k, 1000000007)<<"\n";
				final_ans = (final_ans + (2 * qwerty2(k - 1, i,1000000007) * qwerty2(n + 1 + i - k, k, 1000000007))) % 1000000007;
				// cout<<final_ans<<"\n";
			}
			cout<<final_ans <<"\n";
		}
	}
}
