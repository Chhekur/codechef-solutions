#include <iostream>
#include <vector>

using namespace std;

struct TrieNode{
    struct TrieNode *TrieNodes[2];
    vector<int> ina;
};

struct TrieNode *create_node(void){
    struct TrieNode *temp = new TrieNode;
    temp->TrieNodes[0]=NULL;temp->TrieNodes[1]=NULL;
    return temp;
}

int find_answer(string st,int a,int b,struct TrieNode *root_node){
    struct TrieNode *temp_root = root_node;
    int current;
    for(int i=0; i < st.length(); i++){
        current = st[i] - '0';
        if(current){
            if(temp_root->TrieNodes[!current] != NULL){
                for(int j = 0;j < temp_root->TrieNodes[!current]->ina.size(); j++){
               if(temp_root->TrieNodes[!current]->ina[j] >= a && temp_root->TrieNodes[!current]->ina[j] <= b){
                   temp_root =temp_root->TrieNodes[!current];
                   break;
               }
               else{
                   if(j == (temp_root->TrieNodes[!current]->ina.size()-1)){
                       temp_root = temp_root->TrieNodes[current];
                       break;
                   }
               }
            }
            }
            else temp_root = temp_root->TrieNodes[current];
        }
        else{
           if(!current){
               if(temp_root->TrieNodes[!current]!=NULL){
                    for(int j = 0; j<temp_root->TrieNodes[!current]->ina.size(); j++){
               if(temp_root->TrieNodes[!current]->ina[j] >= a && temp_root->TrieNodes[!current]->ina[j] <= b){
                   temp_root = temp_root->TrieNodes[!current];
                   break;
               }
               else{
                   if(j == temp_root->TrieNodes[!current]->ina.size()-1){
                       temp_root =temp_root->TrieNodes[current];
                       break;
                   }
               }
            }
               }
               else temp_root = temp_root->TrieNodes[current];
           }
          
        }
    }
    for(int i = 0;i < temp_root->ina.size();i++){
        if(temp_root->ina[i] >= a && temp_root->ina[i] <= b){
            return temp_root->ina[i];
        }
    }
}

void insert_in_trie(struct TrieNode *root_node,string st, int ind){
    struct TrieNode *temp_root = root_node;
    for(int i = 0; i< st.length() ; i++){
        int current = st[i] - '0'; 
        if (!temp_root->TrieNodes[current]) 
            temp_root->TrieNodes[current] = create_node();
        temp_root->TrieNodes[current]->ina.push_back(ind);
        temp_root = temp_root->TrieNodes[current];
    }
}

int main(void)
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int num , query,a,b;
   cin>>num>>query;
   string bstring;
   struct TrieNode *root_node = create_node();
   for(int i = 0;i < num; i++){
		cin>>bstring;
		insert_in_trie(root_node,bstring,i+1);
   }
   for(int i = 0; i < query ; i++){
       cin>>a>>b>>bstring;
      cout<<find_answer(bstring, a, b, root_node)<<"\n";
   }
}
