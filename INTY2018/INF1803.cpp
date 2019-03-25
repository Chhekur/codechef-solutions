#include<iostream>
using namespace std;

long long ans[100002];

long long mod_pow(long long x, unsigned long long y, long long p){
    long long res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

void solve(){
	ans[0] = 0;
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 0;
	ans[4] = 0;
	for(int i = 5; i < 100001; i += 3){
		ans[i] = (ans[i - 1] % 1000000007 + mod_pow(i,i,1000000007) % 1000000007) % 1000000007;
		ans[i + 1] = ans[i] % 1000000007;
		ans[i + 2] = ans[i] % 1000000007;
		// cout<<ans[i]<<"\n";
	}
}

int main(void){
	solve();
	int q; cin>>q;
	while(q -- ){
		int l, r;cin>>l>>r;
		cout<<(ans[r] - ans[l - 1]) % 1000000007<<"\n";
	}
}
