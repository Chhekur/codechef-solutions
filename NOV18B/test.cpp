#include<iostream>
#include<vector>
#define M 1000000007

using namespace std;

long long fact[1005];

void cal_fact(){
	fact[0] = 1;
	for(int i = 1; i < 1003; i++){
		fact[i] = (fact[i - 1] * i) % M;
	}
}

long long fast_pow(long long x, long long y, long long p) {
    long long res = 1;
    while(y > 0) {
        if( y % 2 != 0) {
            res = (res * x) % p;
        }
        x = (x * x) % p;
        y /= 2;
    }
    return res;
}



long long qwerty1(long long x, long long p) {
    return fast_pow(x, p-2, p);
}

int qwerty2(int n, int k, int p) {
   if (k == 0)
      return 1;

    return (fact[n]* qwerty1(fact[k], p) % p *
            qwerty1(fact[n - k], p) % p) % p;
}

// long long qwerty2(long long n, long long k, long long p) {

//     long long no = 1;
//     for (int i = 0; i < k; i ++) {
//         no = (no  * (n-i)) % p;
// //        cout<<no<<"\n";
//     }
// //    cout<<"\n";

//     long long don = 1;
//     for (int i=1; i <= k; i++) {
//         don = (don  * i ) % p;
//     }
// //	cout<<no<<"\n";
//     return ( no * qwerty1(don,p)) % p;
// }



int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cal_fact();
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int a[n];
		int fre[2*n + 1] = {0};
		for(int i = 0; i < n; i++){
			cin>>a[i];
			fre[a[i]]++;
		}
		// for(int i = 0; i < n*2 + 1; i++){
		// 	cout<<fre[i]<<" ";
		// }
		// cout<<"\n";
		vector<int> numbers;
		for(int i = 1; i < n*2 + 1; i++){
			fre[i] += fre[i - 1];
			if(fre[i] - fre[i - 1] > 1) numbers.push_back(i);
		}
		// for(int i = 0; i < n*2 + 1; i++){
		// 	cout<<fre[i]<<" ";
		// }
		// cout<<"\n";
		long long ans = 0;
		for(int i = 1; i < n + 1; i += 2){
			ans = (ans + qwerty2(n,i,M)) % M;
		}
		// cout<<ans<<"\n";
		for(int i = 0; i < numbers.size(); i++){
			if(fre[numbers[i]] - fre[numbers[i] - 1] < 2) continue;
			for(int x = 0; x <= (fre[numbers[i]] - fre[numbers[i] - 1]) - 2; x++){
				for(int y = 0; y <= (fre[numbers[i]] - fre[numbers[i] - 1]) - 2 - x; y++){
					ans = (ans + qwerty2((n - fre[numbers[i]]) + x + fre[numbers[i] - 1] + y, (n - fre[numbers[i]]) + x, M)) % M;
				}
			}
		}
		cout<<ans % M<<"\n";
// 		if(k > n)cout<<0<<"\n";
// 		else {
// 			long long final_ans = 0;
// 			for(int i = 0; i < k; i++){
// //				cout<<qwerty2(k - 1, i, 1000000007)<<"\n";
// //				cout<<qwerty2(k + 1 + i - k, k, 1000000007)<<"\n";
// 				final_ans = (final_ans + (2 * qwerty2(k - 1, i,1000000007) * qwerty2(n + 1 + i - k, k, 1000000007))) % 1000000007;
// 				// cout<<final_ans<<"\n";
// 			}
// 			cout<<final_ans <<"\n";
// 		}
	}
}