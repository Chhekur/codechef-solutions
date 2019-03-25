#include<iostream>
using namespace std;

long long gcd(long long a,long long b){
	if(a == 0) return b;
	return gcd(b % a, a);
}


int main(void){
	int t;cin>>t;
	while(t--){
		long long n,k;cin>>n;
		long long A,B;cin>>A>>B>>k;
		long long a,b,r;
		a = n / A;
		b = n / B;
		r = n / ((A * B) / gcd( A , B));
		// cout<<gcd(4,2);
		// cout<<gcd(3,7);
		// cout<<((A * B) / gcd( A , B))<<"\n";
		// cout<<a<<" "<<b<<" "<<r<<"\n";
		// cout<<a + b - 2 * r<<"\n";
		// cout<<k<<"\n";
		if(a + b - (2 * r) >= k) cout<<"Win\n";
		else cout<<"Lose\n";
	}
}