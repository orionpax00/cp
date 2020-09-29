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



int solve(vector<int>& p, vector<int>& q){
		int ans = INT_MIN;
			
		sort(p.begin(), p.end());
		sort(q.begin(), q.end());
		int n = p.size();
		int m = q.size();
		/*
		if(n >= m){
			sort(p.begin(), p.end());
			for(int i = 0 ; i < m; i++){
				auto x = lower_bound(p.begin(), p.end());
				ans += abs(*x - q[i]);
				x = -1;
			}
		}else{
			sort(q.begin(), q.end());
			for(int i = 0 ; i < n; i++){
				auto x = lower_bound(p.begin(), p.end());
				ans += abs(*x - p[i]);
				x = -1;
			}
		}
		*/
		if(n > m){
			int min_ = INT_MAX, I = 0;
			for(int i = 0; i + m <= n; i++){
				int t = abs(q[0] - p[i]); 				
				debug(i, t, q, p);
				if(t < min_) { 
					min_ = t; 
					I = i;
				}
			}
			debug(p, q, min_, I, n ,m);
			for(int i = 0; i < m; i++){
				ans = max(ans , abs(p[i + I] - q[i]));
			}
		}
		else{
			int min_ = INT_MAX, I = 0;
			for(int i = 0; i + n <= m; i++){
				if(abs(q[i] - p[0]) < min_) { 
					min_ = abs(q[i] - p[0]); 
					I = i;
				}
			}
			for(int i = 0; i < n; i++){
				ans = max(ans, abs(q[i + I] - p[i]));
			}
		}


		return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p, q; cin >> p >> q;
	vector<int> vp(p), vq(q);

	for(int& x : vp) cin >> x;
	for(int& x : vq) cin >> x;

	cout <<	solve(vp, vq);
		


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
