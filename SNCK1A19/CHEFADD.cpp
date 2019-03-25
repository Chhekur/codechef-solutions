#include<iostream>
using namespace std;
int cal_ones(long a){
	int one = 0;
	while(a != 0){
		if(a & 1) one++;
		a >>= 1;
	}
	return one;
}

int main(void){
	long po[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
	int t;cin>>t;
	while(t--){
		long a,b,c;cin>>a>>b>>c;
		long na = cal_ones(a);
		long nb = cal_ones(b);
		long nc = cal_ones(c);
		long count = 0;
		for(long i = po[min(na,nb)] -1; i <= (c - po[min(na,nb)]) + 1; i++){
			long x = cal_ones(i);
			long y = cal_ones(c - i);
			if(x == na && y == nb && (i + (c - i)) == c)count ++;
		}
		cout<<count<<"\n";
		// cout<<cal_ones(a)<<" "<<cal_ones(b)<<" "<<cal_ones(c)<<"\n";
	}
}
