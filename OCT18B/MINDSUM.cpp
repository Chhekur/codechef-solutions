#include<iostream>
using namespace std;

long long * func2(long long x, long long d){
	long long count = 0, sum = 0;
	if(x > 9){
		count ++;
		while(x != 0){
			sum += x % 10;
			x /= 10;
		}
	}
	long long b = sum + d;
	long long count2 = 0, sum2 = 0;
	if(b > 9){
		do{
			sum2 = 0;
			count2 ++;
			while(b != 0){
				sum2 += b % 10;
				b /= 10;
			}
			b = sum2;
		}while(b > 9);
	}
	if(b == 1){
		sum = sum2;
		count += count2 + 1;
		// cout<<"count "<<count<<" ";
	}
	long long *a = new long long[2];
	a[0] = sum;a[1] = count;
	if(a[0] == 0) {
		a[0] = x;
		a[1] = 0;
	}
	return a;
}

long long * func(long long x, long long d){
	long long count = 0,sum = 0;bool flag = 0;
	if(x > 9){
		// do{
		// 	count ++;
		// 	sum = 0;
		// 	while(x != 0){
		// 		sum += x % 10;
		// 		x /= 10;
		// 	}
		// 	x = sum;
		// }while(sum > 9);
		count ++;
		while(x != 0){
			sum += x % 10;
			x /= 10;
		}
		// long long b = sum + d;
		// long long count2 = 0, sum2 = 0;
		// if(b > 9){
		// 	do{
		// 		sum2 = 0;
		// 		count2 ++;
		// 		while(b != 0){
		// 			sum2 += b % 10;
		// 			b /= 10;
		// 		}
		// 		b = sum2;
		// 	}while(b > 9);
		// }
		// if(b == 1){
		// 	sum = sum2;
		// 	count += count2 + 1;
		// 	// cout<<"count "<<count<<" ";
		// }
		if(sum > 9){
			// count ++;
			long long *temp = func(sum,d);
			sum = temp[0];
			// count = min(count, count + temp[1]);
			count += temp[1];
			// cout<<"final count "<<count<<"\n";
		}
	}else{
		sum = x;
		count = 0;
	}
	long long *a = new long long[2];
	a[0] = sum;
	a[1] = count;
	return a;
}

long long * func3(long long x, long long d){
	long long count = 0,sum = 0;bool flag = 0;
	if(x > 9){
		// do{
		// 	count ++;
		// 	sum = 0;
		// 	while(x != 0){
		// 		sum += x % 10;
		// 		x /= 10;
		// 	}
		// 	x = sum;
		// }while(sum > 9);
		count ++;
		while(x != 0){
			sum += x % 10;
			x /= 10;
		}
		// long long b = sum + d;
		// long long count2 = 0, sum2 = 0;
		// if(b > 9){
		// 	do{
		// 		sum2 = 0;
		// 		count2 ++;
		// 		while(b != 0){
		// 			sum2 += b % 10;
		// 			b /= 10;
		// 		}
		// 		b = sum2;
		// 	}while(b > 9);
		// }
		// if(b == 1){
		// 	sum = sum2;
		// 	count += count2 + 1;
		// 	// cout<<"count "<<count<<" ";
		// }
		if(sum > 9){
			count ++;
			long long *temp = func(sum,d);
			sum = temp[0];
			// count = min(count, count + temp[1]);
			// count += temp[1];
			// cout<<"final count "<<count<<"\n";
		}
	}else{
		sum = x;
		count = 0;
	}
	long long *a = new long long[2];
	a[0] = sum;
	a[1] = count;
	return a;
}

int main(void){
	int t;cin>>t;
	while(t--){
		// map <long long , bool> m;
		long long n,d;cin>>n>>d;
		// cout<<func(n,d)[0]<<" "<<func(n,d)[1]<<"\n";
		long long *temp = func(n,d);
		long h = temp[0];
		// m[temp[0]] = 1;
		long long ans = temp[0];
		long long step = temp[1];
		// long long step = 0;
		long i = 1;
		// if(n == 95 && d == 83)cout<<"1 9\n";
		// else{
			while(true){
				long long a = n + (i * d);
				// cout<<"a "<<a<<" ";
				temp = func(a,d);
				if(temp[0] < ans){
					ans = temp[0];
					step = temp[1] + i;
					// cout<<"step"<<step<<" ";
				}
				if(temp[0] == ans) step = min(step, temp[1] + i);
				// cout<<temp[0]<<" "<<temp[1]<<" "<<i<<"\n";
				if(temp [0] == 1 || temp[0] == h)break;
				// if(temp[0] == h)break;
				i ++;
				// break;
			}
		long long ans1 = ans;
		long long step1 = step;
		// cout<<"first"<<ans<<" "<<step<<"\n";
		i = 1;
		while(i < 100000){
				long long a = n + (i * d);
				// cout<<"a "<<a<<" ";
				temp = func2(a,d);
				if(temp[0] < ans){
					ans = temp[0];
					step = temp[1] + i;
					// cout<<"step"<<step<<" ";
				}
				if(temp[0] == ans) step = min(step, temp[1] + i);
				// cout<<temp[0]<<" "<<temp[1]<<" "<<i<<"\n";
				if(temp [0] == 1 || temp[0] == h)break;
				// if(temp[0] == h)break;
				i ++;
				// break;
			}
		long long ans2 = ans;
		long long step2 = step;
		i = 1;
		while(i < 100000){
				long long a = n + (i * d);
				// cout<<"a "<<a<<" ";
				temp = func3(a,d);
				if(temp[0] < ans){
					ans = temp[0];
					step = temp[1] + i;
					// cout<<"step"<<step<<" ";
				}
				if(temp[0] == ans) step = min(step, temp[1] + i);
				// cout<<temp[0]<<" "<<temp[1]<<" "<<i<<"\n";
				if(temp [0] == 1 || temp[0] == h)break;
				// if(temp[0] == h)break;
				i ++;
				// break;
			}
			// cout<<func2(n,d)[0]<<" "<<func2(n,d)[1]<<"\n";
			// cout<<"second"<<ans<<" "<<step<<"\n";
			if(ans1 == ans && ans1 == ans2){
				cout<<ans<<" "<< min(step1,min(step2,step))<<"\n";
			}else{
				cout<<min(ans1,ans2)<<" "<<min(step2,step1)<<"\n";
			}
			// cout<<ans<<" "<<step<<"\n";
		// }
	}
}



