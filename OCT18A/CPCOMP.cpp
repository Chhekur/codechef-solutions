#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool visited[5001] = {};
// bool comparator(vector <pair<int, int> > &a, vector <pair<int, int> > &b){
// 	return a.first > b.first;
// }

void bfs(vector <vector <int> > g, int s){
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < g[u].size(); i++){
			if(!visited[g[u][i]]){
				q.push(g[u][i]);
				visited[g[u][i]] = 1;
			}
		}
	}
}

int gcd(int a,int b){
	if(a == 0) return b;
	return gcd(b % a, a);
}

vector <pair<int, int> > num;
int main(void){
	int n;cin>>n;
	vector <vector <int> > graph(n + 1);
	for(int i = 0; i < n; i++){
		int t;cin>>t;
		num.push_back(make_pair(t,i));
		// cin>>num[i].first;
		// num[i].second = i;
	}
	sort(num.begin(), num.end());
	// for(int i = 0; i < n; i++){
	// 	cout<<num[i].first<<" "<<num[i].second<<"\n";
	// }
	for(int i = 0; i < n; i++){
		// cout<<"Hello1";
		if(num[i].first == 0) continue;
		bool flag = false;
		for(int j = i + 1; j < n; j++){
			// cout<<"Hello2";
			if(num[j].first == 0) continue;
			// cout<<gcd(num[i].first,num[j].first)<<"\n";
			if(gcd(num[i].first,num[j].first) == 1){
				// cout<<"Hello";
				flag = true;
				// cout<<num[i].second<<" "<<num[j].second<<"\n";
				graph[num[i].second].push_back(num[j].second);
				graph[num[j].second].push_back(num[i].second);
			}
		}
		if(!flag){
			for(int j = i + 1; j < n; j++){
				if(num[j].first % num[i].first == 0){
					num[j].first = 0;
				}
			}
		}
	}
	// for(int i = 0; i < graph.size(); i++){
	// 	cout<<i<<": ";
	// 	for(int j = 0; j < graph[i].size(); j++){
	// 		cout<<graph[i][j] <<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int count = 0;
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			count ++;
			bfs(graph, i);
		}
	}
	cout<<count<<"\n";
}