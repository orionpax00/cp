#include <bits/stdc++.h>
using namespace std;

#include "../graph.h"
#include "../digraph.h"
#include "../dfs_digraph.h"
#include "../explore_digraph.h"
#include "../debug.h"

void solve(){
	int n, m; cin >> n >> m;
	explore_digraph<int> g(n);
	for(int i = 0; i < m; i++){
		int a, b, c; cin >> a >> b >> c;
		g.add(--a, --b, c);
	}

	vector<int> topo_order = g.toposort();
	debug(topo_order);
	debug(g.g);
	int s;	cin >> s;
	vector<int> ans(n, INT_MAX); ans[--s] = 0; 
	if(topo_order.size() == 0) cout << "Topo Sort Doesn't exist\n";

	for(int i = 0; i < n; i++){
		int to = topo_order[i];
		if(ans[to] != INT_MAX){
			for(auto x :  g.g[i]){
				int from = g.edges[x].from ^ g.edges[x].to ^ to;
				int cost = g.edges[x].cost;
				if(ans[from] > ans[to] + cost)
					ans[from] = ans[to] + cost;
			}
		}
	}	
	
	debug(ans);

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
