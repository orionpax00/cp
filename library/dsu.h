class dsu {
	public:
	vector<int> parent;
	vector<int> rank;

	int n;

	dsu(int _n){
		parent.resize(_n);
		iota(parent.begin(), parent.end(), 0);
		rank.resize(_n);
	}

	inline int find(int x){
		return (x == parent[x] ? x : (parent[x] = find(parent[x])));
	}

	void unite(int a, int b){
		a = find(a); b = find(b);

		if(a != b){
			if(rank[a] < rank[b]) swap(a,b);
			parent[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}
}
