#include <bits/stdc++.h>
using namespace std;


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
};


vector<vector<int>> g;
vector<int> par;
vector<int> goal;

void solve(){
	goal.clear();par.clear();
	int n, m; cin >> n >> m;
	goal.resize(n); par.resize(n);

	for(int i = 1 ; i <= n; i++){int t; cin >> t; par[i] = t;}
	for(int i = 1 ; i <= n; i++){
		int t; cin >> t;
		goal[t] = i;
	}

	dsu d(n + 1);

	for(int i = 0; i < m; i++){
		int a, b; 
		cin >> a >> b;
		d.unite(a, b);
	}
	bool ok = true;
	for(int i = 1; i <= m; i++){
		int p = par[i];
		if(d.find(i) != d.find(goal[p]))
			ok = false;
	}

	cout << (ok ? "YES\n" : "NO\n");

}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt = 1; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
