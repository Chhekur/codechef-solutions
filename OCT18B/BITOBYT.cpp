#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		long n;cin>>n;
		long a = (n - 1) / 26;
		long b = n % 26;
		long long temp = pow(2,a);
		if(n == 0)cout<<"1 0 0\n";
		else if(b > 0 and b < 3)cout<<temp<<" 0 0\n";
		else if(b > 2 and b < 11)cout<<"0 "<<temp<<" 0\n";
		else cout<<"0 0 "<<temp<<"\n";
	}
}