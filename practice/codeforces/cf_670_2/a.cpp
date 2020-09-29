#include <bits/stdc++.h>
//#define int long long

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
		int n; cin >> n;
		vector<int> v(101, 0);
		vector<int> in(n);
		for(int i = 0; i < n; i++){
			int t; cin >> t;
			v[t]++;
			in[i] = t;
		}
		

		int ans = 0;
		if(n&1){
			for(int i = 0 ; i < 101; i++){
				if(v[i] == 0){ ans = i; break;}
			}
			cout << ans << "\n";
			continue;
		}

		else{
			set<int> s;
			for(int i = 0; i < n; i++) s.insert(in[i]);
			debug(v);
			for(int i = 0 ; i < 101; i++){
    		if(v[i] == 0){ ans += i; break;}
			}

			if((int) s.size() > n/2) ans = min(ans, n/2);
			
			int c = 0;
			for(int i :  s) {
				if(c < n/2){
					v[i]--; c++;
				}
			}
			debug(ans, v)	;
			for(int i = 0 ; i < 101; i++){
				if(v[i] == 0){ ans += i; break;}
			}

			cout << ans << "\n";
		}
	}




	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
