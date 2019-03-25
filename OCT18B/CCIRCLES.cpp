#include<iostream>
#include<cmath>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

class circle{
	public:
		int x;
		int y;
		int r;
};

double * cal_distance(circle a, circle b){
	double d = sqrt((double)((b.x - a.x)*(b.x - a.x)) + ((b.y - a.y)*(b.y - a.y)));
	// cout<<d<<" ";
	double *dist = new double[2];
	if(d >= a.r + b.r){
		dist[0] = d - a.r - b.r;
		dist[1] = d + a.r + b.r;
		// cout<<dist[0]<<" "<<dist[1]<<"\n";
	}else{
		dist[0] = (max(a.r,b.r) - (d + min(a.r,b.r)));
		dist[1] = d + a.r + b.r;
		if(dist[0] < 0) dist[0] = 0;
		// cout<<dist[0]<<" "<<dist[1]<<"\n";
			// }else if(d + min(a.r,b.r) == max(a.r,b.r)){
		// 	dist[0] = 0;
		// 	dist[1] = d + a.r + b.r;
		// else{
		// 	dist[0] = 0;
		// 	dist[1] = d + a.r + b.r;
		// }
	}
	return dist;
}

int main(void){
	int n,q;cin>>n>>q;
	vector<pair<int, int> > ranges;
	circle circles[n];
	for(int i = 0; i < n; i++){
		cin>>circles[i].x;
		cin>>circles[i].y;
		cin>>circles[i].r;
	}
	for(int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			double *distances = cal_distance(circles[i],circles[j]);
			// cout<<distances[0]<<" "<<distances[1]<<"\n";
			ranges.push_back(make_pair(ceil(distances[0]),floor(distances[1])));
		}
	}
	// for(int i = 0; i < ranges.size(); i++){
	// 	cout<<ranges[i].first<<" "<<ranges[i].second<<"\n";
	// }
	// cout<<"\n";
	while(q--){
		int d;cin>>d;
		int count = 0;
		for(int i = 0; i < ranges.size(); i++){
			if(d >= ranges[i].first && d <= ranges[i].second) count ++;
		}
		cout<<count<<"\n";
	}
}

