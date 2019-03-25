#include<iostream>
#include<cmath>
#include<map>
using namespace std;
// map <long long, int> perfect_square;
// void preprocess(){
// 	for(int i = 0; i < 100000; i++){
// 		perfect_square[i * i] = 1;
// 		if(i * i > 100000)break;
// 	}
// }

bool perfect_square(long long x){
	long double a = sqrt(x);
	// cout<<"x "<<x<<" a "<<a<<endl;
	return ((a - floor(a)) == 0);
}

int main(void){
	// preprocess();
	int t;cin>>t;
	while(t--){
		long n,q;cin>>n>>q;
		long long numbers[n],dp[n+1] = {};
		for(int i = 0; i < n; i++){
			cin>>numbers[i];
		}
		// for(int i = 0; i < n; i++){
		// 	int count = 0;
		// 	for(int j = 0; j < i + 1; j++){
		// 		long long temp = numbers[0];
		// 		for(int k = i; k < j + 1; k++){
		// 			// cout<<"range "<<k;
		// 			temp &= numbers[k];
		// 		}
		// 		if(perfect_square[temp] == 1){
		// 			// cout<<"temp "<<temp;
		// 			count ++;
		// 			// cout<<j<<" count "<<count<<" ";
		// 		}
		// 	}
		// 	cout<<i<<" count "<<count<<" ";
		// 	dp[i + 1] = dp[i] + count;
		// }
		while(q--){
			int l,r;cin>>l>>r;
			long long count = 0;
			for(int i = l - 1; i < r; i++){
				for(int j = i; j < r; j++){
					long long temp = numbers[i];
					// cout<<"temp "<<temp<<" "<<endl;
					for(int k = i; k < j + 1; k++){
						// cout<<numbers[k]<<" ";
						temp &= numbers[k];
					}
					// cout<<endl;
					// cout<<i<<" "<<j<<endl;
					// cout<<"temp "<<temp<<" "<<endl;
					if(perfect_square(temp)){
						// cout<<i<<" "<<temp<<" ";
						count++;
					}
				}
			}
			cout<<count<<endl;
			// cout<<dp[r] - dp[l - 1]<<endl;
			// for(int i = 0; i < n+1; i++)cout<<dp[i];
		}
	}
}
