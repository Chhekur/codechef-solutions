#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

int chartoint(char a){
	if(a >= 'a' && a <= 'z'){
		return (a - 'a' + 1);
	}else if(a >= 'A' && a <= 'Z'){
		return (a - 'A' + 27);
	}
}


bool compare(pair<string,int> a, pair<string, int> b){
	return a.second > b.second;
}

int main(void){
	int n,m,a,x,r;
	cin>>n>>m>>a>>x>>r;
	string s;cin>>s;
	vector <pair<string, int> > mo, ao;
	vector <pair<int, pair<int, string> > > po;
	for(int i = 0; i < m; i++){
		string x;cin>>x;
		int y;cin>>y;
		mo.push_back(make_pair(x,y));
	}
	for(int i = 0; i < a; i++){
		string x;cin>>x;
		int y;cin>>y;
		ao.push_back(make_pair(x,y));
	}
	sort(mo.begin(), mo.end(), compare);
	// for(int i = 0; i < mo.size(); i++){
	// 	cout<<mo[i].first<<" "<<mo[i].second<<"\n";
	// }
	// if(n + n < 1000000){
	// 	s += s;
	// 	x -= r;
	// 	po.push_back(make_pair(3, make_pair(j + 1, mo[i].first)));
	// }
	// cout<<s<<"\n";
	int count = 0;
	for(int i = 0; i < mo.size(); i++){
		if(mo[i].first.length() == 1){
			// cout<<"Hello\n";
			char c = mo[i].first[0];
			for(int j = 0; j < s.length(); j++){
				if(s[j] != c && s[j] != '#'){
					// cout<<abs(chartoint(s[j]) - chartoint(c))<<"\n";
					if((abs(chartoint(s[j]) - chartoint(c)) <= (x - r)) && (count < 100000)){
						x -= abs(chartoint(s[j]) - chartoint(c));
						count ++;
						s[j] = '#';
						po.push_back(make_pair(1, make_pair(j + 1, mo[i].first)));
					}
				}
			}
		}
	}
	if(n + n <= 1000000){
		count ++;
	}
	cout<<count<<"\n";
	for(int i = 0; i < po.size(); i++){
		cout<<po[i].first<<" "<<po[i].second.first<<" "<<po[i].second.second<<"\n";
	}
	if(n + n <= 1000000){
		x -= r;
		cout<<"3 1 "<<n<<"\n";
	}
}