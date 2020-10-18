class Trie{
public:
	struct Node {
		Node *children[26];
		bool isEnd;
	};

	Node* root;


	Node *getNode(){
		Node *pNode = new Node;
		pNode->isEnd = false;

		for(int i = 0; i < 26; i++) pNode->children[i] = NULL;

		return pNode;
	}

	Trie() {
		root = getNode();
	}
	void insert(string s){
		Node* pC = root;
		for(int i = 0; i < (int)s.length(); i++){
			int idx = s[i] - 'a';
			if(!pC->children[idx]) pC->children[idx] = getNode();

			pC = pC->children[idx];
		}
		pC->isEnd = true;
	}

	bool search(string s){
		Node *pC = root;
		for(int i = 0; i < (int)s.length(); i++){
			int idx = s[i] - 'a';
			if(!pC->children[idx]) return false;
			pC = pC->children[idx];
		}
		return (pC != NULL && pC->isEnd);
	}

	bool isEmpty(Node* root){
		for(int i =0; i < 26; i++)
			if(root->children[i]) return false;
		return true;
	}	

	Node *remove(Node *root, string s, int depth = 0){
		if(!root) return NULL;
		
		if(depth == (int)s.length()){
			if(root->isEnd) root->isEnd = false;
			if(isEmpty(root)){ delete (root); root = NULL;}

			return root;
		}

		int idx = s[depth] - 'a';
		root->children[idx] = remove(root->children[idx], s, depth + 1);

		if(isEmpty(root) && root->isEnd == false){ delete (root); root = NULL;}

		return root;
	}


	vector<string> prefixResults;
	void prefSearchRec(Node* root, string q){
		if(root->isEnd) prefixResults.push_back(q);

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
