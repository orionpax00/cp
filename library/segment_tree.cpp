class segtree {
	public:
	struct node {
		... a = ...; //example int a = 0; or vector<int> a;
		
		void apply(int l , int r, ... v){ // v would be something like v = 5 in add apply
			...
		}	
	};

	node unite(const node &a, const node &b) const{
		node res;
		... // apply node merging logic like in sum parent = left child + right child
		return node;
	}

	inline void pull(int x, int z){
		tree[x] = unite(tree[x+1], tree[z]);
	}
	inline void push(int x, int l, int r){ //this function is useful in lazy propogation as node is a struct so no need to store another tree just use another variable in the node struct
		int y = (l+r) >> 1;
		int z = x + ((y - l + 1) << 1);
		...
//		if (tree[x].add !=0){
//			tree[x+1].apply(l, y, tree[x].add);
//			tree[z].apply(y+1, r, tree[x].add);
//			tree[x].add = 0;
//		}
	}

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
}











