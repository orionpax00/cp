#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = 1e9 +7;


//void __print(int x) {cerr << x;}
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

int perm(int n){
	int ans = 1;
	while(n){
		ans *= n;
		ans %= MOD;
		n--;
	}
	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s; cin >> s;
	vector<int> dp(s + 1, 1);
	if(s <= 3) {
		if(s == 3) cout << 1;
		else cout << 0 ;
	}
	else{
		dp[0] = 0; dp[1] = 0; dp[2] = 0;
		for(int i = 4; i <= s; i++){
			for(int j = 3; j <= s; j++){
					if(i - j > j){
						dp[i] += dp[i - j] + dp[j];
						dp[i] %= MOD;
					}
					if(i-j == j) {dp[i] += dp[j]; dp[i]%=MOD;}
			}
		}
		cout << dp[s];
	}



		


	#ifdef LOCAL
	cerr << "\n";
	#endif
	return 0;
}
