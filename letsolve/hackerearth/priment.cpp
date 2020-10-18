#include <bits/stdc++.h>
using namespace std;

int INF = 1e6+5;

//Sieve of erotosthenes
vector<int> sie(vector<int>& v){
	v[0] = 1;
	v[1] = 1;
	for(int i = 2; i*i <= INF; i++){
		if(!v[i]){
			for(int j = i*i ; j <= INF ; j+=i){
				v[j] = 1;
			}
		}
	}
	
	vector<int> ans;
	for(int i =2; i <= INF; i++){
		if(!v[i]) ans.push_back(i);
	}

	return ans;
}


vector<int> primes_idx(INF + 1);
vector<int> primes = sie(primes_idx);

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
	int n; cin >> n;	
	int N = primes.size();
	map<int, int> m;
	if(!primes_idx[n]) { cout << 1 << "\n"; return;}
	for(int i = 0; i < N; ){
		while(n > 1 && n%primes[i] == 0){
				m[primes[i]]++;
				n /= primes[i];	
		}
		i++;
	}

	int s_ = 0;
	long long ans = 1;
	
	for(auto x: m){
		ans *= (x.second + 1);
		s_++;
	}
	debug(m);
	cout << ans - s_ <<"\n";
	
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
