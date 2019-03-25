#include<iostream>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;

bitset<300000> check_primes;
vector<long> primes;

// taken from competitive coding 3 book

void sieve(){
	check_primes.set();
	check_primes[0] = 0;
	check_primes[1] = 0;
	for(int i = 2; i < 300000; i++){
		if(check_primes[i] == 1){
			for(long j = i; j < 300000; j += i){
				check_primes[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	// for(int i = 0; i < 500000; i++){
	// 	check_primes[i] = 1;
	// }
	sieve();
	// cout<<primes.size()<<"\n";
	// cout<<primes[664578]<<"\n";
	// int x = 35000*35000;
	// cout<<x<<"\n";
	// cout<<primes[3403]<<"\n";
	// for(int i = 1; i < primes.size(); i++){
	// 	long x = primes[i] * primes[i - 1];
	// 	if(x > 1e9){
	// 		cout<<i + 1;
	// 		break;
	// 	}
	// }
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n == 3){
			cout<<"6 15 10\n";
		}else if(n == 4){
			cout<<"6 15 35 14\n";
		}else if(n == 5){
			cout<<"6 15 35 77 22\n";
		}else if(n == 6){
			cout<<"6 15 35 77 143 26\n";
		}else if(n == 7){
			cout<<"6 15 10 14 21 33 22\n";
		}else if(n == 8){
			cout<<"6 15 35 14 22 33 39 26\n";
		}else if(n == 9){
			cout<<"6 15 35 77 22 26 39 51 34\n";
		}else if (n == 10){
			cout<<"6 15 35 77 143 26 34 51 57 38\n";
		}else{
			// if(n < 3334){
			// 	// long long a[n];
			// 	for(int i = 1; i < n; i++){
			// 		cout<<primes[i] * primes[i - 1]<<" ";
			// 		// a[i] = primes[i] * primes[i + 1];
			// 	}
			// 	cout<<primes[0] * primes[n - 1]<<"\n";
			// 	// cout<<"\n";
			// }else{
			int y = n - 7;
			int r = y / 4;
			long long a[n];
			// int z = 3;
			int i = 0,p;
			if(y % 4 == 0){
				i = 3;
				a[0] = 6;a[1] = 3;a[2] = 2;
				p = 2;
			}else if(y % 4 == 1){
				i = 4;
				a[0] = 6;a[1] = 15;a[2] = 5;a[3] = 2;
				p = 3;
			}else if(y % 4 == 2){
				i = 5;
				a[0] = 6;a[1] = 15;a[2] = 35;a[3] = 7;a[4] = 2;
				p = 4;
			}else if(y % 4 == 3){
				i = 6;
				a[0] = 6;a[1] = 15;a[2] = 35;a[3] = 77;a[4] = 11;a[5] = 2;
				p = 5;
			}
			for(int k = 0; k < r; k++){
				for(i; i < n; i += 4){
					a[i] = 2;a[i + 1] = 3;
					a[i + 2] = 3; a[i + 3] = 2;
				}
			}
			for(int i = p - 1; i < n; i += 2){
				a[i] *= primes[p];
				a[i + 1] *= primes[p];
				p++;
			}
			for(int i = 0; i < n; i++){
				cout<<a[i]<<" ";
			}
			cout<<"\n";
		}
		// }
	// 	long long a[n], b[n];
	// 	int c = 0;
	// 	for(int i = 0; i < n; i++){
	// 		if(i % 2 == 0){
	// 			a[i] = primes[c];
	// 			c += 1;
	// 		}else{
	// 			a[i] = primes[n - c];
	// 		}
	// 	}
	// 	// for(int i = 0; i < n; i++){
	// 	// 	cout<<a[i]<<" ";
	// 	// }
	// 	// cout<<"\n";
	// 	long long m = 0;
	// 	// cout<<m<<"\n";
	// 	for(int i = 1; i < n; i++){
	// 		b[i] = a[i] * a[i - 1];
	// 		m = max(m, a[i] * a[i - 1]);
	// 	}
	// 	b[0] = a[0] * a[n - 1];
	// 	m = max(m, a[0] * a[n - 1]);
	// 	// for(int i = 0; i < n; i++){
	// 	// 	cout<<b[i]<<" ";
	// 	// }
	// 	// cout<<"\n";
	// 	// cout<<m<<"\n";
	// 	if(m > 1e9)cout<<-1<<"\n";
	// 	else{
	// 		for(int i = 0; i < n; i++){
	// 			cout<<b[i]<<" ";
	// 		}
	// 		cout<<"\n";
	// 	}
	// 	// if(n >= 3403) cout<<-1<<"\n";
	// 	// else{
	// 	// 	for(int i = 1; i < n; i++){
	// 	// 		long long x = primes[i] * primes[i - 1];
	// 	// 		cout<<x<<" ";
	// 	// 	}
	// 	// 	long long x = primes[0] * primes[n - 1];
	// 	// 	cout<<x<<"\n";
	// 	// }
	// 	// for(int i = 0; i < n; i++){
	// 	// 	cout<<primes[i]<<" ";
	// 	// }
	// }
	}
}