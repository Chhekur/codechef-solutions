#include<iostream>
#include<vector>
#define M 1000000000
using namespace std;

int main(void){
	int t;cin>>t;
	while(t--){
		// int c = 0;
		long long md1, md2,md3,md4,md5;
		cout<<"Q 0 0\n";
		cin>>md1;
		// cout<<md1<<"\n";
		if(md1 < 0)exit(1);
		cout<<"Q 1000000000 0\n";
		cin>>md2;
		// cout<<md2<<"\n";
		if(md2 < 0)exit(1);
		cout<<"Q 1000000000 1000000000\n";
		cin>>md3;
		// cout<<md3<<"\n";
		if(md3 < 0)exit(1);
		long long x = ( md1 - md2 + M ) / 2;
		long long y = ( md1 + md2 - M ) / 2;
		cout<<"Q "<<x<<" "<<0<<"\n";
		cin>>md4;
		// cout<<md4<<"\n";
		if(md4 < 0) exit(1);
		long long x_ = x;
		long long y_ = md4;
		long long x1 = md1 - y_;
		long long y1 = y_;
		long long x2 = - md2 + M + y_;
		long long y2 = y_;
		long long x3 = x2;
		long long y3 = - md3 + (2 * M) - x2;
		cout<<"A "<<x1<<" "<<y1<<" "<<x3<<" "<<y3<<"\n";
		int a;
		cin>>a;
		if(a != 1)exit(1);
	}
}