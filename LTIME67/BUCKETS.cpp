#include<iostream>
using namespace std;
int main(void){
	int n,k;cin>>n>>k;
	int a[n][n];
	int su[n] = {};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			cin>>a[i][j];
			su[i] += a[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		double p;
		for (int j = 0; j < n; j++){
			if(j == 0){
				p = (a[j][i] * 1.0) / (su[j] * 1.0);
				// cout<<p<<" ";
			}else{
				// cout<<a[j][i]<<" "<<su[j]<<"\n";
				double y = p * ((a[j][i]*1.0 + 1) / (su[j] + 1));
				// cout<<y<<" ";
				// cout<<((a[j][i]*1.0) / (su[j] + 1))<<"\n";
				y += (1 - p) * ((a[j][i]*1.0) / (su[j] + 1));
				p = y;
				// cout<<" y "<<y<<" ";
			}
		}
		cout<<p<<" ";
	}
}