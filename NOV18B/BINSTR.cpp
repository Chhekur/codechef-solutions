#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
	public:
		TrieNode * TrieNodes[2];
		vector <int> ina;
		TrieNode(){
			TrieNodes[0] = NULL; TrieNodes[1] = NULL;
		}
};

int solve(TrieNode *temp_root, string st, int a,int b, int ind){
	if(ind >= st.length()){
		for(int i = 0; i < temp_root->ina.size(); i++){
			if(temp_root->ina[i] >= a && temp_root->ina[i] <= b){
				return temp_root->ina[i];
			}
		}
	}else if(temp_root->TrieNodes[0] == NULL && temp_root->TrieNodes[1] == NULL){
		for(int i = 0; i < temp_root->ina.size(); i++){
			if(temp_root->ina[i] >= a && temp_root->ina[i] <= b){
				return temp_root->ina[i];
			}
		}
	}
	if(st[ind] == '0'){
		if(temp_root->TrieNodes[1] != NULL){
			int flag = 0;
			for(int i = 0; i < temp_root->TrieNodes[1]->ina.size(); i++){
				if(temp_root->TrieNodes[1]->ina[i] >= a && temp_root->TrieNodes[1]->ina[i] <= b) {
					flag = 1;
					break;
				}
			}
			if(flag) return solve(temp_root->TrieNodes[1],st,a,b,ind + 1);
			else return solve(temp_root->TrieNodes[st[ind] - '0'], st, a, b, ind + 1);
		}else return solve(temp_root->TrieNodes[st[ind] - '0'], st, a, b, ind + 1);
	}else{
		if(temp_root->TrieNodes[0] != NULL){
			int flag = 0;
			for(int i = 0; i < temp_root->TrieNodes[0]->ina.size(); i++){
				if(temp_root->TrieNodes[0]->ina[i] >= a && temp_root->TrieNodes[0]->ina[i] <= b) {
					flag = 1;
					break;
				}
			}
			if(flag) return solve(temp_root->TrieNodes[0], st, a, b, ind + 1);
			else return solve(temp_root->TrieNodes[st[ind] - '0'], st, a, b, ind + 1);
		}else return solve(temp_root->TrieNodes[st[ind] - '0'], st, a, b, ind + 1);
	}
}
int find_answer(TrieNode *root_node, string st, int a, int b) {
	return solve(root_node, st,a,b,0);
}
void insert_in_trie(TrieNode *root_node, string st, int ind){
	TrieNode * temp_root = root_node;
	for(int i = 0; i < st.length(); i++){
		if(temp_root->TrieNodes[st[i] - '0'] == NULL){
			temp_root->TrieNodes[st[i] - '0'] = new TrieNode();
		}
		temp_root->TrieNodes[st[i] - '0']->ina.push_back(ind);
		temp_root = temp_root->TrieNodes[st[i] - '0'];
	}
}


int main(void){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int num,query;cin>>num>>query;
	string bstring;
	TrieNode * tr = new TrieNode();
	for(int i = 0; i < num; i++){
		cin>>bstring;
		insert_in_trie(tr,bstring, i + 1);
	}
	for(int i = 0; i < query; i++){
		int a,b;
		cin>>a>>b>>bstring;
		cout<<find_answer(tr,bstring,a,b)<<"\n";
	}
}

