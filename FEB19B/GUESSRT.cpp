#include<iostream>
#define M 1000000007
using namespace std;

long long gcd(long long a,long long b){
	if(a == 0) return b;
	return gcd(b % a, a);
}

long long lcm(long long a,long long b){
	return ((a * b) / gcd(a,b));
}

long long mod_power(long long x,long long y){
	if(y == 0) return 1;
	else if(y == 1) return x % M;
	long long temp = mod_power(x, y / 2) % M;
	if(y & 1) return ( ((temp % M) * (temp % M)) % M * (x % M) ) % M;
	else return ((temp % M) * (temp % M)) % M;
}

long long mod_inv(long long x){
	return mod_power(x, M - 2);
}

void prob(long long &x,long long &y,long long &x1,long long &y1,long long &n,long long &m,long long &k){
	long long temp;
	if(n % k == 0) temp = (n / k) - 1;
	else temp = n / k;
	n -= (temp * k);
	x1 = n - 1;
	y1 = n;
	long long x2 = mod_power(x1, m / 2);
	long long y2 = mod_power(y1, m / 2);
	x = ((y2 % M) - (x2 % M) + M ) % M;
	y = y2;
}

int main(void){
	int t;cin>>t;
	while(t--){
		long long n,k,m;cin>>n>>k>>m;
		long long x = 0,y = 0,x1 = 1,y1 = 1;
		if(m == 1){
			x = 1;y = n;
		}else{
			if(n > k){
				m -= 1;
				prob(x,y,x1,y1,n,m,k);
			}else{
				n += k;
				prob(x,y,x1,y1,n,m,k);
			}
			if(m % 2 == 0) n += k;
			long long x2 = mod_power(x1, (m / 2));
			long long y2 = mod_power(y1, (m / 2));
			y2 = (y2 * n) % M;
			long long l = lcm(y, y2);
			x = ((x *(l / y)) % M + (x2 * (l / y2)) % M) % M;
			y = l % M;
		}
		long long temp = gcd(x,y);
		x /= temp;
		y /= temp;
		cout<< ((x % M) * mod_inv(y)) % M <<"\n";
	}
}