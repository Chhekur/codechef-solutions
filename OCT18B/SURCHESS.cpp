#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define bac(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 10000000000000
#define MOD 1000000007
#define N 205
ll i,j,k,l,n,q,m,d,su,sx,sy,prod=1,ans,maxi,a,b,x,y,o,e,f,mini=INF,t,cnt;
string s;
vpii v,v2;
char ch;
ll ar[N][N],br[N][N][N];
ll zc[N][N],zr[N][N];
bool comp(pair<ll,ll> &v1, pair<ll,ll> &v2 )
{
	if(v1.F==v2.F)
	return v1.S>v2.S;
	else
	return v1.F<v2.F;
}
void zerosum()
{
	ll b=0,x;
	rep(i,0,m)
	{if(ar[0][i]!=b)zc[0][i]=1;
	b=1-b;}
	// for(int i = 0; i < m; i++){
	// 	cout<<zc[0][i];
	// }
	// cout<<"\n";
	x=b=1;
	rep(j,0,m){
		b=x;
	rep(i,1,n)
	{
		if(ar[i][j]!=b) zc[i][j]=(zc[i-1][j]+1);
		else zc[i][j]=zc[i-1][j];
		b=1-b;
		// cout<<zc[i][j];
	}
		// cout<<"\n";
	x=1-x;	
	}
	
	
	b=0;
	rep(i,0,n)
	{if(ar[i][0]!=b)zr[i][0]=1;
	b=1-b;}
	x=b=1;
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cout<<zr[i][j];
	// 	}cout<<"\n";
	// }cout<<"\n";
	
	rep(i,0,n){
		b=x;
	rep(j,1,m)
	{
		if(ar[i][j]!=b) zr[i][j]=(zr[i][j-1]+1);
		else zr[i][j]=zr[i][j-1];
		b=1-b;
		// cout<<b<<"\n";
		// cout<<zr[i][j];
	}
		// cout<<"\n";
	x=1-x;	
	}
	
}
ll sumr(ll l, ll r, ll k)
{
	ll sum=0;
	// cout<<r-1<<"\n";
	// cout<<zr[l+k-1][r-1]<<"\n";
	sum+=zr[l+k-1][r+k-1]-zr[l+k-1][r-1];
	sum+=zc[l+k-1][r+k-1]-zc[l-1][r+k-1];
	sum-=(zc[l+k-1][r+k-1]-zc[l+k-2][r+k-1]);
	// cout<<sum<<"\n";
	return sum;
}
int main()
{
    
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
        cin>>n>>m;
        rep(i,0,n)rep(j,0,m){cin>>ch;ar[i][j]=ch-'0';}
        x=b=0;
		rep(j,0,m){
			b=x;
		rep(i,0,n)
		{
			if(ar[i][j]!=b) br[i][j][1]=1;
		b=1-b;
		}
		x=1-x;	
	}
	zerosum();
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++){
		// 		cout<<zr[i][j];
		// 	// }cout<<"\n";
		// }
		// // cout<<"\n";
		// for(int i = 0; i < n; i++){
		// 	for(int j = 0; j < m; j++){
		// 		cout<<zc[i][j];
		// 	}cout<<"\n";
		// }
        rep(i,0,n)
        rep(j,0,m)
        rep(k,2,min(n-i+1,m-j+1))
        	br[i][j][k]=br[i][j][k-1]+sumr(i,j,k);
			// cout<<i<<" "<<j<<" "<<k<<"\n";
		// for(int i = 0; i <n; i++){
		// 	for(int j = 0; j < m; j++){
		// 		for(int k = 0; k < n; k++){
		// 			cout<<br[i][j][k];
		// 		}
		// 		cout<<"\n";
		// 	}
		// 	cout<<"\n";
		// }
        
        	        
        rep(i,0,n)rep(j,0,m)rep(k,1,min(n-i+1,m-j+1)){v.pb({br[i][j][k],k});v.pb({k*k-br[i][j][k],k});}
        sort(all(v),comp);
        v2.pb(v[0]);
        ll x=v[0].F,y=v[0].S;
        rep(i,1,v.size())
        {
        	if(x!=v[i].F and v[i].S>y)
        	{
        		v2.pb(v[i]);
        		x=v[i].F;y=v[i].S;
        	}
        }
        // rep(i,0,v2.size())cout<<v2[i].F<<" "<<v2[i].S<<endl;
        cin>>q;
        rep(i,0,q)
        {
        	cin>>x;
        	ll lo=0,hi=v2.size();
        	while(hi>lo)
        	{
        		ll mid=(hi+lo)/2;
        		if(v2[mid].F>x)hi=mid;
        		else lo=mid+1;
        	}
        	
        	if(lo>v2.size())
        	cout<<min(n,m)<<endl;
        	else
        	cout<<v2[lo-1].S<<endl;
        }
        
    }
    
    return 0;
}

