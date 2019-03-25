#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
using namespace std;

double find(long long n, long long k){
	if(k == 0) return 1 / (double)n;
	else if(n == 1) return 1;
	else if(n == 2) return 1 / (double)2;
}

int main(void){
	int t;cin>>t;
	while(t--){
		long long n,k;cin>>n>>k;
		if(n < 3) printf("%.6f\n",find(n,k));
		else{
			if(k > 0 && n % 4 == 2){
				n = ceil(n / 2.0) + 1;
				k --;
			}
			// cout<<n<<" "<<k<<"\n";
			while(k > 0 && n > 1){
				n = ceil(n / 2.0);
				k --;
			}
			if(k == 0) printf("%.6f\n",1.0 / n);
			else if(n == 1) printf("%.6f\n", 1.0);
		}
	}
}
