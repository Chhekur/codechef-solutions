#include<iostream>
#include<cmath>
using namespace std;

long ans[1000001];


long long fact(long n, long mod) {
	long long sum = 0;
    while (n % 2 == 0){
        printf("%d ", 2);
		sum = (sum + 2) % mod;
		while (n % 2 == 0){
			n = n / 2;
		}
        // n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n % i == 0) {
			sum = (sum + i) % mod;
            printf("%d ", i);
            // n = n/i;
			while (n % i == 0){
				n = n / i;
			}
        }
    }

    if (n > 2) {
		sum = (sum + n) % mod;
		printf ("%d ", n);
	}
	return sum % mod;
        // printf ("%d ", n);
}


int main(void){
	int t;cin>>t;
	while(t --){
		int l,r;cin>>l>>r;
		long long ans = 0;
		// cout<<r<<"\n";
		for(l; l < r + 1; l++){
			ans = (ans + fact(l,1000000007)) % 1000000007;
		}
		cout<<ans<<"\n";
	}
}