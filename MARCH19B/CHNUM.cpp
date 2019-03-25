#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
	int t;cin>>t;
	while(t--){
		int n, ng = 0,pg = 0;cin>>n;
		for(int i = 0; i < n; i++){
			long x;cin>>x;
			if(x >= 0) pg += 1;
			else ng += 1;
		}
		if(ng == 0 || pg == 0){
			cout<<max(ng,pg)<<" "<<max(ng,pg)<<"\n";
		}else{
			cout<<max(ng,pg)<<" "<<min(ng,pg)<<"\n";
		}
	}
}