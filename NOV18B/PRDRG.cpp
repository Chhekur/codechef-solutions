#include<iostream>
#include<cmath>
using namespace std;
int main(void){
	int t;cin>>t;
	int a[26]; a[1] = 1;
	for(int i = 2; i < 26; i++){
		if(i % 2 == 0) a[i] = a[i - 1] * 2 - 1;
		else a[i] = a[i - 1] * 2 + 1;
	}
	// for(int i = 1; i < 26; i++)cout<<a[i]<<" ";
	while(t --){
		int n;cin>>n;
		long long x = pow(2,n);
		cout<<a[n]<<" "<<x<<" ";
		// if(n % 2 == 0) cout<<1<<" "<<x<<" ";
		// else cout<<x - 1 <<" "<<x<<" ";
		// if(n == 1)cout<<1<<" "<<2<<" ";
		// else if(n == 2)cout<<1<<" "<<4<<" ";
		// else if(n == 3)cout<<3<<" "<<8<<" ";
		// else if(n == 4)cout<<5<<" "<<16<<" ";
		// else if(n == 5)cout<<11<<" "<<32<<" ";
		// else if(n == 6)cout<<21<<" "<<64<<" ";
		// else if(n == 7)cout<<
		// else cout<<"0 0 ";
	}
}