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
		int a, b; cin >> a >> b;
		g.add(a, b);
	}

	int s;	cin >> s;	
//	g.dijkstra(--s);	
//	g.dfs(--s);
//	debug(g.dist);
//	debug(g.pv);

	//lexographically smallest toposort order
	vector<int> order = g.toposort();
	debug(order);	

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
