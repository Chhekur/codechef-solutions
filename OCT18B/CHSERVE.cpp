#include<iostream>
using namespace std;
int main(void){
	int t;cin>>t;
	while(t--){
		long a,b,c;cin>>a>>b>>c;
		long e = (a + b) / c;
		if(e % 2 == 0)cout<<"CHEF\n";
		else cout<<"COOK\n";
	}
}