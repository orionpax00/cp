#include <bits/stdc++.h>
//#define int long long

using namespace std;


class segtree {
	public:
	struct node {
		int a = 0; //example int a = 0; or vector<int> a;
		
		void apply(int l , int r, int v){ // v would be something like v = 5 in add apply
			a = v; //cerr << "\n---\n" << r  << l << "\n--\n";	
		}	
	};

	node unite(const node &a, const node &b) const{
		node res;
		
		res.a = min(a.a, b.a);

		return res;
	}

	inline void pull(int x, int z){
		tree[x] = unite(tree[x+1], tree[z]);
	}
	
//	inline void push(int x, int l, int r){ //this function is useful in lazy propogation as node is a struct so no need to store another tree just use another variable in the node struct
//		int y = (l+r) >> 1;
//		int z = x + ((y - l + 1) << 1);

//		if (tree[x].add !=0){
//			tree[x+1].apply(l, y, tree[x].add);
//			tree[z].apply(y+1, r, tree[x].add);
//			tree[x].add = 0;
//		}
//	}

	int n; vector<node> tree;
	void build(int x, int l, int r){
		if(l == r) { return;}
		int y = (l+r) >> 1;
		int z = x + ((y - l + 1) << 1);
		build(x+1, l, y);
		build(z, y+1, r);
		pull(x,z);
	}

	template<typename M>	
	void build(int x, int l, int r, const vector<M> &v){
		if(l == r) { 
			tree[x].apply(l, r, v[l]);
			return;
		}
		int y = (l+r) >> 1;
		int z = x + ((y - l + 1) << 1);
		build(x+1, l, y, v);
		build(z, y+1, r, v);
		pull(x,z);
	}	
	
	node get(int x, int l, int r, int ll, int rr){
		if(ll <= l && r <= rr){
			return tree[x];
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
//		push(x, l, r);
		node res{};	
		if(rr <= y){
			res = get(x+1, l, y, ll, rr);
		}else{
			if(ll > y){
				res = get(z, y+1, r, ll, rr);
			}else{
				res = unite(get(x+1, l, y, ll, rr), get(z, y+1, r, ll, rr));
			}
		}
//		pull(x,z);
		return res;	
	}
	
	template<typename... M>
	void mod(int x, int l, int r, int ll, int rr, const M&... v){
		if(ll <= l && r <= rr){
			tree[x].apply(l, r, v...);
			return;
		}
		int y = (l + r) >> 1;
		int z = x + ((y - l + 1) << 1);
//		push(x, l, r);
		if(ll <= y){
			mod(x+1, l, y , ll, rr, v...);
		}
		if(rr > y){
			mod(z, y + 1, r, ll, rr, v...);
		}
		pull(x, z);
	} 	

	segtree(int _n) : n(_n){
		assert(n > 0);
		tree.resize(2*n -1);
		build(0, 0, n-1);
	}
	
	template<typename M>
	segtree(const vector<M> &v){
		n = v.size();
		assert(n > 0);
		tree.resize(2 * n - 1);
		build(0, 0, n - 1, v);
	}

	node get(int ll, int rr){
		assert(0 <= ll && ll <= rr && rr <= n-1);
		return get(0, 0, n-1, ll, rr);
	}

	node get(int p){
		assert(0 <= p && p <= n-1);
		return get(0, 0, n - 1, p, p);
	}

	template<typename... M>
	void mod(int ll, int rr, const M&... v) {
		assert(0 <= ll && ll <= rr && rr <= n-1);
		mod(0, 0, n-1, ll, rr, v...);
	}	
};



void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  int n, q; cin >> n >> q;
	vector<int> v(n);
	for(int& x: v) cin >> x;

	segtree stree(v);
//	for(auto& x : stree.tree) cerr << x.a << " " ;
  for(int i = 0; i < q; i++){
	  char t; int x, y; cin >> t >> x >> y; x--; y--;
		if(t == 'u'){
			stree.mod(x, x , y);
		}else{
			auto ans = stree.get(x, y);
			cout << ans.a << "\n";
		}
	}


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
