#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
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
//void __print(graph::edge x) {cerr << "{" << x.from << "," << x.to << "," << x.cost <<"}";}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


void solve(){
    int r, c; cin >> r >> c;
    vector<vector<int>> g(r, vector<int>(c,0));
    vector<vector<int>> vis(r, vector<int>(c,0));
    vector<vector<int>> dist(r, vector<int>(c,0));
    
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> g[i][j];
        }
    }
    
    int x, y; cin >> x >> y;
   	debug(g); 
	auto issafe = [&](int x, int y){
    	return x >= 0 && y >= 0 && x < r && y < c && g[x][y] == 1;
    };
    
    pair<int, int> dirs[4] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
    queue<pair<int, int>> q;
    q.push({0,0});
    vis[0][0] = 1;
    while(!q.empty()){
    	pair<int, int> v = q.front();
    	q.pop();
    	int cx = v.first;
    	int cy = v.second;
    	for(pair<int, int> dir: dirs){
    		int dx = dir.first;
    		int dy = dir.second;
    		if(issafe(cx + dx, cy + dy) && !vis[cx + dx][cy + dy]){ 
    			q.push({cx + dx, cy + dy});
    			vis[cx + dx][cy + dy] = 1;
    			dist[cx + dx][cy + dy] = dist[cx][cy] + 1;
    		}
    	}
    }
    cout <<  (vis[x][y] ? dist[x][y] : -1) << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tt; cin >> tt;
	while(tt--) solve();


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
