#include<iostream>
#define MOD 1000000007

using namespace std;

long long bc[1001][1001];

void chek(){
	
	bc[0][0] = 1;
	for (int i = 1; i < 1001; i++) {
        for(int j = 0; j < i + 1; j++){
			bc[i][j] = (bc[i - 1][j - 1] + bc[i - 1][j]) % MOD;
			if(i == j || i == 0) bc[i][j] = 1;
		}
    }
}

int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	chek();
	int test;cin>>test;
	while(test--){
		int num;cin>>num;
		int a[num];
		int f[2001] = {};
		for(int i = 0; i < num; i++){
			cin>>a[i];f[a[i]]++;
		}
		for(int i = 1; i < 2 * num + 1; i++){
			f[i] = f[i - 1] + f[i];
		}
		long long final_res = num;
		for(int i = 0; i < 2 * num + 1; i++){
			for(int j = 0; j < (f[i] - f[i - 1]) - 1; j++){
				for(int k = 0; k < (f[i] - f[i - 1]) - 1 - j; k++){
					final_res = (final_res + bc[(num - f[i]) + j + f[i - 1] + k][(num - f[i]) + j]) % MOD;
				}
			}
		}
		for(int i = 3; i < num + 1; i += 2){
			final_res = (final_res + bc[num][i]) % MOD;
		}
		cout<<final_res % MOD<<"\n";
	}
}
