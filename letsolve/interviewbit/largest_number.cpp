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

bool cmp(string& a, string& b){
	string t1 = a; t1 += a.back();
 	string t2 =	b; t2 += b.back();
	return t1 > t2;
}

int solve(vector<int> & v){
	int n = v.size();
	vector<string> vs(n);
	for(int i = 0; i < n; i++){
		vs[i] = to_string(v[i]);
	}

	sort(vs.begin(), vs.end(), cmp);
	
	debug(v, vs);
	return 0;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    
	int n; cin >> n;
	vector<int> v(n);

	for(int& x: v) cin >> x;

	cout << solve(v);



	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
