#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<set>
#include<stack>
using namespace std;

vector<pair<int, int> > edges;
vector<pair<int, int> > graph;
vector<vector<int> > temp_graph;
int a[1001];
bool isPrime(int num){
	int f = 0;
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0) f = 1;
	}
	if(!f)return true;
	else return false;
}


// void genTree(int n){
// 	edges.clear();
// 	graph.clear();
// 	set< pair<int,int> >::iterator it;
// 	while(edges.size() < n - 1){
// 		int x = ( rand() % ( n ) );
// 		int y = ( rand() % ( n ) );
// 		// cout<<x<<" "<<y<<"\n";
// 		// break;
// 		int f = 0;
// 		for(it=edges.begin(); it!=edges.end(); ++it){
// 			if(it->first == y && it->second == x)f = 1;
// 		}
// 		if(x == y) f = 1;
// 		if(!f) edges.insert(make_pair(x , y));
// 		// i++;
// 	}
	
// 	for(it=edges.begin(); it!=edges.end(); ++it){
// 		graph.push_back(make_pair(it->first + 1, it->second + 1));
// 		// cout<<it->first<<" "<<it->second<<"\n";
// 	}
// }

void print_edges(){
	for(int i = 0; i < edges.size(); i++){
		cout<<edges[i].first + 1<<" "<<edges[i].second + 1<<"\n";
	}
}


int main(void){
	int n;cin>>n;
	vector<int> prime_index;
	vector<int> numbers;
	int index = -1;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		// if(a[i] == 2) index = i + 1;
		// int f = 0;
		// for(int j = 2; j * j <= a[i]; j++){
		// 	if(a[i] % j == 0) f = 1;
		// }
		// if(!f)prime_index.push_back(i + 1);
		// else numbers.push_back(i + 1);
	}
	// if(n == 2) cout<<"1 2\n";
	// else{
		for(int i = 0; i < n; i++){
			if(a[i] != 0){
				for(int j = i + 1; j < n; j++){
					if(a[j] != 0){
						if(isPrime(a[i] + a[j])){
							edges.push_back(make_pair(i,j));
							a[i] = 0;
							a[j] = 0;
							break;
						}
					}
				}
			}
		}
		// print_edges();
		if(edges.size() == 0){
			int f = 0, ind;
			for(int i = 0; i < n; i++){
				if(isPrime(a[i])) {
					f = 1;
					ind = i;
					break;
				}
			}
			if(f){
				for(int i = 0; i < n; i++){
					if(ind + 1 == i + 1) continue;
					cout<<ind + 1<<" "<<i + 1<<"\n";
				}
			}else{
				for(int i = 0; i < n - 1; i++){
					edges.push_back(make_pair(i,i + 1));
				}
				print_edges();
			}
		}
		else{
			vector <int> temp;
			for(int i = 0; i < n; i++){
				if(a[i] == 0) continue;
				// cout<<a[i]<<" "<<i<<"\n";
				temp.push_back(i);
			}
			int size = edges.size();
			if(temp.size() > 0){
				for(int j = 0; j < size; j++){
					if(j % 2 == 0)
					// cout<<temp[j]<<" ";
					edges.push_back(make_pair(temp[temp.size()/2],edges[j].first));
					else
						edges.push_back(make_pair(temp[temp.size() / 2],edges[j].second));
				}
				for(int j = 0; j < temp.size() - 1; j++){
					edges.push_back(make_pair(temp[j],temp[j + 1]));
				}
			}
			else{
				int size = edges.size();
				for(int i = 0; i < size - 1; i++){
					edges.push_back(make_pair(edges[i].first, edges[i + 1].second));
				}
			}
			print_edges();
		}
	// }


	// int z = 10;
	// int tree_count = 0;
	// vector<pair<int, int> > ans;
	// while(z--){
	// 	genTree(n);
	// 	int count = 0;
	// 	for(int i = 0; i < graph.size(); i++){
	// 		// cout<<graph[i].first<<" "<<graph[i].second<<"\n";
	// 		set<int> temp;
	// 		temp.insert(graph[i].second);
	// 		for(int j = 0; j < graph.size(); j++){
	// 			if(i == j)continue;
	// 			temp.insert(graph[j].first);
	// 			temp.insert(graph[j].second);
	// 		}
	// 		set<int>::iterator it;
	// 		long val = 0;
	// 		for(it = temp.begin(); it != temp.end(); it++){
	// 			// cout<<*it<<" ";
	// 			val += *it;
	// 		}
	// 		// cout<<"\n";
	// 		if(isPrime(graph[i].first))count++;
	// 		if(isPrime(val))count++;
	// 	}
	// 	if(count > tree_count){
	// 		// cout<<count<<" "<<tree_count<<"\n";
	// 		tree_count = count;
	// 		ans = graph;
	// 	}
	// }
	// for(int i = 0; i < ans.size(); i++){
	// 	cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	// }
}
