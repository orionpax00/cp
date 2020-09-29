#include "bits/stdc++.h"

using namespace std;

class Trie{
public:
	struct Node {
		Node* children[26];
		bool isEnd; 
	};

	Node* root;

	Node* getNode(){
		Node* pNode = new Node;
		pNode->isEnd = false;
		for(int i = 0 ; i < 26; i++) pNode->children[i] == NULL;
		return pNode;
	}

	Trie(){
		root=getNode();
	}

	void insert(string s){
		Node* pC = root;
		int n = s.length();
		for(int i = 0; i < n; i++){
			int idx = s[i] - 'a';
			if(!pC->children[idx]) pC->children[idx] = getNode();
			pC = pC->children[idx];
		}

		pC->isEnd = true;
	}

	bool isEmpty(Node* root){
		for(int i =0; i < 26; i++){
			if(root->children[i]) return false;
		}
		return true;
	}

	vector<string> prefixResults;
	void prefSearchRec(Node* root, string q){
		if(root->isEnd) prefSearch.push_back(q);

		if(isEmpty(root)) return;

		for(int i = 0; i < 26; i++){
			if(root->children[i]){
				q.push_back(97+i);
				prefSearchRec(root->children[i], q);
				q.pop_back();
				
			}
		}
	}

	int prefixSearch(string s){
		Node* pC = root;
		int n = s.length();
		for(int i = 0; i < n; i++){
			int idx = s[i] - 'a';
			if(!pC->children[idx]) return 0;
			pC = pC->children[idx];
		}

		bool isWord = (pC->isEnd == true);
		bool isLast = isEmpty(pC);
		if(isWord && isLast) return -1; //complete word is found
		if(!isLast){
			prefSearchRec(pC, s);
			return 1;
		}
		assert(false);
	}
};

map<string, int> m;

int main(){

	Trie t;
	int n, q; cin >> n >> q;
	for(int i =0; i < n; i++){
		string s; cin >> s;
		t.insert(s);
		m[s]++;
	}
	for(int i = 0; i < q; i++){
		string s; cin >> s;
		t.prefSearch.clear();
		int res = t.prefixSearch(s);
		if(res == 1){
			int ans = 0;
			for(string x: t.prefSearch) ans += m[x];
			cout << ans << "\n";
		}else if(res == -1){
			cout << 1 << "\n";
		}else{
			cout << 0 <<"\n";
		}
	}

	return 0;
}
