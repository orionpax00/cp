#include <bits/stdc++.h>

using namespace std;



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

  int tt; cin >> tt;
 	while(tt--){
		bool ok = true;
		int n, k; cin >> n >> k;
		if(k&1) ok = false;
		string s; cin >> s;
		vector<vector<int>> v(n+1, vector<int>(3));
		//0 1 ?
		/*
		if(s[0] == '0') v[0][0]++;
		else if(s[0] == '1') v[0][1]++;
		else v[0][2]++;
		*/
//		map<pair<int, int> , pair<int, int>> qs;

		for(int i = 1 ; i <= n ; i++){
			if(s[i -1] == '0') v[i] = v[i-1], v[i][0]++;
			else if(s[i -1] == '1') v[i] = v[i-1], v[i][1]++;
			else v[i] = v[i-1], v[i][2]++;
		}	

		// check for k	
		
		
		vector<pair<int,int>> qk(k);

		for(int i = k; i <= n; i++){
			int t0 = v[i][0] - v[i-k][0];
			int t1 = v[i][1] - v[i-k][1];
//			int tq = v[i][2] - v[i-k][2];
			if(t0 > k/2 || t1 > k/2) ok = false;
			qk[i%k].first = k/2 - t0;
			qk[i%k].second = k/2 - t1;
			if(i%k == 0){
				for(int j = 1; j < k ; j++){
					if(qk[j - 1].first != qk[j].first || qk[j - 1].second != qk[j].second) ok = false;
				}
			}
		}
		
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}

	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
